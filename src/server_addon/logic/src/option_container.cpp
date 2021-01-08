#include "stdafx.h"
#include "option_container.h"

OptionContainer::OptionContainer(const nlohmann::json& json) : json_(json)
{
}