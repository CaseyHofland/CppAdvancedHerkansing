#pragma once

#include <vector>
#include <iterator>
#include <mutex>

// A wrapper class for our vector. Not much to see other than every vector method (minus a few weird ones) 
// wrapped within a mutex lock.
template<typename T>
class ConcurrentVector 
{
private:
	std::vector<T> container;
	std::mutex mutex;

public:
	typedef typename std::vector<T>::vector vector;
	typedef typename std::vector<T>::iterator iterator;
	typedef typename std::vector<T>::const_iterator const_iterator;
	typedef typename std::vector<T>::reverse_iterator reverse_iterator;
	typedef typename std::vector<T>::const_reverse_iterator const_reverse_iterator;
	typedef typename std::vector<T>::size_type size_type;
	typedef typename std::vector<T>::value_type value_type;
	typedef typename std::vector<T>::allocator_type allocator_type;

	ConcurrentVector() {}

	ConcurrentVector(const vector& x)
	{
		this = x;
	}

	ConcurrentVector(const ConcurrentVector& x) 
	{
		this = x;
	}
	
	virtual ~ConcurrentVector() {}

	ConcurrentVector& operator=(const vector& x)
	{
		container = x;
		return this;
	}

	ConcurrentVector& operator=(const ConcurrentVector& x) 
	{
		container = x.container;
		return this;
	}

	iterator begin() 
	{
		mutex.lock();
		auto it = container.begin();
		mutex.unlock();
		return it;
	}

	iterator end() 
	{
		mutex.lock();
		auto it = container.end();
		mutex.unlock();
		return it;
	}

	reverse_iterator rbegin() 
	{
		mutex.lock();
		auto it = container.rbegin();
		mutex.unlock();
		return it;
	}

	reverse_iterator rend() 
	{
		mutex.lock();
		auto it = container.rend();
		mutex.unlock();
		return it;
	}

	const_iterator cbegin() noexcept 
	{
		mutex.lock();
		auto it = container.cbegin();
		mutex.unlock();
		return it;
	}

	const_iterator cend() noexcept
	{
		mutex.lock();
		auto it = container.cend();
		mutex.unlock();
		return it;
	}

	const_reverse_iterator crbegin() noexcept
	{
		mutex.lock();
		auto it = container.crbegin();
		mutex.unlock();
		return it;
	}

	const_reverse_iterator crend() noexcept
	{
		mutex.lock();
		auto it = container.crend();
		mutex.unlock();
		return it;
	}

	size_type size()
	{
		mutex.lock();
		auto size = container.size();
		mutex.unlock();
		return size;
	}

	size_type max_size()
	{
		mutex.lock();
		auto max_size = container.max_size();
		mutex.unlock();
		return max_size;
	}

	void resize(size_type n, value_type val = value_type())
	{
		mutex.lock();
		container.resize(n, val);
		mutex.unlock();
	}

	size_type capacity()
	{
		mutex.lock();
		auto capacity = container.capacity();
		mutex.unlock();
		return capacity;
	}

	bool empty()
	{
		mutex.lock();
		auto empty = container.empty();
		mutex.unlock();
		return empty;
	}

	void reserve(size_type n)
	{
		mutex.lock();
		container.reserve(n);
		mutex.unlock();
	}

	void shrink_to_fit()
	{
		mutex.lock();
		container.shrink_to_fit();
		mutex.unlock();
	}

	value_type operator[](size_type n)
	{
		mutex.lock();
		auto ref = container[n];
		mutex.unlock();
		return ref;
	}

	value_type at(size_type n)
	{
		mutex.lock();
		auto ref = container.at(n);
		mutex.unlock();
		return ref;
	}

	value_type front()
	{
		mutex.lock();
		auto ref = container.front();
		mutex.unlock();
		return ref;
	}

	value_type back()
	{
		mutex.lock();
		auto ref = container.back();
		mutex.unlock();
		return ref;
	}

	value_type* data() noexcept
	{
		mutex.lock();
		auto data = container.data();
		mutex.unlock();
		return data;
	}

	void assign(size_type n, const value_type& val)
	{
		mutex.lock();
		container.assign(n, val);
		mutex.unlock();
	}

	void push_back(const value_type& element)
	{
		mutex.lock();
		container.push_back(element);
		mutex.unlock();
	}

	void pop_back()
	{
		mutex.lock();
		container.pop_back();
		mutex.unlock();
	}

	iterator insert(iterator position, const value_type& val)
	{
		mutex.lock();
		auto it = container.insert(position, val);
		mutex.unlock();
		return it;
	}

	void insert(iterator position, size_type n, const value_type& val)
	{
		mutex.lock();
		container.insert(position, n, val);
		mutex.unlock();
	}

	template <class InputIterator>
	void insert(iterator position, InputIterator first, InputIterator last)
	{
		mutex.lock();
		container.insert(position, first, last);
		mutex.unlock();
	}

	iterator erase(iterator position)
	{
		mutex.lock();
		auto it = container.erase(position);
		mutex.unlock();
		return it;
	}

	iterator erase(iterator first, iterator last)
	{
		mutex.lock();
		auto it = container.erase(first, last);
		mutex.unlock();
		return it;
	}

	void swap(vector& x)
	{
		mutex.lock();
		container.swap(x);
		mutex.unlock();
	}

	void clear()
	{
		mutex.lock();
		container.clear();
		mutex.unlock();
	}

	template <class... Args>
	iterator emplace(const_iterator position, Args&&... args)
	{
		mutex.lock();
		auto it = container.emplace(position, args);
		mutex.unlock();
		return it;
	}

	template <class... Args>
	void emplace_back(Args&&... args)
	{
		mutex.lock();
		container.emplace_back(args);
		mutex.unlock();
	}

	allocator_type get_allocator()
	{
		mutex.lock();
		auto alloc = container.get_allocator();
		mutex.unlock();
		return alloc;
	}

	void print()
	{
		mutex.lock();
		for( const auto& element : container )
			std::cout << element << ", ";
		std::cout << '\n';
		mutex.unlock();
	}
};
