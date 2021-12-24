#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <random>

using namespace std;

template <class T>
class Block {
private:
	T data;
	string previous;
	string hash;
public:
	Block(T data, string prev);
	bool IsValidHash(string s);
	string CreateHash();
	string GetHash();
	T GetData();
	string GetPrevious();
};

template <class T>
Block<T>::Block(T d, string prev) {
	data = d;
	previous = prev;
	hash = CreateHash();
}

template <class T>
bool Block<T>::IsValidHash(string s) {
	return s.find("000") == 0;
}

template <class T>
string Block<T>::CreateHash() {
	string s;
	bool valid = false;
	while (!IsValidHash(s)) {
		int length = 64;
		auto randchar = []() -> char
		{
			const char charset[] =
				"0123456789"
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				"abcdefghijklmnopqrstuvwxyz";
			const size_t max_index = (sizeof(charset) - 1);
			return charset[rand() % max_index];
		};
		string str(length, 0);
		generate_n(str.begin(), length, randchar);
		s = str;
	}
	return s;
}

template <class T>
string Block<T>::GetHash() {
	return hash;
}

template <class T>
T Block<T>::GetData() {
	return data;
}

template <class T>
string Block<T>::GetPrevious() {
	return previous;
}
