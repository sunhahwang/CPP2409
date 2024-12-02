#include "user.h"

// Magician의 User 가상 함수 오버라이딩(상세 내용)
void Magician::DecreaseHP(int dec_hp) {
    hp = hp - dec_hp;
} // hp 감소

void Magician::IncreaseHP(int inc_hp) {
    hp = hp + inc_hp;
} // hp 증가

void Magician::IncreaseItemCnt(int inc_ic) {
    itemCnt = itemCnt + inc_ic;
} // itemCnt 증가

void Magician::DoAttack() {
    cout << "마법 사용." << endl;
} // 메세지 출력

int Magician::GetHP() const {
    return hp;
} // 현 hp 값 반환

void Magician::SpeakInformation() {
    cout << "현재 HP는 " << hp << "이고, 먹은 아이템은 총 " << itemCnt << "개 입니다." << endl;
} // 메세지 출력

// Warrior의 User 가상 함수 오버라이딩(상세 내용)
void Warrior::DecreaseHP(int dec_hp) {
    hp = hp - dec_hp;
} // hp 감소

void Warrior::IncreaseHP(int inc_hp) {
    hp = hp + inc_hp;
} // hp 증가

void Warrior::IncreaseItemCnt(int inc_ic) {
    itemCnt = itemCnt + inc_ic;
} // itemCnt 증가

void Warrior::DoAttack() {
    cout << "베기 사용." << endl;
} // 메세지 출력

int Warrior::GetHP() const {
    return hp;
} // 현 hp 값 반환

void Warrior:: SpeakInformation() {
    cout << "현재 HP는 " << hp << "이고, 먹은 아이템은 총 " << itemCnt << "개 입니다." << endl;
} // 메세지 출력