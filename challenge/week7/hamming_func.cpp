#include <iostream>
#include <string>
using namespace std;

string toLowerStr(string str) {
    for (char &c : str) {
        c = tolower(c);
    }
    return str;
}

string toUpperStr(string str) {
    for (char &c : str) {
        c = toupper(c);
    }
    return str;
}

int calcHammingDist(string s1, string s2) {
    string s_1 = toLowerStr(s1);
    string s_2 = toLowerStr(s2);

    int count = 0;

    for (int i = 0; i < s_1.length(); i++) {
        if (s_1[i] != s_2[i])
            count += 1;
    }

    return count;
}

int main() {
    string s1, s2;
    int count = 0;
    while(true){
        cout << "DNA1 : ";
        cin >> s1;
        cout << "DNA2 : ";
        cin >> s2;

        if (s1.length() != s2.length()) {
            cout << "오류 : 길이가 다름" << endl;
            continue;
        }
        else {
            int count = calcHammingDist(s1, s2);
            cout << "해밍거리는 " << count << endl;
            break;
        }
    }
}