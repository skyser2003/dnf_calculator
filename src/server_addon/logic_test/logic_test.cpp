#include "pch.h"
#include "CppUnitTest.h"

#include "main.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace logictest
{
	TEST_CLASS(logictest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Main main("../../../../server/data");
			Logger::WriteMessage(main.getEquipmentJson().dump().c_str());
		}
	};
}
