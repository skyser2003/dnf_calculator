#include "stdafx.h"
#include "equipment_set.h"

#include "damage_option.h"
#include "skill_option.h"

EquipmentSet::EquipmentSet(const nlohmann::json& json)
{
	for (auto& elem : json)
	{
		this->id_ = elem["id"].get<std::string>();
		this->name_ = elem["name"].get<std::string>();

		auto& setOptions = elem["set_options"];

		for (auto& it : setOptions)
		{
			auto setOption = std::make_unique<EquipmentSetOption>(it);
			auto piece = setOption->getPiece();

			this->setOptions_.emplace(piece, std::move(setOption));
		}
	}
}

EquipmentSetOption::EquipmentSetOption(const nlohmann::json& json)
{
	this->piece_ = json["piece"].get<int>();
	auto& jsonDamageOptions = json["damage_options"];
	auto& jsonSkillOptions = json["skill_options"];

	for (const auto& it : jsonDamageOptions)
	{
		this->damageOptions_.push_back(std::make_unique<DamageOption>(it));
	}

	for (const auto& it : jsonSkillOptions)
	{
		this->skillOptions_.push_back(std::make_unique<SkillOption>(it));
	}
}

EquipmentSetOption::~EquipmentSetOption()
{
}

decltype(EquipmentSetOption::piece_) EquipmentSetOption::getPiece() const
{
	return piece_;
}
