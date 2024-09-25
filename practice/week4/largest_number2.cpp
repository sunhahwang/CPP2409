#include <iostream>
using namespace std;

int main() {
    int a, b, c, largest;

    cout << "3개의 정수를 입력하시오 : ";
    cin >> a >> b >> c;

    // 중첩반복문을 이용하여 가장 큰 값 구하기
    if (a >= b){
        if (a >= c){
            largest =a;
        }
    } // 큰 값으로 a 비교하기
    else if (b >= a){
        if (b >= c){
            largest = b;
        }
    } // 큰 값으로 b 비교하기
    else{
        largest = c;
    } // 큰 값 c

    cout << "가장 큰 정수는" << largest << endl;

    return 0;
}