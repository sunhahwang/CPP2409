#include <iostream>
using namespace std;

// 학습자료와 다르게 작성해보기

int main() {
    int floor;
    cout << "몇 층을 쌓겠습니까? (5~100) : ";
    cin >> floor;
    for (int i = 1; i <= floor; i++){               // (i)1부터 floor까지
        for (int j = 1; j <= floor - i; j++){       // (j)1부터 floor -i까지(i가 1이기 때문에 -1를 뺄 수 있다.)
            cout << "S";
        }
        for (int k = 1; k <= i * 2 - 1; k++){       // (k)1부터 i * 2 + 1까지(1부터 시작하기 때무네 2n-1로 만들 수 있다.)
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}