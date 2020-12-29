#include "stdafx.h"
#include "equipment.h"

#include "damage_option.h"
#include "skill_option.h"

const auto equipmentTypeMap = std::map<std::string, EquipmentPart>{
	{"head_shoulder", EquipmentPart::HeadShoulder},
	{"top", EquipmentPart::Top},
	{"bottom", EquipmentPart::Bottom},
	{"belt", EquipmentPart::Belt},
	{"shoes", EquipmentPart::Shoes},
	{"bracelet", EquipmentPart::Bracelet},
	{"necklace", EquipmentPart::Necklace},
	{"ring", EquipmentPart::Ring},
	{"sub_equipment", EquipmentPart::SubEquipment},
	{"magic_stone", EquipmentPart::MagicStone},
	{"earrings", EquipmentPart::Earrings}
};

Equipment::Equipment(int id, const nlohmann::json& json) : id_(id)
{
	this->stringId_ = json["id"].get<std::string>();
	this->name_ = json["name"].get<std::string>();
	this->type_ = equipmentTypeMap.at(json["type"].get<std::string>());
	this->setId_ = json["set_id"].get<std::string>();

	const auto& jsonIsMythic = json["is_mythic"];
	this->isMythic_ = jsonIsMythic.is_boolean() && jsonIsMythic.get<bool>();

	const auto& jsonDamageOptions = json["damage_options"];
	const auto& jsonSkillOptions = json["skill_options"];

	for (const auto& it : jsonDamageOptions)
	{
		this->damageOptions_.push_back(std::make_unique<DamageOption>(it));
	}

	for (const auto& it : jsonSkillOptions)
	{
		this->skillOptions_.push_back(std::make_unique<SkillOption>(it));
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
