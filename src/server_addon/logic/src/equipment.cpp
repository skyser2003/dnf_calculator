#include "stdafx.h"
#include "equipment.h"

Equipment::Equipment(int id, const nlohmann::json& json) : SwappableOptionContainer(json), id_(id)
{
	this->stringId_ = json["id"].get<std::string>();
	this->name_ = "";
	this->type_ = equipmentTypeMap.at(json["type"].get<std::string>());
	this->setId_ = json["set_id"].get<std::string>();
	this->isMythic_ = json["is_mythic"].get<bool>();
}

Equipment::~Equipment()
{

}

decltype(Equipment::stringId_) Equipment::getStringId() const
{
	return stringId_;
}

decltype(Equipment::name_) Equipment::getName() const
{
	return name_;
}

decltype(Equipment::type_) Equipment::getType() const
{
	return type_;
}
