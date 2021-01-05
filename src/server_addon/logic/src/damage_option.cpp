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
	{"DelayedDamage", DamageOptionType::DelayedDamage},
	{"FireElementUp", DamageOptionType::FireElementUp},
	{"WaterElementUp", DamageOptionType::WaterElementUp},
	{"LightElementUp", DamageOptionType::LightElementUp},
	{"DarkElementUp", DamageOptionType::DarkElementUp},
	{"AllElementsUp", DamageOptionType::AllElementsUp},
	{"CriChance", DamageOptionType::CriChance}
};

DamageOption::DamageOption(const nlohmann::json& json)
{
	cout << json.dump() << endl;
	this->type = damageTypeMap.at(json["type"].get<std::string>());
	this->value = json["value"].get<decltype(this->value)>();
}
