#pragma once

#include "enum_equipment.h"

class Equipment;

class Character
{
public:
	void setEquipment(EquipmentPart equipPart, Equipment& equipment);
	const std::map<StatType, float> calcStats() const;

private:
	std::map<EquipmentPart, Equipment&> equipments;
};