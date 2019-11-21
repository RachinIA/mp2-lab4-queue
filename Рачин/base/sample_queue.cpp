#include <iostream>
#include <string>
#include "TJobStream.h"
#include "TQueue.h"

using namespace std;

int main()
{
  setlocale(LC_ALL, "Russian");
  int QueueSize, ImitTacts, Cores, AmountOfTasks = 0, Completed = 0, LackOfQueue = 0, LackOfCores = 0, IdleTacts = 0;
  int Intense;
  cout << "Количество тактов имитации:";
  cin >> ImitTacts;
  cout << "Размер очереди:";
  cin >> QueueSize;
  cout << "Интенсивность потока задач(до 100 %):";
  cin >> Intense;
  if (Intense > 100 || Intense < 0) throw "Wrong Intense";
  cout << "Количество ядер процессора:";
  cin >> Cores;
  cout << "[----------------Completing...----------------]" << endl;
  //TQueue <int> Q(QueueSize);
  //cout << Q.Be << " " << Q.En << endl << Q.DataCount << " " << Q.MemSize << endl;
  //Q.Put(2);
  //cout << Q.Be << " " << Q.En << endl << Q.DataCount << " " << Q.MemSize << endl;
  //cout << Q.Get()<<endl;
  //cout << Q.Be << " " << Q.En << endl << Q.DataCount << " " << Q.MemSize << endl;

  TJobStream T;
  T.Stream(QueueSize, ImitTacts, Intense, Cores, AmountOfTasks, Completed, LackOfQueue, LackOfCores, IdleTacts);
  cout << "Количество задач:" << AmountOfTasks << endl;
  cout << "Количество выполненных задач: " << Completed << endl;
  cout << "Количество раз невыполнения из-за очереди: " << LackOfQueue << endl;
  cout << "Количество невыполнения из-за нехватки ядер: " << LackOfCores << endl;
  cout << "Количество тактов простоя: " << IdleTacts << endl;
  double PercentOfIdle = IdleTacts*100 / ImitTacts;
  cout << "Процент простоя равен - " << PercentOfIdle << "%" << endl;
  
  return 0;
}
