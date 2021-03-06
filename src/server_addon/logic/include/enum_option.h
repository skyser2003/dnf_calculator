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
	FixedStat,
	PercentPhyMagIndAttack,
	FixedPhyMagIndAttack,
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
	DamageIncrease,
	CooldownReduce,
	CooldownReduceExceptUltimate,
	CooldownRecoveryUp
};

enum class ExtraOptionType
{
	AttackSpeed,
	MoveSpeed,
	CastSpeed,
	PartialSuperArmor,
	FullSuperArmor,
	TalismanCooldownReduce,
	TalismanDamageIncrease
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
	DamageIncrease,
	CooldownReduce
};

#define DamageTypePair(NAME) {#NAME, DamageOptionType::NAME}
#define SkillTypePair(NAME) {#NAME, SkillOptionType::NAME}
#define ExtraTypePair(NAME) {#NAME, ExtraOptionType::NAME}

const auto damageTypeMap = std::map<std::string, DamageOptionType>{
	DamageTypePair(BaseAttackDamage),
	DamageTypePair(BaseCriAttackDamage),
	DamageTypePair(AdditionalAttackDamage),
	DamageTypePair(AdditionalCriAttackDamage),
	DamageTypePair(BonusDamage),
	DamageTypePair(ElementalBonusDamage),
	DamageTypePair(AllAttack),
	DamageTypePair(PercentStat),
	DamageTypePair(FixedStat),
	DamageTypePair(PercentPhyMagIndAttack),
	DamageTypePair(FixedPhyMagIndAttack),
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
	SkillTypePair(DamageIncrease),
	SkillTypePair(CooldownReduce),
	SkillTypePair(CooldownReduceExceptUltimate),
	SkillTypePair(CooldownRecoveryUp)
};

const auto extraTypeMap = std::map<std::string, ExtraOptionType>{
	ExtraTypePair(AttackSpeed),
	ExtraTypePair(MoveSpeed),
	ExtraTypePair(CastSpeed),
	ExtraTypePair(PartialSuperArmor),
	ExtraTypePair(FullSuperArmor),
	ExtraTypePair(TalismanCooldownReduce),
	ExtraTypePair(TalismanDamageIncrease)
};