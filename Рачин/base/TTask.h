#pragma once
#include <iostream>


class TTask
{
	int Tacts;	//����� ������
	bool Condition;	//��������� ������
	bool Need; //����� �� �������� ������
	int Cores;	//����� ����
public:
	TTask();
	int GetCores() { return Cores; }		//����� ��������� ����	
	int GetTacts() { return Tacts; }		//����� ��������� ������
	int GetCondition() { return Condition; }	// �������� ��������� ������
	void Initializing(int _Cores, int _Tacts);	
	void ChangeCondition();		//�������� ��������� ����������
	void DecTacts();		
	void DecCores();
	void ChangeNeed(int b);
	bool GetNeed();
	
};

