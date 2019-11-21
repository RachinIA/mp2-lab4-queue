#include "TTask.h"
#include <ctime>
using namespace std;

TTask::TTask()
{
	Cores = 0;
	Tacts = 0;
	Condition = 0;
	Need = false;
}


void TTask::Initializing(int _Cores, int _Tacts)
{
	if (_Cores <= 0) throw "False";
	if (_Tacts <= 0) throw "False";
	Cores = rand() % (_Cores + 5) + 1;
	Tacts = (rand() % 5 + 1);
	Condition = 0;
}

void TTask::ChangeCondition()
{
	if (Condition == 0) Condition = 1;
	else Condition = 0;
}

void TTask::DecTacts()
{
	if (Tacts - 1 < 0) throw "Error";
	Tacts--;
	
}

void TTask::DecCores()
{
	if (Cores - 1 < 0) throw "Error";
	Cores--;

}

void TTask::ChangeNeed(int b)
{
	Need = b;
}

bool TTask::GetNeed()
{
	return Need;
}

