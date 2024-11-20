#include <iostream>
#include <string>
using namespace std;

class Person {
    string name; // 기본적으로 private
protected:
    string address;
    string GetName() { // 부모 클래스의 protected에 name을 가져오는 GetName()생성
        return name;
    }
};

class Student : Person {
public:
    void SetAddress(string add) {
        address = add;
    }
    string GetAddress() {
        return address;
    }
    void SetName(string n) {
        GetName() = n;
    } // 부모 클래스의 GetName()을 통해 자식 클래스에서 SetName 실행
};

int main() {
    Student obj;
    obj.SetName("미수");
    obj.SetAddress("서울시 종로구 1번지");
    cout << obj.GetAddress() << endl;
    return 0;
}