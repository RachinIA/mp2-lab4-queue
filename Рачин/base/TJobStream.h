#pragma once
#include "TQueue.h"
#include "TTask.h"
#include <iostream>

using namespace std;

class TJobStream {
private:
	//TQueue <int> Queue;	//�������
	TTask* Task;	//������
	double JobIntens; // ������������� ������ �����
public:
	TJobStream() :JobIntens(50),Task(){  };
	void Stream(int _QS, int _ImitTacts, int _Intens, int _Cores, int& _TaskInd, int& _Completed, int& _LackOfQSize, int& _LackOfCores, int& _IdleTacts);	//�������� ������������ ����� �����������
	int GetNewJob(int _Intens); // ������� �������� ������
};

