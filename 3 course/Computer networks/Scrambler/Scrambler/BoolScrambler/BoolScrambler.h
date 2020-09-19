#pragma once

#include "BoolBitScrambler.h"
#include <vector>
#include <memory>

//class BoolScaramblerFormula
//{
//public:
//	BoolScaramblerFormula()
//	{
//		std::vector<int> sda = { 1, 2, 3, 4, 5, 6 };
//	}
//private:
//	std::vector<std::unique_ptr<IBoolBitScrambler>> formula;
//};

using Formula_t = std::vector<std::unique_ptr<IBoolBitScrambler>>;

class BoolScrambler
{
public:
	BoolScrambler(Formula_t& formula) : 
		_formula(formula)
	{	
	}

	void Scramb(void* p_startByte, size_t count);
	void Unscramb(void* p_startByte, size_t count);

	byte ScrambByte(const byte num);
	byte UnscrambByte(const byte num);
private:
	Formula_t& _formula;
};