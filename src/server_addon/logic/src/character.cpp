#include "stdafx.h"
#include "character.h"

void Character::setEquipment(EquipmentPart equipPart, Equipment& equipment)
{
	equipments.insert({ equipPart, equipment });
}

const std::map<StatType, float> Character::calcStats() const
{
	auto stats = std::map<StatType, float>();

	for (auto& it : equipments)
	{
		const auto& equipment = it.second;
	}

	return stats;
}
