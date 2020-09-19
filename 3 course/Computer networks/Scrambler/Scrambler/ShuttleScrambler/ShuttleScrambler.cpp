#include "ShuttleScrambler.h"

ScrambRuleState ShuttleScrambler::Scramb(void* p_startByte, const size_t size)
{
	byte* p_currentByte = (byte*)p_startByte;
	ScrambRuleState currentRuleState = ScrambRuleState::Alpha;

	for (int i = 0; i < size; i++)
	{
		auto scrambResult = ScrambByte(p_currentByte[i], currentRuleState);
		p_currentByte[i] = scrambResult.first;
		currentRuleState = scrambResult.second;
	}

	return currentRuleState;
}

void ShuttleScrambler::Unscramb(void* p_startByte, const size_t size, const ScrambRuleState state)
{
	byte* p_currentByte = (byte*)p_startByte;
	ScrambRuleState currentRuleState = state;

	for (int i = size - 1; i >= 0; i--)
	{
		auto scrambResult = UnscrambByte(p_currentByte[i], currentRuleState);
		p_currentByte[i] = scrambResult.first;
		currentRuleState = scrambResult.second;
	}
}

std::pair<byte, ScrambRuleState> ShuttleScrambler::ScrambByte(const byte value, ScrambRuleState startState)
{
	byte scramblValue = value;
	u_rule->SetScramblerState(startState);

	for (int i = 7; i >= 0; i--)
	{
		ScrambBitOnPosition(scramblValue, i);
	}

	return { scramblValue, u_rule->GetScramblerState() };
}
std::pair<byte, ScrambRuleState> ShuttleScrambler::UnscrambByte(const byte value, const ScrambRuleState state)
{
	byte unscramblValue = value;
	u_rule->SetScramblerState(state);

	for (int i = 0; i < 8; i++)
	{
		UnscrambBitOnPosition(unscramblValue, i);
	}

	return { unscramblValue, u_rule->GetScramblerState() };
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