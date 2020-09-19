#pragma once
#include <iostream>

using byte = unsigned char;

bool GetBitState(const byte num, int position);
void SetBitState(byte& num, int position, bool value);

template<typename T> constexpr size_t SizeOfBit()
{
	return sizeof(T) * 8;
}