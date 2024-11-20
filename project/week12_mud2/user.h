#include <iostream>
#include <string>
using namespace std;

class User {
private:
    int hp;
    int itemCnt;

public:
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    void IncreaseItemCnt(int inc_ic);
    void DoAttack();
    int GetHP();
    User() : hp(20), itemCnt(0){};

    friend ostream& operator << (ostream& os, const User& u) {
        os << "현재 HP는 " << u.hp << "이고, " << "먹은 아이템은 총 " << u.itemCnt << "개 입니다.";
        return os;
    }
    
};

class Magician : public User {
private:
    int hp;
    int itemCnt;

    friend ostream& operator << (ostream& os, const Magician& m) {
        os << "Magi";
        return os;
    }

public:
    void DoAttack(); // 재정의
};

class Warrior : public User {
private:
    int hp;
    int itemCnt;

    friend ostream& operator << (ostream& os, const Warrior& w) {
        os << "Warr";
        return os;
    }
public:
    void DoAttack(); // 재정의
};