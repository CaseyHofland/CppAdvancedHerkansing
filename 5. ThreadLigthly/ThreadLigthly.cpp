// ThreadLigthly.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <thread>
#include "ConcurrentVector.h"
using namespace std;

// This is a test for creating a 'Concurrent Vector', or a thread-safe vector. There are probably ways to
// break it, but I'll leave that as an exercise for you.

int main()
{
	ConcurrentVector<int> concurrentVector;

	thread thread1([&]
		{
			concurrentVector.push_back(100);
		}
	);

	thread thread2([&]
		{
			concurrentVector.push_back(200);
		}
	);

	thread1.detach();
	thread2.detach();
	
	concurrentVector.print();

	return 0;
}
