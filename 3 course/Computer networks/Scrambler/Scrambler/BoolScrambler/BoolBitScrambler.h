#pragma once

#include "Base.h"

class IBoolBitScrambler
{
public:
	virtual bool CanScrambOnPosition(int position) = 0;
	virtual bool GetScrambBitOnPosition(byte num, int position) = 0;
};

class ConstBoolBitScrambler : public IBoolBitScrambler
{
public: 
	ConstBoolBitScrambler(bool value) : _value(value)
	{
	}

	bool CanScrambOnPosition(int position)
	{
		return true;
	}

	bool GetScrambBitOnPosition(byte num, int position)
	{
		return _value;
	}
public:
	bool _value;
};

class DynamicBoolBitScrambler : public IBoolBitScrambler
{
public:
	DynamicBoolBitScrambler(int positionBack, bool isNegative) :
		_positionBack(positionBack), _isNegative(isNegative)
	{
	}

	bool CanScrambOnPosition(int position)
	{
		return ((GetScrmabledValueSize() - 1 - position) - _positionBack) >= 0;
	}

	bool GetScrambBitOnPosition(byte num, int position)
	{
		bool scrambBit = GetBitState(num, RelativeBackPosition(position));
		
		if (_isNegative)
		{
			scrambBit = !scrambBit;
		}

		return scrambBit;
	}
private:
	int _positionBack;
	bool _isNegative;
private:
	int RelativeBackPosition(int position) { return position + _positionBack; }
	int GetScrmabledValueSize() { return SizeOfBit<byte>(); }
};