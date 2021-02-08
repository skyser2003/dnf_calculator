#include "stdafx.h"
#include "extra_option.h"

TalismanExtraOption::TalismanExtraOption(ExtraOptionType type, const nlohmann::json& json) : type_(type)
{
	slot_ = json["slot"].get<decltype(slot_)>();
	value_ = json["value"].get<decltype(value_)>();
}
