#include "user.h"

// void 함수의 하는 일(본문)
void User::DecreaseHP(int dec_hp) {
    hp = hp - dec_hp;
}

void User::IncreaseHP(int inc_hp) {
    hp = hp + inc_hp;
}

void User::IncreaseItemCnt(int inc_ic) {
    itemCnt = itemCnt + inc_ic;
}

void User::DoAttack() {
    cout << "공격합니다." << endl;
}

// int 함수의 하는 일 (본문)(return 값)
int User::GetHP() {
    return hp;
}


// void 함수의 하는 일(본문)
void Magician::DecreaseHP(int dec_hp) override {
    hp = hp - dec_hp;
}

void Magician::IncreaseHP(int inc_hp) {
    hp = hp + inc_hp;
}

void Magician::IncreaseItemCnt(int inc_ic) {
    itemCnt = itemCnt + inc_ic;
}

void Magician::DoAttack() {
    cout << "공격합니다." << endl;
}

// int 함수의 하는 일 (본문)(return 값)
int Magician::GetHP() {
    return hp;
}

// void 함수의 하는 일(본문)
void Warrior::DecreaseHP(int dec_hp) {
    hp = hp - dec_hp;
}

void Warrior::IncreaseHP(int inc_hp) {
    hp = hp + inc_hp;
}

void Warrior::IncreaseItemCnt(int inc_ic) {
    itemCnt = itemCnt + inc_ic;
}

void Warrior::DoAttack() {
    cout << "공격합니다." << endl;
}

// int 함수의 하는 일 (본문)(return 값)
int Warrior::GetHP() {
    return hp;
}


// 자식 클래스의 DoAttack() 재정의
void Magician::DoAttack() {
    cout << "마법 사용" << endl;
}

void Warrior::DoAttack() {
    cout << "베기 사용" << endl;
}