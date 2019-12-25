// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Block.h"

Block makeBlock(int size, std::string name) {
	std::cout << "begin makeBlock: " << std::endl;
	Block newBlock = Block(size, name);
	std::cout << "einde makeBlock: " << newBlock << std::endl;
	return newBlock;
}

int main() {
	std::cout << "------" << std::endl;

	Block block1(1024, "block1");
	std::cout << block1 << std::endl;

	std::cout << "------" << std::endl;

	std::cout << "voor makeBlock" << std::endl;
	Block block2 = makeBlock(2048, "block2");
	std::cout << "na makeBlock" << std::endl;
	std::cout << block2 << std::endl;

	std::cout << "------" << std::endl;

	Block block3(512, "block3");
	block3 = makeBlock(768, "block3");
	std::cout << block3 << std::endl;

	std::cout << "------" << std::endl;

	// gebruik de assignment-oper
	block3 = std::move(block2);
	std::cout << block3 << std::endl;

	std::cout << "------" << std::endl;

	return 0;
}
