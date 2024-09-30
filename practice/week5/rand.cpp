#include <iostream>
using namespace std;

int main() {   
    double list[10];
    //int list[10];
    double max;
    //int max;

    for (int i = 0; i < 10; i++) {
        double elem = rand() % 100 + 1;
        //int elem = rand() % 100 + 1;
        list[i] = elem;
        cout << elem << " ";
    }
    cout << endl;
    max = list[0];
    for (auto elem : list) {
        if(elem > max)
            max = elem;
    }
    cout << "최댓값 = " << max << endl;

    return 0;
}