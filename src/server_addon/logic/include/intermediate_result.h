#pragma once

class DamageOption;
class SkillOption;

class Weapon;
class Equipment;
class EquipmentSet;

class IntermediateResult
{
private:
	std::vector<std::shared_ptr<DamageOption>> damageOptions;
	std::vector<std::shared_ptr<SkillOption>> skillOptions;

	std::vector<std::shared_ptr<IntermediateResult>> interResults;

public:
	void add(std::shared_ptr<Weapon>& weapon);
	void add(std::shared_ptr<Equipment>& equipment);
	void add(std::shared_ptr<EquipmentSet>& equipmentSet);
};