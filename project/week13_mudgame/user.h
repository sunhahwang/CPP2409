#include <iostream>
#include <string>
using namespace std;

// 모든 사용자의 기본 클래스
class User {
public:
    virtual void DoAttack() = 0; // 공격 가상 함수
    virtual void DecreaseHP(int dec_hp) = 0; // HP 감소 가상 함수
    virtual void IncreaseHP(int inc_hp) = 0; // HP 증가 가상 함수
    virtual void IncreaseItemCnt(int inc_ic) = 0; // itenCnt 증가 가상 함수
    virtual int GetHP() const = 0; // HP값 반환 가상 함수
    virtual void SpeakInformation() = 0; // 정보 출력 가상 함수
};

// User 클래스를 상속받는 플레이어 Mafician
class Magician : public User {
private:
    int hp; // Magician의 hp
    int itemCnt; // Magician의 itemCnt
public:
    Magician() : hp(20), itemCnt(0) {} // 생성자를 통해 초기 설정
    
    // User의 함수 오버라이딩
    void DecreaseHP(int dec_hp) override;
    void IncreaseHP(int inc_hp) override;
    void IncreaseItemCnt(int inc_ic) override;
    int GetHP() const override;
    void DoAttack() override;
    void SpeakInformation() override;
};

class Warrior : public User {
private:
    int hp; // Warrior의 hp
    int itemCnt; // Warrior의 itemCnt
public:
    Warrior() : hp(20), itemCnt(0) {} // 생성자를 통해 초기 설정
    
    // User의 함수 오버라이딩
    void DecreaseHP(int dec_hp) override;
    void IncreaseHP(int inc_hp) override;
    void IncreaseItemCnt(int inc_ic) override;
    int GetHP() const override;
    void DoAttack() override;
    void SpeakInformation() override;
};