#include "ShuttleScrambler.h"

std::pair<byte, ScrambRuleState> ShuttleScrambler::Scramb(const byte value)
{
	byte scramblValue = value;
	u_rule->SetScramblerState(ScrambRuleState::Alpha);

	for (int i = 7; i >= 0; i--)
	{
		ScrambBitOnPosition(scramblValue, i);
	}

	return { scramblValue, u_rule->GetScramblerState() } ;
}
byte ShuttleScrambler::Unscramb(const byte value, const ScrambRuleState state)
{
	byte unscramblValue = value;
	u_rule->SetScramblerState(state);

	for (int i = 0; i < 8; i++)
	{
		UnscrambBitOnPosition(unscramblValue, i);
	}

	return unscramblValue;
}
void ShuttleScrambler::ScrambBitOnPosition(byte& num, int position)
{
	// Get bit on position state.
	bool bitValue = GetBitState(num, position);

	bool newBitValue = u_rule->GetScrambBitStatus(bitValue);
	SetBitState(num, position, newBitValue);
}

void ShuttleScrambler::UnscrambBitOnPosition(byte& num, int position)
{
	// Get bit on position state.
	bool bitValue = GetBitState(num, position);

	bool newBitValue = u_rule->GetUnscrambBitStatus(bitValue);
	SetBitState(num, position, newBitValue);
}

bool ShuttleScrambler::GetBitState(const byte num, int position)
{
	byte pattern = 1 << position;

	return num & pattern;
}

void ShuttleScrambler::SetBitState(byte& num, int position, bool value)
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


//1100 | 0001 -> 1101 ÄËß ÂÊËŞ×ÅÍÈß
//1101 & ~0001 -> 1100 ÄËß ÂÛÊËŞ×ÅÍÈß
