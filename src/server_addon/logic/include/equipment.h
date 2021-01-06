#pragma once

#include "equippable.h"

class DamageOption;
class SkillOption;
class SwappableOption;

class Equipment : public Equippable
{
private:
	int id_;
	std::string stringId_;
	std::string name_;
	EquipmentType type_;
	std::string setId_;
	bool isMythic_;

	std::vector<std::unique_ptr<DamageOption>> damageOptions_;
	std::vector<std::unique_ptr<SkillOption>> skillOptions_;
	std::unique_ptr<SwappableOption> swappableOption_;

public:
	Equipment(int id, const nlohmann::json& json);
	~Equipment();

	decltype(stringId_) getStringId() const;
	decltype(name_) getName() const;
	decltype(type_) getType() const;
};