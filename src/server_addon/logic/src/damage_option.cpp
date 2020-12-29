#include "stdafx.h"
#include "damage_option.h"

const auto damageTypeMap = std::map<std::string, DamageOptionType>{
	{"BaseAttackDamage", DamageOptionType::BaseAttackDamage},
	{"BaseCriAttackDamage", DamageOptionType::BaseCriAttackDamage},
	{"AdditionalAttackDamage", DamageOptionType::AdditionalAttackDamage},
	{"AdditionalCriAttackDamage", DamageOptionType::AdditionalCriAttackDamage},
	{"BonusDamage", DamageOptionType::BonusDamage},
	{"AllAttack", DamageOptionType::AllAttack},
	{"PercentStat", DamageOptionType::PercentStat},
	{"PhyMagIndAttack", DamageOptionType::PhyMagIndAttack},
	{"ExtrinsicAttackDamage", DamageOptionType::ExtrinsicAttackDamage},
	{"FireElementUp", DamageOptionType::FireElementUp},
	{"WaterElementUp", DamageOptionType::WaterElementUp},
	{"LightElementUp", DamageOptionType::LightElementUp},
	{"DarkElementUp", DamageOptionType::DarkElementUp},
	{"AllElementsUp", DamageOptionType::AllElementsUp}
};

DamageOption::DamageOption(const nlohmann::json& json)
{
	this->type = damageTypeMap.at(json["type"].get<std::string>());
	this->value = json["value"].get<decltype(this->value)>();
}
