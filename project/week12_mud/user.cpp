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

int User::GetHP() {
    return hp;
}