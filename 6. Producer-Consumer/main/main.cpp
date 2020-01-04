#include <queue>
#include <thread>
#include <iostream>
#include <condition_variable>

// A test for mutex flags

int counter = 0;
std::queue<int> goods;

std::condition_variable flag;
std::mutex mutex;

// Produce the goods and give a notification when it's done
void producer() {
	for( int i = 0; i < 500; ++i )
	{
		goods.push(i);
		counter++;
	}

	flag.notify_one();
}

// Get the goods when the are in place
void consumer() {
	std::unique_lock<std::mutex> lock(mutex);
	flag.wait(lock);

	while( !goods.empty() )
	{
		goods.pop();
		counter--;
	}
}

int main() {
	std::thread producerThread(producer);
	std::thread consumerThread(consumer);

	producerThread.join();
	consumerThread.join();

	std::cout << "Net: " << counter << " " << goods.size() << " " << std::endl;
}