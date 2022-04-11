#pragma once
#include <string>
#include <iostream>
using namespace std;

class Weapon
{
public:
	bool isOwned;
	bool isEquipped;
	string weaponName;
	string weaponSound;
	float weaponCost;
	int weaponUses;
	int weaponSlot;
	int numWeapons = 0;

	Weapon()
	{

	}

	Weapon(bool owned, bool equip, string name, string sound, float cost, int uses, int slot)
	{
		isOwned = owned;
		weaponName = name;
		weaponSound = sound;
		weaponCost = cost;
		weaponUses = uses;
		weaponSlot = slot;
		isEquipped = equip;
	}

	void UseWeapon()
	{
		if (weaponUses > 0)
		{
			cout << weaponSound << endl;
			weaponUses--;
			cout << "Ammo left:" << weaponUses;
		}
		else
		{
			cout << "You're out of ammo!!" << endl;
		}
	}
};
