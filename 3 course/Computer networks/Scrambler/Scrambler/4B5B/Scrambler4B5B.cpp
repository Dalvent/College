#include "Scrambler4B5B.h"

short Scrambler4B5B::Scramb(byte value)
{
	byte _4bit1 = value >> 4;
	byte _5bit1 = Get5BFrom4B(_4bit1);

	byte _4bit2 = value & 0b00001111;
	byte _5bit2 = Get5BFrom4B(_4bit2);

	short scrambedNum = (((short)_5bit1) << 5) + _5bit2;
	return scrambedNum;
}

byte Scrambler4B5B::Unscramb(short value)
{
	byte _5bit1 = value >> 5;
	byte _4bit1 = Get4BFrom5B(_5bit1);

	byte _5bit2 = value & 0b0000000000011111;
	byte _4bit2 = Get4BFrom5B(_5bit2);

	return (_4bit1 << 4) + _4bit2;
}

byte Scrambler4B5B::Get5BFrom4B(byte num)
{
	switch (num)
	{
	case 0b00000000: return 0b00011110;
	case 0b00000001: return	0b00001001;
	case 0b00000010: return 0b00010100;
	case 0b00000011: return 0b00010101;
	case 0b00000100: return 0b00001010;
	case 0b00000101: return 0b00001011;
	case 0b00000110: return 0b00001110;
	case 0b00000111: return 0b00001111;
	case 0b00001000: return 0b00010010;
	case 0b00001001: return 0b00010011;
	case 0b00001010: return 0b00010110;
	case 0b00001011: return 0b00010111;
	case 0b00001100: return 0b00011010;
	case 0b00001101: return 0b00011011;
	case 0b00001110: return 0b00011100;
	case 0b00001111: return 0b00011101;
	default: throw;
	}
}

byte Scrambler4B5B::Get4BFrom5B(byte num)
{
	switch (num)
	{
	case 0b00011110: return 0b00000000;
	case 0b00001001: return	0b00000001;
	case 0b00010100: return 0b00000010;
	case 0b00010101: return 0b00000011;
	case 0b00001010: return 0b00000100;
	case 0b00001011: return 0b00000101;
	case 0b00001110: return 0b00000110;
	case 0b00001111: return 0b00000111;
	case 0b00010010: return 0b00001000;
	case 0b00010011: return 0b00001001;
	case 0b00010110: return 0b00001010;
	case 0b00010111: return 0b00001011;
	case 0b00011010: return 0b00001100;
	case 0b00011011: return 0b00001101;
	case 0b00011100: return 0b00001110;
	case 0b00011101: return 0b00001111;
	default: throw;
	}
}