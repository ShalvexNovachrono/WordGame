#include <vector>
#include <random>
#include "Extra.hpp"

class SkillBestWorksOn {
public:
    string Type;
    float ExtraDamage;
    SkillBestWorksOn(string Type, float ExtraDamage) {
        this->Type = Type;
        this->ExtraDamage = ExtraDamage;
    }
};

int RandomInt(int MIN, int MAX) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(MIN, MAX);
    return dis(gen);
}

class Skill {
public:
    string SkillName;
    int SkillDamage;
    int ProbabilityOfHit;
    vector<SkillBestWorksOn> ThisSkillBestWorksOnThisTypeOfEnemy;

    void AddSkillWorksOn(SkillBestWorksOn WorksBestOn) {
        this->ThisSkillBestWorksOnThisTypeOfEnemy.push_back(WorksBestOn);
    }

    float GetTheDamageDealt(string type) {
        float ExtraDamage = FindSkillBestWorksOnThisType(type);

        return SkillDamage + ExtraDamage;
    }
private:
    float FindSkillBestWorksOnThisType(string type) {
        for (auto worksOn : this->ThisSkillBestWorksOnThisTypeOfEnemy) {
            if (worksOn.Type == type) {
                float AnotherExtraDamage = 0;
                int RandomOne = RandomInt(0, 20);
                if (RandomOne >= 10) {
                    AnotherExtraDamage = (RandomInt(1, 10) * ProbabilityOfHit) / 100.0; // this will small extra extra damage to the enemy
                }
                else {
                    AnotherExtraDamage += ProbabilityOfHit / 10; // still gives small extra extra damage to the enemy
                }
                return worksOn.ExtraDamage + AnotherExtraDamage;
            }
        }
        return 0.0;
    }
};

class Enemy {
    public:
        int Points;
        float MaxHealth;
        float CurrentHealth;
        string Name;
        string Type;
        float CurrentDamageTaken = 0;
        float Damage;

        Enemy (int Points, string Name, string Type, float MaxHealth, float Damage) {
            this->Points = Points;
            this->Name = Name;
            this->Type = Type;
            this->MaxHealth = MaxHealth;
            this->CurrentHealth = this->MaxHealth;
            this->Damage = Damage;
        }

        bool IsDead();
};

bool Enemy::IsDead() {
    CurrentHealth = MaxHealth - CurrentDamageTaken;
    return (CurrentDamageTaken >= CurrentHealth) ? true : false;
}

class EnemyArray {
    public:
        vector<Enemy> TheEnemyArray;
        void AddEnemy(Enemy newEnemy);
        int GetArrayLength();
        Enemy GetElementFromThisIndex(int Index);
        void DeleteElement(int Index);
        void UpdateEnemyHealth(int Index, int DamageTaken);
};

void EnemyArray::AddEnemy(Enemy newEnemy) {
    TheEnemyArray.push_back(newEnemy);
}

int EnemyArray::GetArrayLength() {
    return this->TheEnemyArray.size() + 0;
}

Enemy EnemyArray::GetElementFromThisIndex(int Index = 0) {
    return this->TheEnemyArray[Index];
}

void EnemyArray::DeleteElement(int Index = 0) {
    this->TheEnemyArray.erase(next(this->TheEnemyArray.begin(), Index));
}

void EnemyArray::UpdateEnemyHealth(int Index, int DamageTaken) {
    Enemy CurrentEnemy = this->GetElementFromThisIndex(Index);
    CurrentEnemy.CurrentDamageTaken += DamageTaken;
}

int main() {
    EnemyArray enemyArray;

    Enemy SlimeEnemy(2, "Slime", "Water", 5, 1);
    enemyArray.AddEnemy(SlimeEnemy);

    Enemy WolfEnemy(10, "Wolf", "Monster", 100, 3);
    enemyArray.AddEnemy(WolfEnemy);

    Enemy GoblinEnemy(30, "Goblin", "Humanoid", 100, 40);
    enemyArray.AddEnemy(GoblinEnemy);

    Enemy TrollEnemy(5, "Troll", "Humanoid", 100, 60);
    enemyArray.AddEnemy(TrollEnemy);

    Enemy WitchEnemy(100, "Witch", "Fire", 25, 100);
    enemyArray.AddEnemy(WitchEnemy);

    //enemyArray.DeleteElement(2);


    for (auto enemy : enemyArray.TheEnemyArray) {
        cout << "Name: " << enemy.Name << endl;
        cout << "Points: " << enemy.Points << endl;
        cout << "Health: " << enemy.CurrentHealth << endl;
        cout << "Damage: " << enemy.Damage << endl;
    }

	Extra e;
	e.print("Hello world!!!");
	string somthing = e.GetStringInput("Hi: ");
    int p = e.RangeIntInput(0, 10, "Ok: ");
}