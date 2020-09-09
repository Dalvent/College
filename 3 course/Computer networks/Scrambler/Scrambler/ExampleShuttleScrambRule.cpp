#include "ExampleShuttleScrambRule.h"

bool ExampleShuttleScrambRule::GetScrambBitStatus(bool bit)
{
	switch (_state)
	{
	case ScrambRuleState::Alpha:
		if (bit)
		{
			_state = ScrambRuleState::Beta;
			return true;
		}
		else
		{
			return false;
		}
	case ScrambRuleState::Beta:
	{
		if (bit)
		{
			return false;
		}
		else
		{
			_state = ScrambRuleState::Alpha;
			return true;
		}
	}
	default:
		throw;
	};
}

bool ExampleShuttleScrambRule::GetUnscrambBitStatus(bool bit)
{
	switch (_state)
	{
	case ScrambRuleState::Alpha:
		if (bit)
		{
			_state = ScrambRuleState::Beta;
			return false;
		}
		else
		{
			return false;
		}
	case ScrambRuleState::Beta:
	{
		if (bit)
		{
			SetScramblerState(ScrambRuleState::Alpha);
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
}
