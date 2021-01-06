#include "stdafx.h"
#include "swappable_option.h"

SwappableOption::SwappableOption(const nlohmann::json& json)
{
	type_ = damageTypeMap.at(json["type"].get<std::string>());
	defaultValue_ = json["default_value"].get<decltype(defaultValue_)>();
	minValue_ = json["minimum_value"].get<decltype(minValue_)>();
	maxValue_ = json["maximum_value"].get<decltype(maxValue_)>();
}
