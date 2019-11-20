#pragma once
#include <iostream>


class TTask
{
	int Tacts;	//Колво Тактов
	bool Condition;	//Состояние задачи
	bool Need; //Нужно ли заносить задачу
	int Cores;	//Колво ядер
public:
	TTask();
	int GetCores() { return Cores; }		//Колво требуемых ядер	
	int GetTacts() { return Tacts; }		//Колво требуемых тактов
	int GetCondition() { return Condition; }	// Получить состояние задачи
	void Initializing(int _Cores, int _Tacts);	
	void ChangeCondition();		//Изменить состояние исполнения
	void DecTacts();		
	void DecCores();
	void ChangeNeed(int b);
	bool GetNeed();
	
};

