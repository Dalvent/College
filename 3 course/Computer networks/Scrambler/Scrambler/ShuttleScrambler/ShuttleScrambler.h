#pragma once

#include "Base.h"
#include <utility>
#include <memory>

enum class ScrambRuleState
{
	Alpha, Beta
};

class ShuttleScrambRule
{
public:
	ShuttleScrambRule() {}

	ScrambRuleState GetScramblerState() { return _state; }
	void SetScramblerState(ScrambRuleState state) { _state = state; }

	virtual bool GetScrambBitStatus(bool bit) = 0;
	virtual bool GetUnscrambBitStatus(bool bit) = 0;
protected:
	ScrambRuleState _state = ScrambRuleState::Alpha;
};

class ShuttleScrambler
{
public:
	ShuttleScrambler(ShuttleScrambRule* rule)
	{
		u_rule.reset(rule);
	}
public:
	ScrambRuleState Scramb(void* p_startByte, const size_t size);
	void Unscramb(void* p_startByte, const size_t size, const ScrambRuleState state);

	std::pair<byte, ScrambRuleState> ScrambByte(const byte value, ScrambRuleState startState = ScrambRuleState::Alpha);
	std::pair<byte, ScrambRuleState> UnscrambByte(const byte value, const ScrambRuleState state);
private:
	void ScrambBitOnPosition(byte& num, int position);
	void UnscrambBitOnPosition(byte& num, int position);
private:
	std::unique_ptr<ShuttleScrambRule> u_rule;
};