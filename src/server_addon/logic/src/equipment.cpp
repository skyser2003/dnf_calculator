#include "stdafx.h"
#include "equipment.h"

#include "damage_option.h"
#include "skill_option.h"
#include "swappable_option.h"

Equipment::Equipment(int id, const nlohmann::json& json) : OptionContainer(json), id_(id)
{
	this->stringId_ = json["id"].get<std::string>();
	this->name_ = "";
	this->type_ = equipmentTypeMap.at(json["type"].get<std::string>());
	this->setId_ = json["set_id"].get<std::string>();
	this->isMythic_ = json["is_mythic"].get<bool>();

	const auto& damageOptionsIt = json.find("damage_options");
	const auto& skillOptionsIt = json.find("skill_options");
	const auto& swappableOptionIt = json.find("swappable_option");

	if (damageOptionsIt != json.end())
	{
		for (const auto& it : damageOptionsIt.value())
		{
			this->damageOptions_.push_back(std::make_shared<DamageOption>(it));
		}
	}

	if (skillOptionsIt != json.end())
	{
		for (const auto& it : skillOptionsIt.value())
		{
			this->skillOptions_.push_back(std::make_shared<SkillOption>(it));
		}
	}

	if (swappableOptionIt != json.end())
	{
		swappableOption_.reset(new SwappableOption(*swappableOptionIt));
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

decltype(Equipment::type_) Equipment::getType() const
{
	return type_;
}
