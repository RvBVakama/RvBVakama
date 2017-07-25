#pragma once
#include "BehaviourNode.h"
#include <vector>
using namespace std;

class Composite : public BehaviourNode
{
public:
	vector<BehaviourNode*> children;
};

