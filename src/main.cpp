#include <iostream>
#include <string>
#include <Windows.h>
#include <random>
#include <ctime>



using namespace std;




int main()
{

	default_random_engine randomEngine(time(0));
	uniform_real_distribution<float> attack(0.0f, 1.0f);

	string generalName;

	// Human properties
	float humanAttack = 0.6f; //Chance
	float humanHealth = 250.0f;
	float humanDamage = 200.0f;
	float currentHumanHealth = humanHealth;
	int humansKilled;

	// Skeleton properties
	float skeletonAttack = 0.2f;
	float skeletonHealth = 50.0f;
	float skeletonDamage = 40.0f;
	float currentSkeletonHealth = skeletonHealth;
	int skeletonsKilled;

	float attackResult;

	// Armies
	int armyMen;
	int armySkeleton;

	char turn = 'H'; // H - Human

	cout << skeletonAttack << endl;
	cout << "What your name would be?" << endl;
	cin >> generalName;
	cout << "Oh, welcome general " << generalName << endl;
	cout << "How many men do we have?" << endl;
	cin >> armyMen;
	cout << "I see..." << endl;
	cout << "((How many skeletons are attacking? (skeletons are weaker than humans)))" << endl;
	cin >> armySkeleton;

	if (armySkeleton <= 0) 
	{

		cout << "Nice weather..." << endl;

	}

	else if (armySkeleton > 0 && armySkeleton <= 25)
	{

		cout << "Small group of skeletons is attacking!" << endl;
		cout << "We shall attack!" << endl;
		goto battleProcess;
	}
	else if (armySkeleton > 25 && armySkeleton < 100)
	{

		cout << "Big group of skeletons is attacking!" << endl;
		cout << "We shall attack!" << endl;
		goto battleProcess;
	}
	else if (armySkeleton >= 100)
	{

		cout << "Army of skeletons is attacking!" << endl;
		cout << "We shall attack!" << endl;
		//End of if's

	battleProcess:
		while ((armyMen > 0) && (armySkeleton > 0)) // Battle process, goto statement.
		{

			if (turn == 'H')
			{


				if (armyMen--)
				{

					cout << "Human recruit has been killed" << endl;

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
			else {

				if (armySkeleton--)
				{

					cout << "Skeleton recruit has been killed" << endl;

				}

				currentHumanHealth -= skeletonDamage;

				if (currentHumanHealth < 0)
				{

					armyMen--;
					humansKilled++;

				}
				turn = 'H';

			}

			cout << "Humans: " << armyMen << endl << "Skeletons: " << armySkeleton << endl;
			
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