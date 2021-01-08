#include "stdafx.h"
#include "option_container.h"

#include "damage_option.h"
#include "skill_option.h"
#include "swappable_option.h"

OptionContainer::OptionContainer(const nlohmann::json& json)
{
	const auto& damageOptionsIt = json.find("damage_options");
	const auto& skillOptionsIt = json.find("skill_options");

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
}

SwappableOptionContainer::SwappableOptionContainer(const nlohmann::json& json) : OptionContainer(json)
{
	const auto& swappableOptionIt = json.find("swappable_option");

	if (swappableOptionIt != json.end())
	{
		swappableOption_.reset(new SwappableOption(*swappableOptionIt));
	}
}