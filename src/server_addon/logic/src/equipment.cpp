#include "stdafx.h"
#include "equipment.h"

#include "damage_option.h"
#include "skill_option.h"

const auto equipmentTypeMap = std::map<std::string, EquipmentType>{
	{"head_shoulder", EquipmentType::HeadShoulder},
	{"top", EquipmentType::Top},
	{"bottom", EquipmentType::Bottom},
	{"belt", EquipmentType::Belt},
	{"shoes", EquipmentType::Shoes},
	{"bracelet", EquipmentType::Bracelet},
	{"necklace", EquipmentType::Necklace},
	{"ring", EquipmentType::Ring},
	{"sub_equipment", EquipmentType::SubEquipment},
	{"magic_stone", EquipmentType::MagicStone},
	{"earrings", EquipmentType::Earrings}
};

Equipment::Equipment(int id, const nlohmann::json& json) : Equippable(json), id_(id)
{
	this->stringId_ = json["id"].get<std::string>();
	this->name_ = "";
	this->type_ = equipmentTypeMap.at(json["type"].get<std::string>());
	this->setId_ = json["set_id"].get<std::string>();
	this->isMythic_ = json["is_mythic"].get<bool>();

	const auto& damageOptionsIt = json.find("damage_options");
	const auto& skillOptionsIt = json.find("skill_options");

	if (damageOptionsIt != json.end())
	{
		for (const auto& it : damageOptionsIt.value())
		{
			this->damageOptions_.push_back(std::make_unique<DamageOption>(it));
		}
	}

	if (skillOptionsIt != json.end())
	{
		for (const auto& it : skillOptionsIt.value())
		{
			this->skillOptions_.push_back(std::make_unique<SkillOption>(it));
		}
	}
}

Equipment::~Equipment()
{

}

decltype(Equipment::stringId_) Equipment::getStringId() const
{
	return stringId_;
}

decltype(Equipment::name_) Equipment::getName() const
{
	return name_;
}
