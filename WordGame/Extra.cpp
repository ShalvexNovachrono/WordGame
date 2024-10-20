#include "Extra.hpp"

void Extra::print(string message, int mode) {
    if (mode == 0) {
        cout << message << endl;
    }
    else {
        cout << message;
    }
}

string Extra::GetStringInput(string message) {
    print(message, 1);
    string Input;
    getline(cin, Input);
    return Input;
}

int Extra::RangeNumberInput(int Min, int Max, string message) { // this input function will only return number when it meets the requirement
    int thisIntInput;

    while (true) {
        try {
            string thisStringInput = GetStringInput(message);
            thisIntInput = stoi(thisStringInput);
            if (thisIntInput >= Min && thisIntInput <= Max) {
                return thisIntInput;
            }
            else {
                print("Please enter a valid number bewteen " + to_string(Min) + " - " + to_string(Max));
            }
        }
        catch (exception e) {
            print("Invalid input. Please enter a valid number.");
        }
    }
}

float Extra::RangeNumberInput(float Min, float Max, string message) {
    float thisFloatInput;

    while (true) {
        try {
            string thisStringInput = GetStringInput(message);
            thisFloatInput = stof(thisStringInput);
            if (thisFloatInput >= Min && thisFloatInput <= Max) {
                return thisFloatInput;
            }
            else {
                print("Please enter a valid number between " + to_string(Min) + " and " + to_string(Max));
            }
        }
        catch (exception e) {
            print("Invalid input. Please enter a valid number.");
        }
    }
}

double Extra::RangeNumberInput(double Min, double Max, string message) {
    double thisDoubleInput;

    while (true) {
        try {
            string thisStringInput = GetStringInput(message);
            thisDoubleInput = stod(thisStringInput);
            if (thisDoubleInput >= Min && thisDoubleInput <= Max) {
                return thisDoubleInput;
            }
            else {
                print("Please enter a valid number between " + to_string(Min) + " and " + to_string(Max));
            }
        }
        catch (exception e) {
            print("Invalid input. Please enter a valid number.");
        }
    }
}

string Extra::RangeInput(int Min, int Max, string message) {
    string thisStringInput;

    while (true) {
        try {
            string thisStringInput = GetStringInput(message);
            if (thisStringInput.length() >= Min && thisStringInput.length() <= Max) {
                return thisStringInput;
            }
            else {
                print("Please enter a valid string between " + to_string(Min) + " and " + to_string(Max) + " characters.");
            }
        }
        catch (exception e) {
            print("Invalid input. Please enter a valid string.");
        }
    }
}

