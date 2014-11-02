#pragma once
#include <string>

class TroopNames
{

    public:

		TroopNames();

			// Positions/Classes (Might change or be moved!)
			std::string hGeneral; // General
			std::string generalName; // General (user)
			std::string hKnight; // Horseman
			std::string hManAtArms; // Horseman
			std::string hSquire; // Footman
			std::string hSpearman; // Footman
			std::string hRecruit; // Footman/Spear
			std::string hSwordsman; // Footman
			std::string hChampionSwordsman; //Footman 
			std::string hVeteranSwordsman; // Footman
			std::string hCrossbowman; // Ranged
			std::string hBowyer; // Ranged
			std::string hSharpshooter; // Ranged/Crossbow
			std::string hHunter; // Ranged
		
	~TroopNames();

};
