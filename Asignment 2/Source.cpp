#include <iostream>
#include <string>
#include "weapons.h"
using namespace std;

int main()
{
	const int numWeapons = 6;
	Weapon weapons[numWeapons];

	weapons[0] = Weapon{ false, false, "FLATLINE", "POW POW", 3100, 28, 1 }; // Owned, Equipped, Weapon Name, Weapon Sound, Weapon Price, Weapon Ammo, Weapon Slot
	weapons[1] = Weapon{ false, false, "LONGBOW", "BOOM", 2500, 10, 2 };
	weapons[2] = Weapon{ false, false, "R-99", "TAKA TAKA", 2700, 30, 3 };
	weapons[3] = Weapon{ false, false, "SPITFIRE", "RATTATTATA", 3100, 150, 4 };
	weapons[4] = Weapon{ false, false, "R-301", "PEW PEW", 3100, 25, 5 };
	weapons[5] = Weapon{ false, false, "KRABER", "KAPOW", 5000,12, 6 };

	bool MenuExit = false;
	bool GameExit = false;
	char SwitchCase;
	float balance = 9000;
	bool weaponOwned = false;
	int weaponEquip;
	int menuChoice;
	int weaponChoice;

	while (MenuExit == false)
	{
		cout << "1. Weapon store" << endl << "2. Balance" << endl << "3. Exit" << endl;

		cin >> menuChoice;

		if (menuChoice == 1)
		{
			cout << "Weapons ready to buy: " << endl << endl;

			for (int i = 0; i < 6; i++)
			{
				cout << weapons[i].weaponName << " for " << weapons[i].weaponCost << "$. Slot " << weapons[i].weaponSlot << endl;
			}

			cout << endl << "To buy a weapon, choose a slot from 1 to 6. Otherwise, press 7 to go back to the main menu." << endl << endl;
			cin >> weaponChoice;

			if (weaponChoice > 0 && weaponChoice < 7)
			{
				weaponChoice--;
				if (weapons[weaponChoice].isOwned)
				{
					cout << "You already own a " << weapons[weaponChoice].weaponName << " for slot " << weapons[weaponChoice].weaponSlot << endl << endl;
				}
				else
				{
					if (balance < weapons[weaponChoice].weaponCost)
					{
						cout << "You can't afford " << weapons[weaponChoice].weaponName << endl;
					}
					else
					{
						balance = balance - weapons[weaponChoice].weaponCost;
						cout << "Thank you for buying " << weapons[weaponChoice].weaponName << "! You have $" << balance << " remaining." << endl;
						weapons[weaponChoice].isOwned = true;
						weaponOwned = true;
					}
				}

			}
			else if (weaponChoice < 0 || weaponChoice > 8)
			{
				cout << "Invalid input." << endl;
			}

		}

		else if (menuChoice == 2)
		{
			cout << "You have $" << balance << " remaining." << endl;
		}

		else if (menuChoice == 3)
		{
			if (weaponOwned == false)
			{
				cout << "Please buy a weapon before leaving." << endl;
			}
			else if (weaponOwned == true)
			{
				MenuExit = true;
			}
		}

	}

	cout << "Here's your armory:" << endl << endl;

	while (GameExit == false)
	{
		for (int i = 0; i < 6; i++)
		{
			if (weapons[i].isOwned == true)
			{
				cout << weapons[i].weaponName << " in slot " << weapons[i].weaponSlot << endl;
			}
		}

		cout << endl << "Enter a slot number to equip that weapon" << endl << endl;

		cin >> weaponEquip;
		weaponEquip--;
		if (weapons[weaponEquip].isOwned == false)
		{
			cout << endl << "You don't have that." << endl;
		}
		else
		{
			weapons[weaponEquip].isEquipped = true;
			cout << "Equipped weapon: " << weapons[weaponEquip].weaponName << endl << "Press F to fire, S to switch weapon or X to exit" << endl;
			while (weapons[weaponEquip].isEquipped == true)
			{
				cin >> SwitchCase;
				switch (SwitchCase)
				{
				case 'F':
				case 'f':
					weapons[weaponEquip].UseWeapon();
					break;
				case 'S':
				case 's':
					weapons[weaponEquip].isEquipped = false;
					break;
				case 'X':
				case 'x':
					weapons[weaponEquip].isEquipped = false;
					GameExit = true;
					break;
				}
			}
		}
	}

	if (GameExit == true)
	{
		cout << "Thank you for visiting our store!" << endl;
		system("pause");
	}
	return 0;
}