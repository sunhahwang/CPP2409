#include <iostream>
#include <string>
using namespace std;

class User {
private:
    int hp;

public:
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    int GetHP();
    User();
    
};