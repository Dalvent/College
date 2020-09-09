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
	ShuttleScrambRule() = default;

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
	std::pair<byte, ScrambRuleState> Scramb(const byte value);
	byte Unscramb(const byte value, const ScrambRuleState state);
private:
	void ScrambBitOnPosition(byte& num, int position);
	void UnscrambBitOnPosition(byte& num, int position);

	bool GetBitState(const byte num, int position);
	void SetBitState(byte& num, int position, bool value);
private:
	std::unique_ptr<ShuttleScrambRule> u_rule;
};
/*{
		switch (state)
		{
		case ScramblerState::Alpha:
			if (bit)
			{
				state = ScramblerState::Beta;
				return true;
			}
			else
			{
				return false;
			}
		case ScramblerState::Beta:
		{
			if (bit)
			{
				return false;
			}
			else
			{
				state = ScramblerState::Alpha;
				return true;
			}
		}
		default:
			throw;
		};
	}*/
/*
	{
		switch (state)
		{
		case ScramblerState::Alpha:
			if (bit)
			{
				state = ScramblerState::Beta;
				return false;
			}
			else
			{
				return false;
			}
		case ScramblerState::Beta:
		{
			if (bit)
			{
				state = ScramblerState::Alpha;
				return true;
			}
			else
			{
				return true;
			}
		}
		default:
			throw;
		};
	}*/