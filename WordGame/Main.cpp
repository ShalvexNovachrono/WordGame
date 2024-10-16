#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Extra {
	public:
		void print(string message, int mode);

        string GetStringInput(string message);

        int RangeIntInput(int Min, int Max, string message);
};

void Extra::print(string message, int mode = 0) {
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

class Enemy {
    public:
        int ID;
        int Points;
        float Health;
        string Name;
        float CurrentDamageTaken = 0;
        float Damage;

        Enemy (int Points, string Name, float Health, float Damage) {
            this->Points = Points;
            this->Name = Name;
            this->Health = Health;
            this->Damage = Damage;
        }
};

class EnemyArray {
    public:
        vector<Enemy> TheEnemyArray;
        int ID = 0;
        void AddEnemy(Enemy newEnemy);
        int GetArrayLength();
        Enemy GetElementFromThisIndex(int Index);
        void DeleteElement(int Index);
};

void EnemyArray::AddEnemy(Enemy newEnemy) {
    this->ID++;
    newEnemy.ID = this->ID;
    TheEnemyArray.push_back(newEnemy);
}

int EnemyArray::GetArrayLength() {
    return this->TheEnemyArray.size();
}

Enemy EnemyArray::GetElementFromThisIndex(int Index = 0) {
    return this->TheEnemyArray[Index];
}

void EnemyArray::DeleteElement(int Index = 0) {
    this->TheEnemyArray.erase(next(this->TheEnemyArray.begin(), Index));
}

int main() {
    EnemyArray enemyArray;

    Enemy newEnemy(2, "Slime", 5, 1);
    enemyArray.AddEnemy(newEnemy);

    Enemy newEnemy2(10, "Wolf", 100, 3);
    enemyArray.AddEnemy(newEnemy2);

    Enemy newEnemy3(30, "Goblin", 100, 40);
    enemyArray.AddEnemy(newEnemy3);

    enemyArray.DeleteElement(2);


    for (auto enemy : enemyArray.TheEnemyArray) {
        cout << "Name: " << enemy.Name << endl;
        cout << "Points: " << enemy.Points << endl;
        cout << "Health: " << enemy.Health << endl;
        cout << "Damage: " << enemy.Damage << endl;
    }

	Extra e;
	e.print("Hello world!!!");
	string somthing = e.GetStringInput("Hi: ");
    int p = e.RangeIntInput(0, 10, "Ok: ");
}