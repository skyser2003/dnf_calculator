#pragma once

class Weapon;
class Equipment;

class FullGear
{
private:
	Weapon const * weapon_;
	std::map<EquipmentType, Equipment const*> equipments_;

public:
	void setWeapon(Weapon const* weapon);
	void addEquipment(Equipment const* equipment);
};