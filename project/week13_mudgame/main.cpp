#include "user.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
// 플레이어가 2명으로 늘어난 만큼 각각의 플레이어를 map에 나타내기 위해서는 플레이어 각각의 위치가 필요
// displayMap의 파라미터를 다음과 같이 설정한다.
void displayMap(vector<vector<int>> map, int magi_x, int magi_y, int warr_x, int warr_y);
bool checkGoal(vector<vector<int>> map, int user_x, int user_y);
void checkState(vector<vector<int>> map, int user_x, int user_y, User &user);
int inMapFalse(bool inMap, int user_x, int user_y);
bool checkUser(User user);

int main() {
	// 객체 생성
	// Magician과 Warrior는 User 클래스의 일종으로 간주될 수 있음(상속관계이기에)
	// 자식 클래스 객체의 주소를 부모 클래스의 포인터에 저장하여 접근이 가능
	User *current_user;
	Magician magician;
	Warrior warrior;

	// 플레이어의 순서를 체크하기 위한 변수
	int k = 0;
	
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	vector<vector<int>> map =  { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };

	// 각각의 플레이어의 위치
	int magi_x = 0;
	int magi_y = 0;
	int warr_x = 0;
	int warr_y = 0;

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// k가 짝수일 때 -> Magician의 차례
		// k가 홀수일 때 -> Warrior의 차례
		// 한 플레이어의 이동이 완료되었을 때 k값을 + 1 한다.
		switch(k % 2) {
		case(0) :
			cout << "Magician의 차례입니다." << endl;
			current_user = &magician;	// 부모클래스의 포인터가 magician객체의 주소를 포인팅
			break;
		case(1) :
			cout << "Warrior의 차례입니다." << endl;
			current_user = &warrior;	// 부모클래스의 포인터가 warrior객체의 주소를 포인팅
			break;
 		}

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		// 현재 HP값 출력 후 이동 명령어 받기
		// 포인터가 멤버변수/함수를 가리킬 때는 -> 사용
		// 현재의 플레이서의 hp를 GetHP()를 통해 알아온다
		cout << "현재 HP: " << current_user->GetHP() << "  명령어를 입력하세요 (up,down,left,right,information,map,end): ";
		cin >> user_input;

		// map을 그릴 때와 달리, 이동위치가 올바른지 알아보거나 상태를 확인할 때에는 두 플레이어의 위치를 모두 알 필요 x
		// 현재 플레이어의 위치만 그때그때 user_x, user_y로 받아오고 원래 선언된 함수를 사용한다.
		int user_x, user_y;
		if (k % 2 == 0) {
			user_x = magi_x;
			user_y = magi_y;
		}
		else {
			user_x = warr_x;
			user_y = warr_y;
		}

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
                current_user->DecreaseHP(1); // 객체의 멤버 함수를 사용하여 1만큼 감소
				// 어떤 상태를 만났는지 판단 후 문구 출력, HP 증감
                checkState(map, user_x, user_y, *current_user); // 객체를 가리키는 포인터도 함께 인자로 넘겨, hp를 조절
				// 위의 코드들에서 변경된 user_x, user_y값을 원래의 두 플레이어 위치값에 반영
        		if (k % 2 == 0) {
            		magi_x = user_x;
            		magi_y = user_y;
        		} else {
            		warr_x = user_x;
            		warr_y = user_y;
        		}
				// 반영된 값으로 map을 출력한다.
				displayMap(map, magi_x, magi_y, warr_x, warr_y);
				k++; // 플레이어를 변경하기 위한 k++
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
                current_user->DecreaseHP(1); // 객체의 멤버 함수를 사용하여 1만큼 감소
				// 어떤 상태를 만났는지 판단 후 문구 출력, HP 증감
                checkState(map, user_x, user_y, *current_user); // 객체를 가리키는 포인터도 함께 인자로 넘겨, hp를 조절
				// 위의 코드들에서 변경된 user_x, user_y값을 원래의 두 플레이어 위치값에 반영
        		if (k % 2 == 0) {
            		magi_x = user_x;
            		magi_y = user_y;
        		} else {
            		warr_x = user_x;
            		warr_y = user_y;
        		}
				// 반영된 값으로 map을 출력한다.
				displayMap(map, magi_x, magi_y, warr_x, warr_y);
				k++; // 플레이어를 변경하기 위한 k++
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
                current_user->DecreaseHP(1); // 객체의 멤버 함수를 사용하여 1만큼 감소
				// 어떤 상태를 만났는지 판단 후 문구 출력, HP 증감
                checkState(map, user_x, user_y, *current_user); // 객체를 가리키는 포인터도 함께 인자로 넘겨, hp를 조절
				// 위의 코드들에서 변경된 user_x, user_y값을 원래의 두 플레이어 위치값에 반영
        		if (k % 2 == 0) {
            		magi_x = user_x;
            		magi_y = user_y;
        		} else {
            		warr_x = user_x;
            		warr_y = user_y;
        		}
				// 반영된 값으로 map을 출력한다.
				displayMap(map, magi_x, magi_y, warr_x, warr_y);
				k++; // 플레이어를 변경하기 위한 k++
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
                current_user->DecreaseHP(1); // 객체의 멤버 함수를 사용하여 1만큼 감소
				// 어떤 상태를 만났는지 판단 후 문구 출력, HP 증감
                checkState(map, user_x, user_y, *current_user); // 객체를 가리키는 포인터도 함께 인자로 넘겨, hp를 조절
				// 위의 코드들에서 변경된 user_x, user_y값을 원래의 두 플레이어 위치값에 반영
        		if (k % 2 == 0) {
            		magi_x = user_x;
            		magi_y = user_y;
        		} else {
            		warr_x = user_x;
            		warr_y = user_y;
        		}
				// 반영된 값으로 map을 출력한다.
				displayMap(map, magi_x, magi_y, warr_x, warr_y);
				k++; // 플레이어를 변경하기 위한 k++
			}

		}
		else if (user_input == "information") {
			// User의 friend를 통해 각각의 객체의 hp와 itemCnt에 접근
			cout << *current_user << endl;
		}
		else if (user_input == "map") {
			// TODO: 지도 보여주기 함수 호출
			displayMap(map, magi_x, magi_y, warr_x, warr_y);
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
			// 어떤 플레이어가 도착했는지 확인하기 위한 변수 선언
			// 위 코드에서 k++로 인해 기준이 달라졌음
			// k가 짝수 -> Warrior, k가 홀수 -> Magician
			string end_user;
			if (k % 2 == 0) 
				end_user = "Warrior";
			else 
				end_user = "Magician";
			cout << end_user << "가 목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

		// 플레이어의 HP가 0이하인지 확인
		// 이 if문을 맨 뒤에서 실행하지 않으면 hp가 0이하가 된 플레이어의 다음 차례가 돌아왔을 때 실패가 결정된다.
        if (!checkUser(*current_user)) { // 플레이어의 hp값이 0인지 체크하는 함수를 통해 확인
			// HP가 0이하가 된 플레이어를 알리기 위한 변수
			// 게임의 시작지점에서 확인할 때와 달리, k++로 인해 end_user를 구별하는 기준이 달라졌기 때문에
			// k가 짝수 -> Warrior, k가 홀수 -> Magician
            string end_user;
			if (k % 2 == 0) 
				end_user = "Warrior";
			else 
				end_user = "Magician";
			cout << end_user <<"의 HP가 0 이하가 되었습니다. 실패했습니다." << endl;
            cout << "게임을 종료합니다.";
            break;
        }

	}

	return 0;
}

