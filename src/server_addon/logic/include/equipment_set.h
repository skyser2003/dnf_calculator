#pragma once

#include "option_container.h"

class EquipmentSetOption;

class EquipmentSet
{
private:
	const nlohmann::json json_;

	EquipmentSetType id_;
	std::string name_;

	std::map<int, std::shared_ptr<EquipmentSetOption>> setOptions_;

public:
	EquipmentSet(const nlohmann::json& json);

	decltype(id_) getId() const;
};

class EquipmentSetOption : public OptionContainer
{
private:
	EquipmentSetType setId_;
	int piece_;

public:
	EquipmentSetOption(EquipmentSetType setId, const nlohmann::json& json);
	~EquipmentSetOption();

	decltype(piece_) getPiece() const;
};