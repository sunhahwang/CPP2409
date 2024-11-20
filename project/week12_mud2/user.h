#include <iostream>
#include <string>
using namespace std;

class User {
private:
    int hp;
    int itemCnt; // 아이템을 획득한 수

public:
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    void IncreaseItemCnt(int inc_ic); // itemCnt를 inc_in만큼 증가시키는 함수 선언
    void DoAttack(); // 상위 클래스인 User에서 DoAttack 함수 선언
    int GetHP();
    User() : hp(20), itemCnt(0){}; // User클래스의 hp를 20으로, itemCnt를 0으로 초기화한다(생성자)

    // friend를 통해 User class의 private로 선언된 hp와 itemCnt에 접근
    friend ostream& operator << (ostream& os, const User& u) {
        os << "현재 HP는 " << u.hp << "이고, " << "먹은 아이템은 총 " << u.itemCnt << "개 입니다.";
        return os;
    }
};

// User를 부모 클래스로 두는 자식 클래스 Magician
class Magician : public User {
private: // Magician 클래스만의 변수 생성
    int hp;
    int itemCnt;

public:
    void DoAttack(); // 하위클래스에서 DoAttack 재정의
};

// User를 부모 클래스로 두는 자식 클래스 Warrior
class Warrior : public User {
private: // Warrior 클래스만의 변수 생성
    int hp;
    int itemCnt;

public:
    void DoAttack(); // 하위클래스에서 DoAttack 재정의
};