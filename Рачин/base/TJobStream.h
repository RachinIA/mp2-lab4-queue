#pragma once
#include "TQueue.h"
#include "TTask.h"
#include <iostream>

using namespace std;

class TJobStream {
private:
	//TQueue <int> Queue;	//Очередь
	TTask* Task;	//Задачи
	double JobIntens; // Интенсивность потока задач
public:
	TJobStream() :JobIntens(50),Task(){  };
	void Stream(int _QS, int _ImitTacts, int _Intens, int _Cores, int& _TaskInd, int& _Completed, int& _LackOfQSize, int& _LackOfCores, int& _IdleTacts);	//Имитация обслуживания задач процессором
	int GetNewJob(int _Intens); // Попытка создания задачи
};

