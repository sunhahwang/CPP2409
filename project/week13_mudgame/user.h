#include <iostream>
#include <string>
using namespace std;

class User {
private:
    int hp;
    int itemCnt;

public:
    virtual void DecreaseHP(int dec_hp) = 0;
    virtual void IncreaseHP(int inc_hp) = 0;
    virtual void IncreaseItemCnt(int inc_ic) = 0;
    void DoAttack();
    virtual int GetHP() = 0;

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
public:
    void DoAttack();
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    void IncreaseItemCnt(int inc_ic);
    int GetHP();
};

// User를 부모 클래스로 두는 자식 클래스 Warrior
class Warrior : public User {
private:
    int hp;
    int itemCnt;
public:
    void DoAttack();
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    void IncreaseItemCnt(int inc_ic);
    int GetHP();
};