#pragma once

#include "option_container.h"

class Weapon : public SwappableOptionContainer
{
private:
	int id_;
	std::string stringId_;
	std::string name_;
	WeaponType type;

public:
	Weapon(int id, const nlohmann::json& json);
	~Weapon();

	decltype(stringId_) getStringId() const;
	decltype(name_) getName() const;
};