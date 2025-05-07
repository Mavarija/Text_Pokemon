#pragma once
#include <string>
using namespace std;

struct SMove
{
	string name;
	int power;

	SMove(const string& _moveName, int _movePower)
	{
		name = _moveName;
		power = _movePower;
	}
};