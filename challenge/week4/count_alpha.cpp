#include <iostream>
using namespace std;

int main() {
    int vowel = 0;
    int consonant = 0;
    cout << "영문자를 입력하고 ctrl+z를 치세요" << endl;

    char ch; 

    //isalpha를 추가하여 입력받은 값이 영소문자인지 확인
    while (cin >> ch){
        if (isalpha(ch) == 2){
            switch (ch){
                case 'a' : case 'e' : case 'i' : case 'o' : case 'u' :
                    vowel++;
                    break;
                default :
                    consonant++;
                    break;
            }
        }
        else {
            cout << "잘못 입력했습니다." << endl;
            continue;
        }
    }

    cout << "모음 : " << vowel << endl;
    cout << "자음 : " << consonant << endl;

    return 0;
}