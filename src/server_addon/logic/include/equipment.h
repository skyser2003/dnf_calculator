#pragma once

class Equipment
{
public:
	Equipment(const std::map<StatType, float>& stats);

private:
	std::map<StatType, float> stats;
};