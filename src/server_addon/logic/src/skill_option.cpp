#include "stdafx.h"
#include "skill_option.h"

std::regex levelRegex(R"((\d+)(\s*-\s*(\d+)){0,1})");

SkillOption::SkillOption(const nlohmann::json& json) : beginLevel_(-1), endLevel_(-1)
{
	auto type = json["type"].get<std::string>();
	auto levelRangeIt = json.find("level_range");
	auto skillIdIt = json.find("skill_id");
	auto value = json["value"].get<decltype(this->value)>();

	this->type = skillTypeMap.at(type);
	this->value = value;

	if (levelRangeIt != json.end())
	{
		auto levelRange = levelRangeIt.value().get<std::string>();

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

	if (skillIdIt != json.end())
	{
		this->skillId_ = skillIdIt.value().get<std::string>();
	}
}