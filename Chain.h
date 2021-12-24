#pragma once
#include <iostream>
#include <vector>
#include "Block.h"

using namespace std;

template <class T>
class Chain {
private:
	vector<Block<T>> blocks;
public:
	Chain(T startdata);
	void SetStartBlock(T data);
	string GetLastHash();
	void AddNewBlock(T data);
	vector<Block<T>> GetBlocks();
	void ToString();
};

template <class T>
Chain<T>::Chain(T startData) {
	SetStartBlock(startData);
}

template <class T>
void Chain<T>::SetStartBlock(T data) {
	string previous(64, '0');
	Block<T> newBlock = Block<T>(data, previous);
	blocks.push_back(newBlock);
}

template <class T>
string Chain<T>::GetLastHash() {
	Block<T> lastBlock = blocks[blocks.size() - 1];
	string lastHash = lastBlock.GetHash();
	return lastHash;
}

template <class T>
void Chain<T>::AddNewBlock(T data) {
	string previous = GetLastHash();
	Block<T> newBlock = Block<T>(data, previous);
	blocks.push_back(newBlock);
}

template <class T>
vector<Block<T>> Chain<T>::GetBlocks() {
	return blocks;
}

template <class T>
void Chain<T>::ToString() {
	for (auto block : GetBlocks()) {
		cout << left << setw(10) << "Mined: " << left << setw(15) << block.GetData() << right << setw(20) << block.GetPrevious() << endl;
	}
}
