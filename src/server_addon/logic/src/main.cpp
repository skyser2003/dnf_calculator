#include "stdafx.h"
#include "main.h"

#include "weapon.h"
#include "equipment.h"
#include "equipment_set.h"

Main::Main()
{
	size_t apiKeySize;
	char rawApiKey[255];
	getenv_s(&apiKeySize, rawApiKey, sizeof(rawApiKey), "API_KEY");

	const std::string apiKey = rawApiKey ? rawApiKey : "";

	auto weaponJsonFile = std::ifstream("data/weapon.json");
	auto equipmentJsonFile = std::ifstream("data/equipment.json");
	auto equipmentSetJsonFile = std::ifstream("data/equipment_set.json");

	auto weaponJsonStr = std::string(std::istreambuf_iterator<char>(weaponJsonFile), std::istreambuf_iterator<char>());
	auto equipmentJsonStr = std::string(std::istreambuf_iterator<char>(equipmentJsonFile), std::istreambuf_iterator<char>());
	auto equipmentSetJsonStr = std::string(std::istreambuf_iterator<char>(equipmentSetJsonFile), std::istreambuf_iterator<char>());

	auto weaponJson = nlohmann::json::parse(weaponJsonStr);
	auto equipmentJson = nlohmann::json::parse(equipmentJsonStr);
	auto equipmentSetJson = nlohmann::json::parse(equipmentSetJsonStr);

	// Data
	for (auto& it : weaponJson)
	{
		int uid = weapons_.size();
		auto weapon = std::make_unique<Weapon>(uid, it);
		weaponIdConverter_.emplace(weapon->getStringId(), uid);

		weapons_.push_back(std::move(weapon));
	}

	for (auto& it : equipmentJson)
	{
		int uid = equipments_.size();
		auto equipment = std::make_unique<Equipment>(uid, it);
		equipmentIdConverter_.emplace(equipment->getStringId(), uid);

		equipments_.push_back(std::move(equipment));
	}

	equipmentSet_.reset(new EquipmentSet(equipmentSetJson));

	equipmentJsonFile.close();
	equipmentSetJsonFile.close();
	weaponJsonFile.close();

	std::cout << "All data parsing done" << std::endl;
}

Main::~Main()
{

}