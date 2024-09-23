#include <iostream>
using namespace std;

int main() {
    int a, b, c, largest;

    cout << "3개의 정수를 입력하시오 : ";
    cin >> a >> b >> c;

    // a와 b가 같고 c가 a, b보다 작을 때 c가 출력되는 문제 해결
    if (a >= b && a >= c){
        largest = a;
    }
    else if (b >= a && b >= c){
        largest = b;
    }
    else {
        largest = c;
    }

    cout << "가장 큰 정수는" << largest << endl;

    return 0;
}