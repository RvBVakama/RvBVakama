#pragma once
#include "Composite.h"

class Selector : public Composite
{
public:
	EBehaviourResult Execute()
	{
		for (unsigned int i = 0; i < children.size(); ++i)
		{
			if (children[i]->Execute() == EBEHAVIOUR_SUCCESS)
			{
				return EBEHAVIOUR_SUCCESS;
			}
		}

		return EBEHAVIOUR_FAILURE;
	}
};

