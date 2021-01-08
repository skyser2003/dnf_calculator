#include "stdafx.h"
#include "equipment_set.h"

EquipmentSet::EquipmentSet(const nlohmann::json& json) : json_(json)
{
	id_ = equipmentSetTypeMap.at(json["id"].get<std::string>());
	this->name_ = "";

	auto& setOptions = json["set_options"];

	for (auto& it : setOptions)
	{
		auto setOption = std::make_shared<EquipmentSetOption>(id_, it);
		auto piece = setOption->getPiece();

		this->setOptions_.emplace(piece, setOption);
	}
}

decltype(EquipmentSet::id_) EquipmentSet::getId() const
{
	return id_;
}

EquipmentSetOption::EquipmentSetOption(EquipmentSetType setId, const nlohmann::json& json) :
	OptionContainer(json),
	setId_(setId)
{
	this->piece_ = json["piece"].get<int>();
}

EquipmentSetOption::~EquipmentSetOption()
{
}

decltype(EquipmentSetOption::piece_) EquipmentSetOption::getPiece() const
{
	return piece_;
}
