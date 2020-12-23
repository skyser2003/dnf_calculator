#include "stdafx.h"
#include "equipment.h"

Equipment::Equipment(const std::map<StatType, float>& stats)
{
	this->stats = stats;
}