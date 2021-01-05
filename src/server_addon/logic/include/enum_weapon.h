#pragma once

enum class WeaponType
{
	GreatSword,
	Bludgeon,
	ShortSword,
	Katana,
	Lightsabre,

	Gauntlet,
	BoxingGlove,
	Claw,
	Knuckle,
	Tonfa,

	HandCannon,
	Musket,
	Revolver,
	Bowgun,
	AutoGun,

	Spear,
	Pole,
	Staff,
	Rod,
	Broomstick,

	BattleAxe,
	Totem,
	Cross,
	Scythe,
	Rosary,

	Dagger,
	DualBlade,
	Wand,
	ChakraWeapon,

	LongLance,
	Halberd,
	BeamSpear,
	Javelin,

	Odachi,
	Kodachi,
	SquareSword,
	CoreBlade
};

const auto weaponTypeMap = std::map<std::string, WeaponType>{
	{"great_sword", WeaponType::GreatSword},
	{"bludgeon", WeaponType::Bludgeon},
	{"short_sword", WeaponType::ShortSword},
	{"katana", WeaponType::Katana},
	{"lightsabre", WeaponType::Lightsabre},

	{"gauntlet", WeaponType::Gauntlet},
	{"boxing_glove", WeaponType::BoxingGlove},
	{"claw", WeaponType::Claw},
	{"knuckle", WeaponType::Knuckle},
	{"tonfa", WeaponType::Tonfa},

	{"hand_cannon", WeaponType::HandCannon},
	{"musket", WeaponType::Musket},
	{"revolver", WeaponType::Revolver},
	{"bowgun", WeaponType::Bowgun},
	{"auto_gun", WeaponType::AutoGun},

	{"spear", WeaponType::Spear},
	{"pole", WeaponType::Pole},
	{"staff", WeaponType::Staff},
	{"rod", WeaponType::Rod},
	{"broomstick", WeaponType::Broomstick},

	{"battle_axe", WeaponType::BattleAxe},
	{"totem", WeaponType::Totem},
	{"cross", WeaponType::Cross},
	{"scythe", WeaponType::Scythe},
	{"rosary", WeaponType::Rosary},

	{"dagger", WeaponType::Dagger},
	{"dual_blade", WeaponType::DualBlade},
	{"wand", WeaponType::Wand},
	{"chakra_weapon", WeaponType::ChakraWeapon},

	{"long_lance", WeaponType::LongLance},
	{"halberd", WeaponType::Halberd},
	{"beam_spear", WeaponType::BeamSpear},
	{"javelin", WeaponType::Javelin},

	{"odachi", WeaponType::Odachi},
	{"kodachi", WeaponType::Kodachi},
	{"square_sword", WeaponType::SquareSword},
	{"core_blade", WeaponType::CoreBlade}
};