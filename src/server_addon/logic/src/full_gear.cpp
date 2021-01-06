#include "stdafx.h"
#include "full_gear.h"

#include "weapon.h"
#include "equipment.h"

void FullGear::setWeapon(Weapon const* weapon)
{
	weapon_ = weapon;
}

void FullGear::addEquipment(Equipment const* equipment)
{
	equipments_[equipment->getType()] = equipment;
}
