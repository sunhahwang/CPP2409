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


// 자식 클래스의 DoAttack() 재정의
void Magician::DoAttack() {
    cout << "마법 사용" << endl;
}

void Warrior::DoAttack() {
    cout << "베기 사용" << endl;
}