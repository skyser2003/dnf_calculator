#include "stdafx.h"
#include "main.h"

#include "weapon.h"
#include "equipment.h"
#include "equipment_set.h"

Main::Main() :
	weaponJson_(new nlohmann::json()),
	equipmentJson_(new nlohmann::json()),
	equipmentSetJson_(new nlohmann::json()),
	dataJson_(new nlohmann::json())
{

	size_t apiKeySize;
	char rawApiKey[255];
	getenv_s(&apiKeySize, rawApiKey, sizeof(rawApiKey), "API_KEY");

	const std::string apiKey = rawApiKey ? rawApiKey : "";

	auto weaponJsonFile = std::ifstream("data/weapon.json");
	auto equipmentJsonFile = std::ifstream("data/equipment.json");
	auto equipmentSetJsonFile = std::ifstream("data/equipment_set.json");
	auto dataJsonFile = std::ifstream("data/dat.json");

	weaponJsonFile >> *weaponJson_;
	equipmentJsonFile >> *equipmentJson_;
	equipmentSetJsonFile >> *equipmentSetJson_;
	dataJsonFile >> *dataJson_;

	// Data
	for (const auto& it : *weaponJson_)
	{
		int uid = weapons_.size();
		auto weapon = std::make_unique<Weapon>(uid, it);
		cout << "Weapon uid: " << uid << endl;
		weaponIdConverter_.insert({ weapon->getStringId(), uid });
		// weaponIdConverter_.emplace(weapon->getStringId(), uid);

		weapons_.push_back(std::move(weapon));
	}

	cout << "test2" << endl;

	for (const auto& it : *equipmentJson_)
	{
		int uid = equipments_.size();
		auto equipment = std::make_unique<Equipment>(uid, it);
		equipmentIdConverter_.emplace(equipment->getStringId(), uid);

		equipments_.push_back(std::move(equipment));
	}

	for (const auto& it : *equipmentSetJson_)
	{
		auto equipmentSet = std::make_unique<EquipmentSet>(it);

		equipmentSets_.push_back(std::move(equipmentSet));
	}

	equipmentJsonFile.close();
	equipmentSetJsonFile.close();
	weaponJsonFile.close();
	dataJsonFile.close();

	std::cout << "All data parsing done" << std::endl;
}

Main::~Main()
{

}

const nlohmann::json& Main::getWeaponJson() const
{
	return *weaponJson_;
}

const nlohmann::json& Main::getEquipmentJson() const
{
	return *equipmentJson_;
}

const nlohmann::json& Main::getEquipmentSetJson() const
{
	return *equipmentSetJson_;
}
