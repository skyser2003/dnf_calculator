#pragma once

class Equippable
{
private:
	const nlohmann::json json_;

public:
	Equippable(const nlohmann::json& json);
};