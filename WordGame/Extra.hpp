#pragma once
#include <iostream>
#include <string>

using namespace std; 
class Extra {
public:
    void print(string message, int mode = 0);

    string GetStringInput(string message);

    int RangeIntInput(int Min, int Max, string message);
};