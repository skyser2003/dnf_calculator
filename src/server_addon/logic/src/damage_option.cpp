#include "stdafx.h"
#include "damage_option.h"

DamageOption::DamageOption(const nlohmann::json& json)
{
	cout << json.dump() << endl;
	this->type = damageTypeMap.at(json["type"].get<std::string>());
	this->value = json["value"].get<decltype(this->value)>();
}
