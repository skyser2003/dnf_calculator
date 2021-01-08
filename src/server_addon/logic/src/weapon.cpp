#include "stdafx.h"
#include "weapon.h"

Weapon::Weapon(int id, const nlohmann::json& json) : SwappableOptionContainer(json), id_(id)
{
	this->stringId_ = json["id"].get<std::string>();
	this->name_ = json["name"].get<std::string>();
	this->type = weaponTypeMap.at(json["type"].get<std::string>());
}

Weapon::~Weapon()
{
}

decltype(Weapon::stringId_) Weapon::getStringId() const
{
	return stringId_;
}

decltype(Weapon::name_) Weapon::getName() const
{
	return name_;
}