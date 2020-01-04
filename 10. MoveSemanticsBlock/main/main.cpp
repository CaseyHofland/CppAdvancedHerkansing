// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Block.h"

/* This test, honestly... just don't. It's for testing out the 'big five'. You can either trust me it works
or perish in semantics hell */

Block makeBlock(int size, std::string name) {
	std::cout << "begin makeBlock: " << std::endl;
	Block newBlock = Block(size, name);
	std::cout << "end makeBlock: " << newBlock << std::endl;
	return newBlock;
}

int main() {
	std::cout << "------" << std::endl;

	Block block1(1024, "block1");
	std::cout << block1 << std::endl;

	std::cout << "------" << std::endl;

	std::cout << "before makeBlock" << std::endl;
	Block block2 = makeBlock(2048, "block2");
	std::cout << "after makeBlock" << std::endl;
	std::cout << block2 << std::endl;

	std::cout << "------" << std::endl;

	Block block3(512, "block3");
	block3 = makeBlock(768, "block3");
	std::cout << block3 << std::endl;

	std::cout << "------" << std::endl;

	// use the assignment-opr
	block3 = std::move(block2);
	std::cout << block3 << std::endl;

	std::cout << "------" << std::endl;

	return 0;
}
