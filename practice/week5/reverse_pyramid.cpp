#include <iostream>
using namespace std;

// 학습자료와 다르게 작성해보기

int main() {
    int floor;
    cout << "몇 층을 쌓겠습니까? (5~100) : ";
    cin >> floor;
    for (int i = 0; i < floor; i++){                    // (i) 0부터 floor까지 floor번 반복
        for (int j = floor; j > floor - i; j--){        // (j) floor부터 줄여가며 floor - i - 1까지 반복
            cout << "S";
        }
        for (int k = (floor - i) * 2 - 1; k > 0; k--){  // (k) (floor - i) * 2 - 1부터 0까지 1씩 줄여가며 반복
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}