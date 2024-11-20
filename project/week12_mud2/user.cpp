#include "user.h"

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

int User::GetHP() {
    return hp;
}

void Magician::DoAttack() {
    cout << "마법 사용" << endl;
}

void Warrior::DoAttack() {
    cout << "베기 사용" << endl;
}