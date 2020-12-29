#pragma once

class DamageOption
{
public:
	DamageOption(const nlohmann::json& json);

private:
	DamageOptionType type;
	float value;
};