#include "BoolScrambler.h"

void BoolScrambler::Scramb(void* p_startByte, size_t count)
{
	byte* p_currentByte = (byte*)p_startByte;

	for (int i = 0; i < count; i++)
	{
		p_currentByte[i] = ScrambByte(p_currentByte[i]);
	}
}

void BoolScrambler::Unscramb(void* p_startByte, size_t count)
{
	byte* p_currentByte = (byte*)p_startByte;

	for (int i = 0; i < count; i++)
	{
		p_currentByte[i] = UnscrambByte(p_currentByte[i]);
	}
}

byte BoolScrambler::ScrambByte(const byte num)
{
	byte scramblValue = num;

	for (int bitIndex = (SizeOfBit<byte>() - 1); bitIndex >= 0; bitIndex--)
	{
		bool bitValue = GetBitState(scramblValue, bitIndex);
		for (int formulaOperIndex = 0; formulaOperIndex < _formula.size(); formulaOperIndex++)
		{
			if (_formula[formulaOperIndex]->CanScrambOnPosition(bitIndex))
			{
				bitValue = bitValue xor _formula[formulaOperIndex]->GetScrambBitOnPosition(scramblValue, bitIndex);
			}
		}
		SetBitState(scramblValue, bitIndex, bitValue);
	}
	return scramblValue;
}

byte BoolScrambler::UnscrambByte(const byte num)
{
	byte scramblValue = num;

	for (int bitIndex = 0; bitIndex < SizeOfBit<byte>(); bitIndex++)
	{
		bool bitValue = GetBitState(scramblValue, bitIndex);
		for (int formulaOperIndex = 0; formulaOperIndex < _formula.size(); formulaOperIndex++)
		{
			if (_formula[formulaOperIndex]->CanScrambOnPosition(bitIndex))
			{
				bitValue = bitValue xor _formula[formulaOperIndex]->GetScrambBitOnPosition(scramblValue, bitIndex);
			}
		}
		SetBitState(scramblValue, bitIndex, bitValue);
	}

	return scramblValue;
}
