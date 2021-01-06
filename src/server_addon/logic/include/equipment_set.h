#pragma once

#include "equippable.h"

class DamageOption;
class SkillOption;

class EquipmentSetOption;

class EquipmentSet : public Equippable
{
private:
	EquipmentSetType id_;
	std::string name_;

	std::map<int, std::unique_ptr<EquipmentSetOption>> setOptions_;

public:
	EquipmentSet(const nlohmann::json& json);

	decltype(id_) getId() const;
};

class EquipmentSetOption
{
private:
	EquipmentSetType setId_;
	int piece_;

	std::vector<std::unique_ptr<DamageOption>> damageOptions_;
	std::vector<std::unique_ptr<SkillOption>> skillOptions_;

public:
	EquipmentSetOption(EquipmentSetType setId, const nlohmann::json& json);
	~EquipmentSetOption();

	decltype(piece_) getPiece() const;
};