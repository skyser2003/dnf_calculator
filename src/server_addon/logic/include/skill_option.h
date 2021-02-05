#pragma once

class SkillOption
{
public:
	SkillOption(const nlohmann::json& json);

private:
	SkillOptionType type;
	std::string skillId_;
	int beginLevel_;
	int endLevel_;
	int value;
};