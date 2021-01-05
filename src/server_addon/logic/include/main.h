#pragma once

#include "nlohmann/json_fwd.hpp"

class Weapon;
class Equipment;
class EquipmentSet;

class Main
{
private:
	std::map<std::string, int> weaponIdConverter_;
	std::map<std::string, int> equipmentIdConverter_;

	std::unique_ptr<nlohmann::json> weaponJson_;
	std::unique_ptr<nlohmann::json> equipmentJson_;
	std::unique_ptr<nlohmann::json> equipmentSetJson_;
	std::unique_ptr<nlohmann::json> dataJson_;

	std::vector<std::unique_ptr<Weapon>> weapons_;
	std::vector<std::unique_ptr<Equipment>> equipments_;
	std::vector<std::unique_ptr<EquipmentSet>> equipmentSets_;

public:
	Main(const std::string& dataPath = "");
	~Main();

	const nlohmann::json& getWeaponJson() const;
	const nlohmann::json& getEquipmentJson() const;
	const nlohmann::json& getEquipmentSetJson() const;
};