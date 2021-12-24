// blockchain.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include "Chain.h"

using namespace std;

int main()
{
    
    // STRING IMPLEMENTATION
    
    Chain<string> chain1("Genesis");
    chain1.AddNewBlock("Block One");
    chain1.AddNewBlock("Block Two");
    chain1.AddNewBlock("Block Three");
    chain1.AddNewBlock("Block Four");
    chain1.AddNewBlock("Block Five");
    chain1.AddNewBlock("Block Six");
    chain1.AddNewBlock("Block Seven");
    chain1.AddNewBlock("Block Eight");
    chain1.AddNewBlock("Block Nine");
    chain1.AddNewBlock("Block Ten");  
    chain1.ToString();

    // INTEGER IMPLEMENTATION

    Chain<int> chain2(0);
    chain2.AddNewBlock(1);
    chain2.AddNewBlock(2);
    chain2.AddNewBlock(3);
    chain2.AddNewBlock(4);
    chain2.AddNewBlock(5);
    chain2.AddNewBlock(6);
    chain2.AddNewBlock(7);
    chain2.AddNewBlock(8);
    chain2.AddNewBlock(9);
    chain2.AddNewBlock(10);
    chain2.ToString();

    return 0;
}
