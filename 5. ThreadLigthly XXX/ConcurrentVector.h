#pragma once

#include <vector>
#include <mutex>
using namespace std;

template<typename T>
class ConcurrentVector 
{
public:
	virtual ~ConcurrentVector();

	void push_back(T element);
	void push_back(vector<T> elements);
	void print() const;

private:
	vector<T> vector;
	mutex mutex;
};

template<typename T>
inline ConcurrentVector<T>::~ConcurrentVector() {}

template<typename T>
inline void ConcurrentVector<T>::push_back(T element) 
{
	lock_guard<std::mutex> guard(mutex);
	mutex.lock();
	vector.push_back(element);
	mutex.unlock();
}

template<typename T>
inline void ConcurrentVector<T>::push_back(std::vector<T> elements) 
{
	for(const T& element : elements )
		push_back(element);
}

template<typename T>
inline void ConcurrentVector<T>::print() const 
{
	for( const auto& element : vector )
		cout << element << ", ";
	cout << '\n';
}
