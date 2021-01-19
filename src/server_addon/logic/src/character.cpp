#include "stdafx.h"
#include "character.h"

#include "equipment.h"

void Character::addElement(AttackElementType element)
{
	this->elements_.emplace(element);
}
