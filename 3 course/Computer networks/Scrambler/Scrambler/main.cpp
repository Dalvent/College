#include <iostream>
#include <memory>
#include <vector>

#include "ShuttleScrambler/ExampleShuttleScrambRule.h"
#include "4B5B/Scrambler4B5B.h"
#include "BoolScrambler/BoolScrambler.h"

using test_t = long long;

int main()
{
	//auto boolFormula = Formula_t();
	//boolFormula.push_back(std::unique_ptr<IBoolBitScrambler>(new DynamicBoolBitScrambler(1, false)));
	//boolFormula.push_back(std::unique_ptr<IBoolBitScrambler>(new DynamicBoolBitScrambler(2, true)));
	//auto scrambler = BoolScrambler(boolFormula);
	auto scrambler = ShuttleScrambler(new ExampleShuttleScrambRule());

	test_t value = 12345678;
	test_t* p_value = &value;

	std::cout << (int)*p_value << std::endl;
	auto keyResult = scrambler.Scramb(p_value, sizeof(test_t));
	std::cout << (int)*p_value << std::endl;

	scrambler.Unscramb(p_value, sizeof(test_t), keyResult);
	std::cout << (int)*p_value << std::endl;
}