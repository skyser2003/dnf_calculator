#pragma once

#include "enum_equipment.h"

class Equipment;

class Character
{
public:
	void setEquipment(EquipmentType equipPart, Equipment& equipment);
	const std::map<FinalDamageOptionType, float> calcStats() const;

private:
	std::map<EquipmentType, Equipment&> equipments;
};