#pragma once

#include "option_container.h"

class Equipment : public SwappableOptionContainer
{
private:
	int id_;
	std::string stringId_;
	std::string name_;
	EquipmentType type_;
	std::string setId_;
	bool isMythic_;

public:
	Equipment(int id, const nlohmann::json& json);
	~Equipment();

	decltype(stringId_) getStringId() const;
	decltype(name_) getName() const;
	decltype(type_) getType() const;
};