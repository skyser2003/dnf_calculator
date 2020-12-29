#include "stdafx.h"
#include "skill_option.h"

const auto skillTypeMap = std::map<std::string, SkillOptionType>{
	{"LevelIncrease", SkillOptionType::LevelIncrease},
	{"CooldownReduce", SkillOptionType::CooldownReduce},
	{"CooldownRecoveryUp", SkillOptionType::CooldownRecoveryUp}
};

std::regex levelRegex(R"((\d+)\s*-\s*(\d+))");

SkillOption::SkillOption(const nlohmann::json& json)
{
	auto type = json["type"].get<std::string>();
	auto levelRange = json["level_range"].get<std::string>();
	auto value = json["value"].get<decltype(this->value)>();

	this->type = skillTypeMap.at(type);
	this->value = value;

	std::smatch levelMatch;
	if (std::regex_match(levelRange, levelMatch, levelRegex))
	{
		auto beginLevel = std::stoi(levelMatch[1]);
		auto endLevel = std::stoi(levelMatch[2]);

		if (beginLevel == 1)
		{
			this->levels.push_back(beginLevel);
			beginLevel = 5;
		}

		for (auto i = beginLevel; i <= endLevel; i += 5)
		{
			this->levels.push_back(i);
		}
	}
}