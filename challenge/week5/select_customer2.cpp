#include <iostream>
#include <string>
using namespace std;

int main() {
    const int maxPeople = 5;
    string names[maxPeople];
    int ages[maxPeople];

    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;

    for (int i = 0; i < maxPeople; i++) {
        cout << "사람 " << i + 1 << "의 이름 : ";
        cin >> names[i];
        cout << "사람 " << i + 1 << "의 나이 : ";
        cin >> ages[i];
    }

    // 나이의 최대, 최소를 구하는 과정(그 값의 index 또한 기억하여 name을 구할 수 있도록 한다.)
    int max = ages[0];
    int min = ages[0];
    int big_index = 0;
    int small_index = 0;

    for (int i = 1; i < maxPeople; i++) {
        if (ages[i] > max){ 
            max = ages[i];
            big_index = i;
        }
        if (ages[i] < min){
            min = ages[i];
            small_index = i;
        }
    }

    int number;
    while(1) {
        cout << "메뉴를 선택해주세요 (1:가장 나이가 많은 사람 출력, 2:가장 나이가 적은 사람 출력, 3:종료) : ";
        cin >> number;

        switch(number){
            case 1 :
                cout << "가장 나이가 많은 사람 : " << names[big_index] << endl;
                break;
            case 2 : 
                cout << "가장 나이가 적은 사람 : " << names[small_index] << endl;
                break;
            case 3 :
                cout << "종료" << endl;
                return 0;                   // return 0;을 사용하여 3이 입력되었을 때는 프로그램이 종료되도록 한다.
            default :
                cout << "잘못 입력하셨습니다.";
                break;
        }
    }
}