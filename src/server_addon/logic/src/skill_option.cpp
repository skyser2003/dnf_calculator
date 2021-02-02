#include "stdafx.h"
#include "skill_option.h"

std::regex levelRegex(R"((\d+)(\s*-\s*(\d+)){0,1})");

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
		beginLevel_ = std::stoi(levelMatch[1]);

		if (levelMatch[3].matched == false)
		{
			endLevel_ = beginLevel_;
		}
		else
		{
			endLevel_ = std::stoi(levelMatch[3]);
		}
	}
}