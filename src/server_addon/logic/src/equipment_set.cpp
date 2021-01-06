#include "stdafx.h"
#include "equipment_set.h"

#include "damage_option.h"
#include "skill_option.h"

EquipmentSet::EquipmentSet(const nlohmann::json& json) : Equippable(json)
{
	id_ = equipmentSetTypeMap.at(json["id"].get<std::string>());
	this->name_ = "";

	auto& setOptions = json["set_options"];

	for (auto& it : setOptions)
	{
		auto setOption = std::make_unique<EquipmentSetOption>(id_, it);
		auto piece = setOption->getPiece();

		this->setOptions_.emplace(piece, std::move(setOption));
	}
}

decltype(EquipmentSet::id_) EquipmentSet::getId() const
{
	return id_;
}

EquipmentSetOption::EquipmentSetOption(EquipmentSetType setId, const nlohmann::json& json) : setId_(setId)
{
	this->piece_ = json["piece"].get<int>();

	const auto& damageOptionsIt = json.find("damage_options");
	const auto& skillOptionsIt = json.find("skill_options");

	if (damageOptionsIt != json.end())
	{
		for (const auto& it : damageOptionsIt.value())
		{
			this->damageOptions_.push_back(std::make_unique<DamageOption>(it));
		}
	}

	if (skillOptionsIt != json.end())
	{
		for (const auto& it : skillOptionsIt.value())
		{
			this->skillOptions_.push_back(std::make_unique<SkillOption>(it));
		}
	}
}

EquipmentSetOption::~EquipmentSetOption()
{
}

decltype(EquipmentSetOption::piece_) EquipmentSetOption::getPiece() const
{
	return piece_;
}
