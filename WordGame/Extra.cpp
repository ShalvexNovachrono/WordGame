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

int Extra::RangeIntInput(int Min, int Max, string message) { // this input function will only return number when it meets the requirement
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