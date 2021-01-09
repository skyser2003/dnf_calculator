#include "stdafx.h"
#include "swappable_option.h"

SwappableOption::SwappableOption(const nlohmann::json& json)
{
	type_ = damageTypeMap.at(json["type"].get<std::string>());
	defaultValue_ = json["value"].get<decltype(defaultValue_)>();
	maxValue_ = defaultValue_ + 8;
}
