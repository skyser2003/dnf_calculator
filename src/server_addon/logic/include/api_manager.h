#pragma once

namespace Neople
{
	class ApiManager
	{
	public:
		ApiManager(const std::string& apiKey);

	private:
		std::string apiKey;
	};
}