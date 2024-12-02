#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream os{ "temp.txt" };
    if (!os) {
        cerr << "파일 오픈에 실패하였습니다." << endl;
        exit(1);
    }
    for (int i = 1, j = 24; i < 5; i++, j++) {
        os << i << " " << j << ".0" << endl;
    } 

    ifstream is{ "temp.txt" };
    if (!is) {
        cerr << "파일 오픈에 실패하였습니다." << endl;
        exit(1);
    }

    int hour;
    double temperature;
    while (is >> hour >> temperature) {
        cout << hour << "시: 온도 " << temperature << endl;
    }

    return 0;
}