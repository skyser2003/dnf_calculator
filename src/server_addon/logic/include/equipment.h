#pragma once

#include "option_container.h"

class DamageOption;
class SkillOption;
class SwappableOption;

class Equipment : public OptionContainer
{
private:
	int id_;
	std::string stringId_;
	std::string name_;
	EquipmentType type_;
	std::string setId_;
	bool isMythic_;

	std::vector<std::shared_ptr<DamageOption>> damageOptions_;
	std::vector<std::shared_ptr<SkillOption>> skillOptions_;
	std::shared_ptr<SwappableOption> swappableOption_;

public:
	Equipment(int id, const nlohmann::json& json);
	~Equipment();

	decltype(stringId_) getStringId() const;
	decltype(name_) getName() const;
	decltype(type_) getType() const;
};