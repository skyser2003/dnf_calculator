#pragma once

enum class DamageOptionType
{
	BaseAttackDamage,
	BaseCriAttackDamage,
	AdditionalAttackDamage,
	AdditionalCriAttackDamage,
	BonusDamage,
	ElementalBonusDamage,
	AllAttack,
	PercentStat,
	PhyMagIndAttack,
	ExtrinsicAttackDamage,
	DelayedDamage,
	FireElementUp,
	WaterElementUp,
	LightElementUp,
	ShadowElementUp,
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
	ShadowElementUp
};

enum class FinalSkillOptionType
{
	LevelIncrease,
	CooldownReduce
};

#define DamageTypePair(NAME) {#NAME, DamageOptionType::NAME}
#define SkillTypePair(NAME) {#NAME, SkillOptionType::NAME}

const auto damageTypeMap = std::map<std::string, DamageOptionType>{
	DamageTypePair(BaseAttackDamage),
	DamageTypePair(BaseCriAttackDamage),
	DamageTypePair(AdditionalAttackDamage),
	DamageTypePair(AdditionalCriAttackDamage),
	DamageTypePair(BonusDamage),
	DamageTypePair(ElementalBonusDamage),
	DamageTypePair(AllAttack),
	DamageTypePair(PercentStat),
	DamageTypePair(PhyMagIndAttack),
	DamageTypePair(ExtrinsicAttackDamage),
	DamageTypePair(DelayedDamage),
	DamageTypePair(FireElementUp),
	DamageTypePair(WaterElementUp),
	DamageTypePair(LightElementUp),
	DamageTypePair(ShadowElementUp),
	DamageTypePair(AllElementsUp),
	DamageTypePair(CriChance)
};

const auto skillTypeMap = std::map<std::string, SkillOptionType>{
	SkillTypePair(LevelIncrease),
	SkillTypePair(CooldownReduce),
	SkillTypePair(CooldownRecoveryUp)
};