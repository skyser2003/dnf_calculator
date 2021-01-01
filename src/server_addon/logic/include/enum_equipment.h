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