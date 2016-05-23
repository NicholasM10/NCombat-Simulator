#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include "ConsoleColor.h"
#include "TroopNames.h"

using namespace std;

     TroopNames troopNames;

	 int main()
	 {

		 default_random_engine randomEngine(time(0));
		 uniform_real_distribution<float> attack(0.0f, 1.0f);

		 // Human properties
		 float humanAttack = 0.6f; // Chance
		 float humanHealth = 250.0f;
		 float humanDamage = 200.0f;
		 float currentHumanHealth = humanHealth;
		 int humansKilled = 0;

		 // Skeleton properties
		 float skeletonAttack = 0.2f;
		 float skeletonHealth = 50.0f;
		 float skeletonDamage = 40.0f;
		 float currentSkeletonHealth = skeletonHealth;
		 int skeletonsKilled = 0;

		 float attackResult;

		 // Armies
		 int armyMen;
		 int armySkeleton;

		 // General (user)
		 string generalName; 

		 char turn = 'H'; // H - Human

		 char gameMenuChoice; // Main menu choice N - New game C - Continue.

		 boolean playingGame = false; // false is main menu state.

		 boolean completedIntro; // if true that means player already completed first part of game where they enter name of general etc.

		 //ifstream saveIn("save.txt");
		 ofstream saveOut;
		 //saveIn.open("save.txt");
		 saveOut.open("save.txt", std::ofstream::out | std::ofstream::app);

		 start_game:

		 cout << "Welcome to NCombat Simuator, would you like to start a new game?" << endl << "Or continue already existing save?" << endl;
		 cin >> gameMenuChoice;

		 if (gameMenuChoice == 'N' || gameMenuChoice == 'n')
		 {
			 cout << "Starting new game..." << endl;
			 cout << string(100, '\n');
			 remove("save.txt");
			 saveOut.close();
			 saveOut.open("save.txt", std::ofstream::out | std::ofstream::trunc);
			 playingGame = true;
		 }
		 else if (gameMenuChoice == 'C' || gameMenuChoice == 'c')
		 {
			 //playingGame = true;
			 cout << "Not yet supported..." << endl; // LEFT OFF HERE, MAKE CONTINUE FEATURE.
		 } 
		 else 
		 {
			 cout << "Error... make sure you entered right letter - N to start a new game, C to continue." << endl;
			 goto start_game;
		 }

		 if (playingGame == true)
		 {
			 //NEW GAME
			
			 cout << troopNames.hManAtArms << ": " << "What your name would be?" << endl;
			 cout << white << "You: ";
			 cin >> generalName;

			 completedIntro = true;
			 if (completedIntro == true)
			 {
				 cout << white << "Completed setup." << endl;
				 saveOut << "intro: 1" << endl;
				 saveOut.flush();
			 }

			 cout << troopNames.hManAtArms << ": "  "Oh, welcome general " << generalName << "." << endl;
			 cout << troopNames.hManAtArms << ": " << "How many men do we have?" << endl;
			 cout << white << "You: ";
			 cin >> armyMen;

			 cout << troopNames.hManAtArms << ": " "I see..." << endl;
			 cout << "((How many skeletons are attacking? (skeletons are weaker than humans)))" << endl;
			 cin >> armySkeleton;

			 if (armySkeleton <= 0)
			 {
				 cout << troopNames.hManAtArms << ": " "Nice weather..." << endl;
			 }
			 else if (armySkeleton > 0 && armySkeleton <= 25)
			 {
				 cout << troopNames.hManAtArms << ": " "Small group of skeletons is attacking!" << endl;
				 cout << troopNames.hManAtArms << ": " "We shall attack!" << endl;
			 }
			 else if (armySkeleton > 25 && armySkeleton < 100)
			 {
				 cout << troopNames.hManAtArms << ": " "Big group of skeletons is attacking!" << endl;
				 cout << troopNames.hManAtArms << ": " "We shall attack!" << endl;
			 }
			 else if (armySkeleton >= 100)
			 {
				 cout << troopNames.hManAtArms << ": " "Army of skeletons is attacking!" << endl;
				 cout << troopNames.hManAtArms << ": " "We shall attack!" << endl;
			 }

			 while ((armyMen > 0) && (armySkeleton > 0)) // Battle process
			 {
				 if (turn == 'H')
				 {
					 if (armyMen--)
					 {
						 cout << red << "Human recruit has been killed" << endl << white << endl;
					 }

					 // Get attack result
					 attackResult = attack(randomEngine);

					 // Check if attack was succsessful
					 if (attackResult <= humanAttack)
					 {
						 currentSkeletonHealth -= humanDamage;
						 if (currentSkeletonHealth < 0)
						 {
							 armySkeleton--;
							 skeletonsKilled++;
						 }
						 turn = 'S';
					 }
				 }
				 else
				 {
					 if (armySkeleton--)
					 {
						 cout << green << "Skeleton recruit has been killed" << white << endl << endl;
					 }

					 currentHumanHealth -= skeletonDamage;

					 if (currentHumanHealth < 0)
					 {
						 armyMen--;
						 humansKilled++;
					 }
					 turn = 'H';
				 }

				 //cout << "Humans: " << armyMen << endl << "Skeletons: " << armySkeleton << endl;

				 if (armyMen <= 0)
				 {
					 cout << "Victory!" << endl;
					 cout << "Humans killed: " << humansKilled << endl << "Skeletons killed: " << skeletonsKilled << endl;
				 }
				 else if (armySkeleton <= 0)
				 {
					 cout << "Defeat" << endl;
					 cout << "Humans killed: " << humansKilled << endl << "Skeletons killed: " << skeletonsKilled << endl;
				 }
			 }
			 system("PAUSE");
		 }
	 }
	 