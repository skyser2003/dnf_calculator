#pragma once

enum class DamageOptionType
{
	BaseAttackDamage,
	BaseCriAttackDamage,
	AdditionalAttackDamage,
	AdditionalCriAttackDamage,
	BonusDamage,
	AllAttack,
	PercentStat,
	PhyMagIndAttack,
	ExtrinsicAttackDamage,
	DelayedDamage,
	FireElementUp,
	WaterElementUp,
	LightElementUp,
	DarkElementUp,
	AllElementsUp,
	CriChance
};

enum class SkillOptionType
{
	LevelIncrease,
	CooldownReduce,
	CooldownRecoveryUp
};

enum class FinalDamageOptionType
{
	AttackDamage,
	CriAttackDamage,
	BonusDamage,
	AllAttack,
	PercentStat,
	PhyMagIndAttack,
	ExtrinsicAttackDamage,
	FireElementUp,
	WaterElementUp,
	LightElementUp,
	DarkElementUp
};

enum class FinalSkillOptionType
{
	LevelIncrease,
	CooldownReduce
};

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

const auto skillTypeMap = std::map<std::string, SkillOptionType>{
	{"LevelIncrease", SkillOptionType::LevelIncrease},
	{"CooldownReduce", SkillOptionType::CooldownReduce},
	{"CooldownRecoveryUp", SkillOptionType::CooldownRecoveryUp}
};