#include "stdafx.h"
#include "option_container.h"

#include "damage_option.h"
#include "skill_option.h"
#include "swappable_option.h"
#include "extra_option.h"

OptionContainer::OptionContainer(const nlohmann::json& json)
{
	const auto& damageOptionsIt = json.find("damage_options");
	const auto& skillOptionsIt = json.find("skill_options");
	const auto& extraOptionsIt = json.find("extra_options");

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

	if (extraOptionsIt != json.end())
	{
		for (const auto& it : extraOptionsIt.value())
		{
			auto type = extraTypeMap.at(it["type"].get<std::string>());

			switch (type)
			{
			case ExtraOptionType::TalismanCooldownReduce:
			case ExtraOptionType::TalismanDamageIncrease:
			{
				talismanOptions_.push_back(std::make_shared<TalismanExtraOption>(type, it));
			}
			break;

			default:
			{
				break;
			}
			}
		}
	}
}

const decltype(OptionContainer::damageOptions_)& OptionContainer::getDamageOptions() const
{
	return damageOptions_;
}

const decltype(OptionContainer::skillOptions_)& OptionContainer::getSkillOptions() const
{
	return skillOptions_;
}

SwappableOptionContainer::SwappableOptionContainer(const nlohmann::json& json) : OptionContainer(json)
{
	const auto& swappableOptionIt = json.find("swappable_option");

	if (swappableOptionIt != json.end())
	{
		swappableOption_.reset(new SwappableOption(*swappableOptionIt));
	}
}