#pragma once

class SwappableOption
{
private:
	DamageOptionType type_;
	float defaultValue_;
	float maxValue_;

public:
	SwappableOption(const nlohmann::json& json);
};