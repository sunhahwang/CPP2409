#include <iostream>
#include <time.h>
using namespace std;

int main() {
    int i;
    int ans;
    cout << "산수 문제를 자동으로 출제합니다. " << endl;

    // while문의 조건을 true로 설정하여 맞았을 때 break로 나가고 틀렸을 때 continue로 되돌아 갈 수 있도록
    while(true){
        int firstNum = rand()%100;
        int secondNum = rand()%100;

        cout << firstNum << "+" << secondNum << "=";
        cin >> ans;
        if (ans == firstNum + secondNum){
            cout << "맞았습니다.";
            break;
        }
        else {
            cout << "틀렸습니다." << endl;            
            continue;
        }
    }

    return 0;
}