#include "stdafx.h"
#include "weapon.h"

#include "damage_option.h"
#include "skill_option.h"

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

Weapon::Weapon(int id, const nlohmann::json& json) : Equippable(json), id_(id)
{
	this->stringId_ = json["id"].get<std::string>();
	this->name_ = json["name"].get<std::string>();
	this->type = weaponTypeMap.at(json["type"].get<std::string>());

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

Weapon::~Weapon()
{
}

decltype(Weapon::stringId_) Weapon::getStringId() const
{
	return stringId_;
}

decltype(Weapon::name_) Weapon::getName() const
{
	return name_;
}