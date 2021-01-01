#pragma once

class Weapon;
class Equipment;
class EquipmentSet;

class Main
{
public:
	Main();
	~Main();

private:
	std::map<std::string, int> weaponIdConverter_;
	std::map<std::string, int> equipmentIdConverter_;

	std::vector<std::unique_ptr<Weapon>> weapons_;
	std::vector<std::unique_ptr<Equipment>> equipments_;
	std::vector<std::unique_ptr<EquipmentSet>> equipmentSets_;
};