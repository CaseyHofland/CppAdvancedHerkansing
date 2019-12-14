#pragma once

#include <vector>
using namespace std;

template<typename T>
class Queue 
{
public:
	Queue();
	Queue(vector<T>);
	virtual ~Queue();

	void Put(T element);
	T Get();
	const int Size();

private:
	vector<T> queue;
};

template<typename T>
inline Queue<T>::Queue() {}

template<typename T>
inline Queue<T>::Queue(vector<T> vec) : queue(vec) {}

template<typename T>
inline Queue<T>::~Queue() {}

template<typename T>
inline void Queue<T>::Put(T element) 
{
	queue.push_back(element);
}

template<typename T>
inline T Queue<T>::Get() 
{
	return queue.front();
}

template<typename T>
inline const int Queue<T>::Size() 
{
	return queue.size();
}