// 지도와 사용자 위치 출력하는 함수
void displayMap(vector<vector<int>> map, int magi_x, int magi_y, int warr_x, int warr_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == magi_y && j == magi_x && i == warr_y && j == warr_x) // 두 플레이어의 위치가 동일
                cout << " MAWA |";
            else if (i == magi_y && j == magi_x) // magician 플레이어의 위치
                cout << " MAGI |";
            else if (i == warr_y && j == warr_x) // warrior 플레이어의 위치
                cout << " WARR |";
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
	cout << endl;
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
// User &user를 추가하여 객체의 hp를 직접 변경할 수 있도록(&가 없으면 해당 객체의 값이 변경되지 X)
void checkState(vector<vector<int>> map, int user_x, int user_y, User &user) {
    if (map[user_y][user_x] == 1) {
        user.IncreaseHP(2); // 객체의 hp를 2 증가
		user.IncreaseItemCnt(1); // 객체의 itemCnt를 1 증가
        cout << "아이템이 있습니다. HP가 2 늘어납니다." << endl;
    }
    else if (map[user_y][user_x] == 2) {
        user.DecreaseHP(2); // 객체의 hp를 2 감소
        cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
    }
    else if (map[user_y][user_x] == 3) {
        user.IncreaseHP(2); // 객체의 hp를 2 증가
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
	if (user.GetHP() <= 0) {
		return false;
	}
	return true;
}