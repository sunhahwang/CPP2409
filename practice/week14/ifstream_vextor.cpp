#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class TimeTemp {
public:
    int hour;
    double temperature;
};

int main() {
    ifstream is{ "temp.txt" };
    if (!is) {
        cerr << "파일 오픈에 실패하였습니다." << endl;
        exit(1);
    }

    vector<TimeTemp> temps;
    int hour;
    double temperature;
    while (is >> hour >> temperature) {
        temps.push_back(TimeTemp{ hour, temperature });
    }
    for (TimeTemp t : temps) {
        cout << t.hour << "시: 온도 " << t.temperature << endl;
    }

    return 0;
}