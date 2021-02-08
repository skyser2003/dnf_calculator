#pragma once

class ExtraOption
{
private:
public:
};

class TalismanExtraOption
{
private:
	ExtraOptionType type_;

	int slot_;
	int value_;

public:
	TalismanExtraOption(ExtraOptionType type, const nlohmann::json& json);
};