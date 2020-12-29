#pragma once

class DamageOption;
class SkillOption;

class EquipmentSetOption;

class EquipmentSet
{
public:
	EquipmentSet(const nlohmann::json& json);

private:
	std::string id_;
	std::string name_;

	std::map<int, std::unique_ptr<EquipmentSetOption>> setOptions_;
};

class EquipmentSetOption
{
private:
	int piece_;
	std::vector<std::unique_ptr<DamageOption>> damageOptions_;
	std::vector<std::unique_ptr<SkillOption>> skillOptions_;

public:
	EquipmentSetOption(const nlohmann::json& json);
	~EquipmentSetOption();

	decltype(piece_) getPiece() const;
};