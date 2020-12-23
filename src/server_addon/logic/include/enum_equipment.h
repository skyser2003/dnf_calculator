#pragma once

enum class EquipmentPart
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
	Top = static_cast<int>(EquipmentPart::Top),
	Bracelet = static_cast<int>(EquipmentPart::Bracelet),
	Earrings = static_cast<int>(EquipmentPart::Earrings)
};

enum class SirocoEquipmentPart
{
	Bottom = static_cast<int>(EquipmentPart::Bottom),
	SubEquipment = static_cast<int>(EquipmentPart::SubEquipment),
	Ring = static_cast<int>(EquipmentPart::Ring),
};