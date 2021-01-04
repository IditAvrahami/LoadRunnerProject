#pragma once
#include "Present.h"



class BadPresent : public Present
{
public:
	BadPresent();
	virtual ~BadPresent()=default;
	virtual void character();

private:

};
