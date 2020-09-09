#include <iostream>
#include "ShuttleScrambler.h"
#include "ExampleShuttleScrambRule.h"

int main()
{
	auto scrambler = ShuttleScrambler(new ExampleShuttleScrambRule());
	
	auto scrambledResult = scrambler.Scramb(128);
	byte scrambledValue = scrambledResult.first;
	ScrambRuleState state = scrambledResult.second;

	std::cout << (int)scrambledValue << std::endl;

	byte originalValue = scrambler.Unscramb(scrambledValue, state);
	
	std::cout << (int)originalValue << std::endl;
}