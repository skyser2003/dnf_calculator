#pragma once

class SkillOption
{
public:
	SkillOption(const nlohmann::json& json);

private:
	SkillOptionType type;
	std::vector<int> levels;
	int value;
};