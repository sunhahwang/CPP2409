#include <iostream>
#include <time.h>
using namespace std;

int main() {
    srand(time(NULL));

    int answer = rand() % 100;
    int tries = 0;

    int guess;

    // while문을 이용하여 추측한 값과 답이 일치할 때까지 반복
    while(guess != answer) {
        cout << "정답을 추측하여 보시오 : ";
        cin >> guess;
        tries++;

        if (guess > answer){
            cout << "제시된 정수가 높습니다." << endl;
        }
        else if (guess < answer){
            cout << "제시된 정수가 낮습니다." << endl;
        }
    }

    cout << "축하합니다. 시도 회수=" << tries << endl;
    
    return 0;
}