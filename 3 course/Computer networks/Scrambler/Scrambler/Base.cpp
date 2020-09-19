#include "Base.h"

bool GetBitState(const byte num, int position)
{
	byte pattern = 1 << position;
	return num & pattern;
}

void SetBitState(byte& num, int position, bool value)
{
	byte pattern = 1 << position;
	// If need to "On" bit.
	if (value)
	{
		num |= pattern;
	}
	// If need to "Off" bit.
	else
	{
		num &= ~pattern;
	}
}
