#pragma once

#include "Base.h"
#include <set>

class Scrambler4B5B
{
public:
	short Scramb(byte value);
	byte Unscramb(short value);
private:
	byte Get5BFrom4B(byte num);
	byte Get4BFrom5B(byte num);
};