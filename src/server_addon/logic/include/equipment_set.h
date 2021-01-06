#pragma once

#include "equippable.h"

class DamageOption;
class SkillOption;

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

class EquipmentSetOption
{
private:
	EquipmentSetType setId_;
	int piece_;

	std::vector<std::shared_ptr<DamageOption>> damageOptions_;
	std::vector<std::shared_ptr<SkillOption>> skillOptions_;

public:
	EquipmentSetOption(EquipmentSetType setId, const nlohmann::json& json);
	~EquipmentSetOption();

	decltype(piece_) getPiece() const;
};