#pragma once
#include <iostream>
#include <string>

using namespace std; 
class Extra {
public:
    void print(string message, int mode = 0);

    string GetStringInput(string message);

    int RangeNumberInput(int Min, int Max, string message);
    float RangeNumberInput(float Min, float Max, string message);
    double RangeNumberInput(double Min, double Max, string message);
    string RangeInput(int Min, int Max, string message);

};