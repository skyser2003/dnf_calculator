#pragma once

enum class EquipmentType
{
	HeadShoulder,
	Top,
	Bottom,
	Belt,
	Shoes,
	Bracelet,
	Necklace,
	Ring,
	SubEquipment,
	MagicStone,
	Earrings
};

enum class MythicEquipmentPart
{
	Top = static_cast<int>(EquipmentType::Top),
	Bracelet = static_cast<int>(EquipmentType::Bracelet),
	Earrings = static_cast<int>(EquipmentType::Earrings)
};

enum class SirocoEquipmentPart
{
	Bottom = static_cast<int>(EquipmentType::Bottom),
	SubEquipment = static_cast<int>(EquipmentType::SubEquipment),
	Ring = static_cast<int>(EquipmentType::Ring),
};

const auto equipmentTypeMap = std::map<std::string, EquipmentType>{
	{"head_shoulder", EquipmentType::HeadShoulder},
	{"top", EquipmentType::Top},
	{"bottom", EquipmentType::Bottom},
	{"belt", EquipmentType::Belt},
	{"shoes", EquipmentType::Shoes},
	{"bracelet", EquipmentType::Bracelet},
	{"necklace", EquipmentType::Necklace},
	{"ring", EquipmentType::Ring},
	{"sub_equipment", EquipmentType::SubEquipment},
	{"magic_stone", EquipmentType::MagicStone},
	{"earrings", EquipmentType::Earrings}
};