#include "TJobStream.h"
#include <time.h>

void TJobStream::Stream(int _QS, int _ImitTacts, int _Intens, int _Cores, int& _TaskInd, int& _Completed, int& _LackOfQSize, int& _LackOfCores, int& _IdleTacts)
{
	_TaskInd = 0;
	int tmp;
	int CoreCompleting = 0;
	TQueue <int> Queue(_QS);
	JobIntens = _Intens;
	Task = new TTask[_ImitTacts];
	for (int i = 1; i < _ImitTacts; i++)
	{
		if (GetNewJob(_Intens))
		{
			
			if (!Queue.IsFull())
			{
				_TaskInd++;
				Task[_TaskInd].Initializing(_Cores, _ImitTacts);
				if (Task[_TaskInd].GetCores() > _Cores)
				{
					_LackOfCores++;
				}
				else
				{
					Queue.Put(_TaskInd);
				}
			}
			else
			{
				_LackOfQSize++;
			}
		}
		if ((!Queue.IsEmpty()) || (CoreCompleting != 0))
		{
			if (!Queue.IsEmpty()) {
				if (Task[Queue.GetHead()].GetCores() <= _Cores - CoreCompleting)
				{
					tmp = Queue.Get();
					CoreCompleting += Task[tmp].GetCores();
					Task[tmp].ChangeCondition();
				}
				
			}
			if (CoreCompleting != 0) {
				for (int j = 1; j < _ImitTacts; j++)
					if (Task[j].GetCondition() == 1)
					{
						Task[j].DecTacts();
						if (Task[j].GetTacts() <= 0)
						{
							CoreCompleting -= Task[j].GetCores();
							Task[j].ChangeCondition();
							_Completed++;
						}
					}
			}
		}
		else
		if (CoreCompleting == 0)
		{
			_IdleTacts++;
		}

	}
}

int TJobStream::GetNewJob(int _Intens)
{
	if (rand() % 100 < _Intens)
		return 1;
	else
		return 0;
}
