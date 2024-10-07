#include <iostream>
using namespace std;

// 전역변수를 사용하여 함수들끼리의 변수 사용을 용이하게 한다.
const int NUM_USERS = 3;
const int NUM_ITEMS = 3;
int userPreferences[NUM_USERS][NUM_ITEMS];

// 사용자와 항목 간의 선호도를 입력 받아 2차원 배열을 초기화한다.
void initializePreferences(int preferences[NUM_USERS][NUM_ITEMS]){
    for (int i = 0; i < NUM_USERS; ++i) {
        cout << "사용자 " << (i + 1) << "의 선호도를 입력하세요 (";
        cout << NUM_ITEMS << "개의 항목에 대해) : ";
        for (int j = 0; j < NUM_ITEMS; ++j) {
            cin >> userPreferences[i][j];
        }
    }
}

// 각 사용자에 대한 추천 항목을 찾고 사용자에게 추천하는 항목을 출력한다.
void findRecommendedItems(const int preferences[NUM_USERS][NUM_ITEMS]){
    for (int i = 0; i < NUM_USERS; ++i) {
        int maxPreferenceIndex = 0;
        for (int j = 0; j < NUM_ITEMS; ++j) {
            if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]) {
                maxPreferenceIndex = j;
            }
        }

        cout << "사용자 " << (i + 1) << "에게 추천하는 항목 : ";
        cout << (maxPreferenceIndex + 1) << std::endl;
    }
}

// 시작점
int main() {
    
    initializePreferences(userPreferences);     // 선호도 초기화
    findRecommendedItems(userPreferences);      // 사용자에게 추천할 항목 찾기

    return 0;
}