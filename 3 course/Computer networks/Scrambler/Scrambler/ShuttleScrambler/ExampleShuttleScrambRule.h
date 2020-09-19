#pragma once
#include "ShuttleScrambler.h"

class ExampleShuttleScrambRule : public ShuttleScrambRule
{
public:
	virtual bool GetScrambBitStatus(bool bit) override;
	virtual bool GetUnscrambBitStatus(bool bit) override;
};