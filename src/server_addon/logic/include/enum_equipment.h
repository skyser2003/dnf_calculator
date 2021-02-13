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

enum class EquipmentSetType
{
	// Cloth
	AncientCelebrant,
	CelestialDancer,
	ForgottenMage,

	// Leather
	Veteran,
	RoyalExecutor,
	ShadowyCompanion,

	// Light armor
	Desert,
	Tropica,
	ADP,

	// Heavy armor
	Blacksmith,
	Fettering,
	RuinationHell,

	// Plate armor
	FlowingPath,
	MotherNature,
	CrossroadChoice,

	// Top-Necklace-SubEquipment
	AbyssWatcher,
	DuskTraveler,
	StrangeFate,
	SwallowedAnger,

	// Bottom-Bracelet-MagicStone
	BlackMagic,
	TimeTraveler,
	FatefulShout,
	MadnessFollower,

	// Shoes-Ring-Earrings
	AbyssalSeeker,
	DimensionTraveler,
	FatefulDice,
	ArynTragedy,

	// Accessories
	Elementalist,
	BreakOfDawn,
	AncientConjuration,
	LuckyTriangle,

	// Special equipments
	NormalizingSynchro,
	WarGod,
	TimeWar,
	Annunciation
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

const auto equipmentSetTypeMap = std::map<std::string, EquipmentSetType>{
	{"ancient_celebrant", EquipmentSetType::AncientCelebrant},
	{"celestial_dancer", EquipmentSetType::CelestialDancer},
	{"forgotten_mage", EquipmentSetType::ForgottenMage},

	{"veteran", EquipmentSetType::Veteran},
	{"royal_executor", EquipmentSetType::RoyalExecutor},
	{"shadowy_companion", EquipmentSetType::ShadowyCompanion},

	{"desert", EquipmentSetType::Desert},
	{"tropica", EquipmentSetType::Tropica},
	{"adp", EquipmentSetType::ADP},

	{"blacksmith", EquipmentSetType::Blacksmith},
	{"fettering", EquipmentSetType::Fettering},
	{"ruination_hell", EquipmentSetType::RuinationHell},

	{"flowing_path", EquipmentSetType::FlowingPath},
	{"mother_nature", EquipmentSetType::MotherNature},
	{"crossroad_choice", EquipmentSetType::CrossroadChoice},

	{"abyss_watcher", EquipmentSetType::AbyssWatcher},
	{"dusktraveler", EquipmentSetType::DuskTraveler},
	{"strange_fate", EquipmentSetType::StrangeFate},
	{"swallowed_anger", EquipmentSetType::SwallowedAnger},

	{"black_magic", EquipmentSetType::BlackMagic},
	{"time_traveler", EquipmentSetType::TimeTraveler},
	{"fateful_shout", EquipmentSetType::FatefulShout},
	{"madness_follower", EquipmentSetType::MadnessFollower},

	{"abyssal_seeker", EquipmentSetType::AbyssalSeeker},
	{"dimension_traveler", EquipmentSetType::DimensionTraveler},
	{"fateful_dice", EquipmentSetType::FatefulDice},
	{"aryn_tragedy", EquipmentSetType::ArynTragedy},

	{"elementalist", EquipmentSetType::Elementalist},
	{"break_of_dawn", EquipmentSetType::BreakOfDawn},
	{"ancient_conjuration", EquipmentSetType::AncientConjuration},
	{"lucky_triangle", EquipmentSetType::LuckyTriangle},

	{"normalizing_synchro", EquipmentSetType::NormalizingSynchro},
	{"war_god", EquipmentSetType::WarGod},
	{"time_war", EquipmentSetType::TimeWar},
	{"annunciation", EquipmentSetType::Annunciation}
};