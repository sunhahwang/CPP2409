#include <vector>
#include <iostream>
using namespace std;

int main(void) {
    vector<int> n;

    int number;
    int sum;
    int vector_num = -1;
    while(number != -1) {
        cout << "성적을 입력하시오(종료는 -1) : ";
        cin >> number;
        n.push_back(number);
        vector_num++;
    }
    n.erase(n.end() - 1);

    for (auto& e : n) {
        sum += e;
    }

    cout << "성적 평균 = " << sum / vector_num;

}