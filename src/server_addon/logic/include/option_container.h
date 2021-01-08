#pragma once

class OptionContainer
{
private:
	const nlohmann::json json_;

public:
	OptionContainer(const nlohmann::json& json);
};