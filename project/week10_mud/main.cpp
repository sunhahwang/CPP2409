#include "user.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(vector<vector<int>> map, int user_x, int user_y);
bool checkGoal(vector<vector<int>> map, int user_x, int user_y);
void checkState(vector<vector<int>> map, int user_x, int user_y, User &user);
int inMapFalse(bool inMap, int user_x, int user_y);
bool checkUser(User user);

int main() {
	// 객체 생성(이 과정에서 생성자를 통해 hp는 20으로 초기화된다.)
	User firstUser;
	
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	vector<vector<int>> map =  { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };

	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		// 새로운 이동 전에 HP값이 0이하인지 확인
        if (!checkUser(firstUser)) { // firstUser의 hp값이 0인지 체크하는 함수를 통해 확인
            cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
            cout << "게임을 종료합니다.";
            break;
        }

		// 현재 HP값 출력 후 이동 명령어 받기
		cout << "현재 HP: " << firstUser.GetHP() << "  명령어를 입력하세요 (up,down,left,right,map,end): ";
		cin >> user_input;

		if (user_input == "up") {
			// 위로 한 칸 올라가기
			user_y -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			// 다시 돌아가기 위한 값 받아오기
			int moveValue = inMapFalse(inMap, user_x, user_y);
			// 돌아가는 경우 (1), 그대로 이동하는 경우 (0)
			user_y += moveValue;
			if (moveValue == 0) {
				cout << "위로 한 칸 올라갑니다." << endl;
				// 이동에 따른 HP값 감소
                firstUser.DecreaseHP(1); // 객체의 멤버 함수를 사용하여 1만큼 감소
				// 어떤 상태를 만났는지 판단 후 문구 출력, HP 증감
                checkState(map, user_x, user_y, firstUser); // 객체도 함께 인자로 넘겨, hp를 조절
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "down") {
			// TODO: 아래로 한 칸 내려가기
			user_y += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			// 다시 돌아가기 위한 값 받아오기
			int moveValue = inMapFalse(inMap, user_x, user_y);
			// 돌아가는 경우 (1), 그대로 이동하는 경우 (0)
			user_y -= moveValue;
			if (moveValue == 0) {
				cout << "아래로 한 칸 내려갑니다." << endl;
				// 이동에 따른 HP값 감소
                firstUser.DecreaseHP(1); // 객체의 멤버 함수를 사용하여 1만큼 감소
				// 어떤 상태를 만났는지 판단 후 문구 출력, HP 증감
                checkState(map, user_x, user_y, firstUser); // 객체도 함께 인자로 넘겨, hp를 조절
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "left") {
			// TODO: 왼쪽으로 이동하기
			user_x -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			// 다시 돌아가기 위한 값 받아오기
			int moveValue = inMapFalse(inMap, user_x, user_y);
			// 돌아가는 경우 (1), 그대로 이동하는 경우 (0)
			user_x += moveValue;
			if (moveValue == 0) {
				cout << "왼쪽으로 이동합니다." << endl;
				// 이동에 따른 HP값 감소
                firstUser.DecreaseHP(1); // 객체의 멤버 함수를 사용하여 1만큼 감소
				// 어떤 상태를 만났는지 판단 후 문구 출력, HP 증감
                checkState(map, user_x, user_y, firstUser); // 객체도 함께 인자로 넘겨, hp를 조절
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "right") {
			// TODO: 오른쪽으로 이동하기
			user_x += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			// 다시 돌아가기 위한 값 받아오기
			int moveValue = inMapFalse(inMap, user_x, user_y);
			// 돌아가는 경우 (1), 그대로 이동하는 경우 (0)
			user_x -= moveValue;
			if (moveValue == 0) {
				cout << "오른쪽으로 이동합니다." << endl;
				// 이동에 따른 HP값 감소
                firstUser.DecreaseHP(1); // 객체의 멤버 함수를 사용하여 1만큼 감소
				// 어떤 상태를 만났는지 판단 후 문구 출력, HP 증감
                checkState(map, user_x, user_y, firstUser); // 객체도 함께 인자로 넘겨, hp를 조절
				displayMap(map, user_x, user_y);
			}

		}
		else if (user_input == "map") {
			// TODO: 지도 보여주기 함수 호출
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "end") {
			cout << "종료합니다.";
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

	}

	return 0;
}

// 지도와 사용자 위치 출력하는 함수
void displayMap(vector<vector<int>> map, int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(vector<vector<int>> map, int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// 아이템/포션, 적을 만났을 때 그에 대한 메세지 출력 및 HP 증감
// User &user를 추가하여 firstUser의 hp를 직접 변경할 수 있도록(&가 없으면 해당 객체의 값이 변경되지 X)
void checkState(vector<vector<int>> map, int user_x, int user_y, User &user) {
    if (map[user_y][user_x] == 1) {
        user.IncreaseHP(2); // firstUser의 hp를 2 증가
        cout << "아이템이 있습니다. HP가 2 늘어납니다." << endl;
    }
    else if (map[user_y][user_x] == 2) {
        user.DecreaseHP(2); // firstUser의 hp를 2 감소
        cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
    }
    else if (map[user_y][user_x] == 3) {
        user.IncreaseHP(2); // firstUser의 hp를 2 증가
        cout << "포션이 있습니다. HP가 2 늘어납니다." << endl;
    }
}

// 맵을 벗어났는지 확인하고 그에 대한 메세지 출력
int inMapFalse (bool inMap, int user_x, int user_y) {
    if (inMap == false) {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        return 1;
    }
    return 0;
}

// User객체의 hp가 0인지 체크
// 단순 값을 확인하는 과정이기 떄문에 &없이 값을 복사하여 확인하는 과정으로 수행
bool checkUser(User user) {
	if (user.GetHP() == 0) {
		return false;
	}
	return true;
}