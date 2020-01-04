#pragma once

//#define MOVESEMANTICS

#include <string>
#include <ostream>

class Block {
public:
	Block(int size, std::string name);
	// 'big four'
	virtual ~Block() noexcept; // destrucor
	Block(const Block& other); // copy-constructor
	Block& operator=(const Block& other); // assignment-operator
	Block& operator=(Block&& other) noexcept; // move-assignment-operator

#ifdef MOVESEMANTICS
	// needed for de 'big five'
	Block(Block&& other) noexcept; // move-constructor
	//TODO: implement the move-assignment operator
#endif

private:
	std::string name;
	int* data;
	int size;

	friend std::ostream& operator<<(std::ostream& os, const Block& block);
};
