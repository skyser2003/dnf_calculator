#pragma once

class DamageOption;
class SkillOption;
class SwappableOption;

class TalismanExtraOption;

class OptionContainer
{
protected:
	std::vector<std::shared_ptr<DamageOption>> damageOptions_;
	std::vector<std::shared_ptr<SkillOption>> skillOptions_;

	std::vector<std::shared_ptr<TalismanExtraOption>> talismanOptions_;

public:
	OptionContainer(const nlohmann::json& json);

	const decltype(damageOptions_)& getDamageOptions() const;
	const decltype(skillOptions_)& getSkillOptions() const;
};

class SwappableOptionContainer : public OptionContainer
{
protected:
	std::shared_ptr<SwappableOption> swappableOption_;

public:
	SwappableOptionContainer(const nlohmann::json& json);

};