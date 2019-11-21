#pragma once
#ifndef __TQueue_H__
#define __TQueue_H__

using namespace std;
const int MaxMemSize = 200;

template <class T>
class TQueue{
	T* pMem;		// указатель на память выделенную для кольцевого буфера
public:
	int MemSize;	// размер выделенной памяти
	int DataCount;	// количество запомненных в очереди значений
	int Tail; // индекс конца очереди
	int Head; // индекс начала очереди
public:
	TQueue(int _size = MaxMemSize)
	{
		MemSize = _size;
		if ((_size < 1) || (_size > MaxMemSize))
			throw ("Wrong Size");

		pMem = new T[MemSize];
		DataCount = 0;
		Tail = 0;
		Head = MemSize - 1;

	};
	~TQueue() { delete[] pMem; }
	void Put(const T value);		// поместить элемент в очередь
	T Get(void);  // извлечь значение
	bool IsEmpty();	// проверка пустоты
	bool IsFull();	//проверка переполнения
	int GetNextIndex(int index); // получить следующий индекс
	T GetByInd(int index); // получить элемент по индексу
	T GetHead(); // получить начальный элемент
	T GetTail(); // получить конечный элемент
};

template<class T>
inline void TQueue<T>::Put(T value)
{
	if (IsFull()) throw "Queue Full";
	Head = GetNextIndex(Head);
	pMem[Head] = value;
	++DataCount;
}

template<class T>
inline T TQueue<T>::Get(void)
{
	if (IsEmpty()) throw("Queue exhausted");
			T tmp = pMem[Tail];
			Tail = GetNextIndex(Tail);
			DataCount--;
			return tmp;
			
}

template<class T>
inline bool TQueue<T>::IsEmpty()
{
	if (DataCount == 0)return true;
	else return false;
}

template<class T>
inline bool TQueue<T>::IsFull()
{
	if (DataCount == MemSize) return true;
	else return false;
}

template<class T>
inline int TQueue<T>::GetNextIndex(int index)
{
	return (index+1) % MemSize;
}
//template<class T>
//inline T TQueue<T>::GetByInd(int index)
//{
//	return pMem[index];
//}
template<class T>
inline T TQueue<T>::GetHead()
{
	if (IsEmpty()) throw("Empty");
	return pMem[Head];
}
template<class T>
inline T TQueue<T>::GetTail()
{
	if (IsEmpty()) throw "Empty";
	return pMem[Tail];
}
#endif

