#pragma once

#include "equippable.h"

class DamageOption;
class SkillOption;
class SwappableOption;

class Weapon : public Equippable
{
private:
	int id_;
	std::string stringId_;
	std::string name_;
	WeaponType type;

	std::vector<std::shared_ptr<DamageOption>> damageOptions_;
	std::vector<std::shared_ptr<SkillOption>> skillOptions_;
	std::shared_ptr<SwappableOption> swappableOption_;

public:
	Weapon(int id, const nlohmann::json& json);
	~Weapon();

	decltype(stringId_) getStringId() const;
	decltype(name_) getName() const;
};