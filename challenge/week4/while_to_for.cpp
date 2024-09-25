#include <iostream>
using namespace std;

int main() {
    int userInput;

    cout << "정수를 10번 입력하세요 (0을 입력하면 종료) : ";
    int i = 0;

    // for문을 사용하여 10번만 실행되도록 하는 while문의 코드를 생략
    for (int j = 0; j < 10; j++){
        cin >> userInput;
        if (userInput == 0){
            break;
        }

        cout << "입력값 : " << userInput << " 1횟수 : " << i++ << endl;
    }
    cout << "종료되었습니다";

    return 0;
}