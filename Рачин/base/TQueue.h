#pragma once
#ifndef __TQueue_H__
#define __TQueue_H__

using namespace std;
const int MaxMemSize = 200;

template <class T>
class TQueue{
	T* pMem;		// ��������� �� ������ ���������� ��� ���������� ������
public:
	int MemSize;	// ������ ���������� ������
	int DataCount;	// ���������� ����������� � ������� ��������
	int Tail; // ������ ����� �������
	int Head; // ������ ������ �������
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
	void Put(const T value);		// ��������� ������� � �������
	T Get(void);  // ������� ��������
	bool IsEmpty();	// �������� �������
	bool IsFull();	//�������� ������������
	int GetNextIndex(int index); // �������� ��������� ������
	T GetByInd(int index); // �������� ������� �� �������
	T GetHead(); // �������� ��������� �������
	T GetTail(); // �������� �������� �������
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

