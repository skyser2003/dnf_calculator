#include "stdafx.h"
#include "character.h"

#include "equipment.h"

void Character::setEquipment(EquipmentPart equipPart, Equipment& equipment)
{
	equipments.insert({ equipPart, equipment });
}

const std::map<FinalDamageOptionType, float> Character::calcStats() const
{
	auto stats = decltype(calcStats())();

	float baseAttackDamage = 0;
	float baseCriAttackDamage = 0;

	for (auto& it : equipments)
	{
		const auto& equipment = it.second;
	}

	return stats;
}
