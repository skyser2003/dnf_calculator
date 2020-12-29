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
	FireElementUp,
	WaterElementUp,
	LightElementUp,
	DarkElementUp,
	AllElementsUp
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