#pragma once

#include "enum_equipment.h"

class Equipment;

class Character
{
private:
	std::set<AttackElementType> elements_;

public:
	void addElement(AttackElementType element);

};