#include <vector>
#include <random>
#include "Extra.hpp"

class SkillBestWorksOn {
public:
    string Type;
    int ExtraDamage;
    void SetType(string Type) {
        this->Type = Type;
    }
    void SetDamage(int ExtraDamage) {
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

    void ClearSkillWorksOnBest() {
        this->ThisSkillBestWorksOnThisTypeOfEnemy.clear();
    }

    float GetTheDamageDealt(string type = "none") {
        float ExtraDamage = FindSkillBestWorksOnThisType(type);

        return SkillDamage + ExtraDamage;
    }
private:
    float FindSkillBestWorksOnThisType(string type) {
        for (auto worksOn : this->ThisSkillBestWorksOnThisTypeOfEnemy) {
            if (worksOn.Type == type || type == "All") {
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
        vector<Skill> TheSkillsOfMine;

        Enemy (int Points, string Name, string Type, float MaxHealth, float Damage) {
            this->Points = Points;
            this->Name = Name;
            this->Type = Type;
            this->MaxHealth = MaxHealth;
            this->CurrentHealth = this->MaxHealth;
            this->Damage = Damage;
        }

        void AddSkills(Skill skill) {
            this->TheSkillsOfMine.push_back(skill);
        }

        bool IsDead();

        int ReturnAttackDamage() {
            int Index = RandomInt(0, this->TheSkillsOfMine.size());
            int Damage = TheSkillsOfMine[Index].GetTheDamageDealt();
            return Damage + this->Damage;
        }
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

float PlayerMaxHealth = 100.00;

float PlayerHealth = PlayerMaxHealth;

string PlayerName;

int PlayerDamage = 10;

int IncreaseDamage = 0;

string PlayerType = "Humanoid";


void StartGame();

int main() {
    EnemyArray enemyArray;
    Skill TheSkill;
    SkillBestWorksOn TheSkillBestWorksOn;

    Enemy SlimeEnemy(2, "Slime of Purity", "Water", 5, 1);
    TheSkillBestWorksOn.SetType("Fire");
    TheSkillBestWorksOn.SetDamage(1);
    TheSkill.AddSkillWorksOn(TheSkillBestWorksOn);
    TheSkill.SkillName = "Water Slash";
    TheSkill.SkillDamage = 2;
    TheSkill.ProbabilityOfHit = 7;
    SlimeEnemy.AddSkills(TheSkill);
    enemyArray.AddEnemy(SlimeEnemy);
    TheSkill.ClearSkillWorksOnBest();

    Enemy SnakeEnemy(3, "Water Snake of Greed", "Water", 3, 3);
    TheSkillBestWorksOn.SetType("Fire");
    TheSkillBestWorksOn.SetDamage(5);
    TheSkill.AddSkillWorksOn(TheSkillBestWorksOn);
    TheSkill.SkillName = "Water Shot";
    TheSkill.SkillDamage = 1;
    TheSkill.ProbabilityOfHit = 7;
    SnakeEnemy.AddSkills(TheSkill);
    TheSkill.SkillName = "Tail Whip";
    TheSkill.SkillDamage = 4;
    TheSkill.ProbabilityOfHit = 3;
    SnakeEnemy.AddSkills(TheSkill);
    enemyArray.AddEnemy(SnakeEnemy);
    TheSkill.ClearSkillWorksOnBest();

    Enemy WolfEnemy(10, "Demon Wolf of Pride", "Monster", 100, 3);
    TheSkillBestWorksOn.SetType("All");
    TheSkillBestWorksOn.SetDamage(2);
    TheSkill.AddSkillWorksOn(TheSkillBestWorksOn);
    TheSkill.SkillName = "Bite";
    TheSkill.SkillDamage = 8;
    TheSkill.ProbabilityOfHit = 5;
    WolfEnemy.AddSkills(TheSkill);
    enemyArray.AddEnemy(WolfEnemy);
    TheSkill.ClearSkillWorksOnBest();

    Enemy GoblinEnemy(30, "Demon Goblin of Lust and Fury/Wrath", "Humanoid", 100, 40);
    TheSkillBestWorksOn.SetType("All");
    TheSkillBestWorksOn.SetDamage(5);
    TheSkill.AddSkillWorksOn(TheSkillBestWorksOn);
    TheSkill.SkillName = "Punch";
    TheSkill.SkillDamage = 6;
    TheSkill.ProbabilityOfHit = 4;
    GoblinEnemy.AddSkills(TheSkill);
    TheSkill.SkillName = "Kick";
    TheSkill.SkillDamage = 8;
    TheSkill.ProbabilityOfHit = 3;
    GoblinEnemy.AddSkills(TheSkill);
    enemyArray.AddEnemy(GoblinEnemy);
    TheSkill.ClearSkillWorksOnBest();

    Enemy TrollEnemy(5, "Troll Demon of Greed and Gluttony", "Humanoid", 100, 60);
    TheSkillBestWorksOn.SetType("Monster");
    TheSkillBestWorksOn.SetDamage(50);
    TheSkill.AddSkillWorksOn(TheSkillBestWorksOn);
    TheSkill.SkillName = "Rock Throw";
    TheSkill.SkillDamage = 10;
    TheSkill.ProbabilityOfHit = 6;
    TrollEnemy.AddSkills(TheSkill);
    enemyArray.AddEnemy(TrollEnemy);
    TheSkill.ClearSkillWorksOnBest();

    Enemy WitchEnemy(100, "Demon Witch of Flames", "Fire", 25, 100);
    TheSkillBestWorksOn.SetType("Water");
    TheSkillBestWorksOn.SetDamage(10);
    TheSkill.AddSkillWorksOn(TheSkillBestWorksOn);
    TheSkill.SkillName = "Fireball";
    TheSkill.SkillDamage = 15;
    TheSkill.ProbabilityOfHit = 8;
    WitchEnemy.AddSkills(TheSkill);
    enemyArray.AddEnemy(WitchEnemy);
    TheSkill.ClearSkillWorksOnBest();

    Enemy DragonEnemy(100, "Fire Dragon of Sloth", "Fire", 520, 400);
    TheSkillBestWorksOn.SetType("Water");
    TheSkillBestWorksOn.SetDamage(300);
    TheSkill.AddSkillWorksOn(TheSkillBestWorksOn);
    TheSkill.SkillName = "Inferno";
    TheSkill.SkillDamage = 20;
    TheSkill.ProbabilityOfHit = 9;
    DragonEnemy.AddSkills(TheSkill);
    enemyArray.AddEnemy(DragonEnemy);
    TheSkill.ClearSkillWorksOnBest();

    Enemy HydraEnemy(100, "Hydra Snake of Envy", "Water", 520, 430);
    TheSkillBestWorksOn.SetType("Fire");
    TheSkillBestWorksOn.SetDamage(400);
    TheSkill.AddSkillWorksOn(TheSkillBestWorksOn);
    TheSkill.SkillName = "Tidal Wave";
    TheSkill.SkillDamage = 18;
    TheSkill.ProbabilityOfHit = 7;
    HydraEnemy.AddSkills(TheSkill);
    enemyArray.AddEnemy(HydraEnemy);
    TheSkill.ClearSkillWorksOnBest();

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
    int p = e.RangeNumberInput(0, 10, "Ok: ");
}

