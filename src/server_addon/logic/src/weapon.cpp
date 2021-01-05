#include "stdafx.h"
#include "weapon.h"

#include "damage_option.h"
#include "skill_option.h"

Weapon::Weapon(int id, const nlohmann::json& json) : Equippable(json), id_(id)
{
	this->stringId_ = json["id"].get<std::string>();
	this->name_ = json["name"].get<std::string>();
	this->type = weaponTypeMap.at(json["type"].get<std::string>());

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

Weapon::~Weapon()
{
}

decltype(Weapon::stringId_) Weapon::getStringId() const
{
	return stringId_;
}

decltype(Weapon::name_) Weapon::getName() const
{
	return name_;
}