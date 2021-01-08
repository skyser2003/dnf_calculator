#pragma once

class DamageOption;
class SkillOption;
class SwappableOption;

class OptionContainer
{
protected:
	std::vector<std::shared_ptr<DamageOption>> damageOptions_;
	std::vector<std::shared_ptr<SkillOption>> skillOptions_;

public:
	OptionContainer(const nlohmann::json& json);
};

class SwappableOptionContainer : public OptionContainer
{
protected:
	std::shared_ptr<SwappableOption> swappableOption_;

public:
	SwappableOptionContainer(const nlohmann::json& json);

};