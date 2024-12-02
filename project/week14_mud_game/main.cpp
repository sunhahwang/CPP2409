#include "user.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// 전체 맵 크기 설정
const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
// displayMap에서 string user_choice를 추가하여 map에 플레이어에 따른 유저를 나타낸다.
void displayMap(vector<vector<int>> map, int user_x, int user_y, string user_choice);
bool checkGoal(vector<vector<int>> map, int user_x, int user_y);
void checkState(vector<vector<int>> map, int user_x, int user_y, User &user);
int inMapFalse(bool inMap, int user_x, int user_y);
bool checkUser(User user);

int main() {
	// User 객체를 가리킬 포인터 선언
    User* user;

	// 사용자의 선택을 저장할 변수
    string user_choice;
	cout << "직업을 선택해주세요!(Magician or Warrior) : ";
	cin >> user_choice;

    if (user_choice == "Magician") {
		// Magician 객체를 생성하여 user 포인터에 할당
        user = new Magician();
        cout << "당신의 직업은 Magician입니다!" << endl;
    }
    else if (user_choice == "Warrior") {
		// Warrior 객체를 생성하여 user 포인터에 할당
        user = new Warrior();
        cout << "당신의 직업은 Warrior입니다!" << endl;
    }
    else {
		// 잘못된 입력을 안내하고 프로그램 종료
        cout << "Magician, Warrior 중 하나를 입력해주세요." << endl;
		return 0;
    }
	
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	vector<vector<int>> map;
	// ifstream을 이용하여 map.txt를 열고 열 별로 저장된 vector를 map vector에 추가
	ifstream is{ "map.txt" };
    if (!is) {
        cerr << "파일 오픈에 실패하였습니다." << endl;
        exit(1);
    }
    int map_number;
	vector<int> map_row;
	// 파일에서 글자를 받아올 수 있을 때까지 반복
    while(is) {
		is >> map_number; // 글자 받아오고
        map_row.push_back(map_number); // map의 열 벡터(map_row)에 저장
		
		// map_row의 크기가 5일 때 map 벡터에 추가
		if (map_row.size() == 5) {
			map.push_back(map_row);
			map_row.clear(); // map_row 초기화
		}
    }

	// 플레이어의 위치
	int user_x = 0;
    int user_y = 0;

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수
		string user_input = "";

		// 현재 HP값 출력 후 이동 명령어 받기
		// 포인터가 멤버변수/함수를 가리킬 때는 -> 사용
		// 현재의 플레이서의 hp를 GetHP()를 통해 알아온다
		cout << "현재 HP: " << user->GetHP() << "  명령어를 입력하세요 (up,down,left,right,information,map,end): ";
		cin >> user_input;

		// 해당 과정에서 발생하는 오류(맵을 벗어남, 잘못된 입력)를 잡기 위한 try
		try {
			if (user_input == "up") {
				// 위로 한 칸 올라가기
				user_y -= 1;
				bool inMap = checkXY(user_x, mapX, user_y, mapY);
				// 다시 돌아가기 위한 값 받아오기
				int moveValue = inMapFalse(inMap, user_x, user_y); // 맵을 벗어나는지 확인 후 throw 실행
				cout << "위로 한 칸 올라갑니다." << endl;
				// 이동에 따른 HP값 감소
				user->DecreaseHP(1); // 객체의 멤버 함수를 사용하여 1만큼 감소
				// 어떤 상태를 만났는지 판단 후 문구 출력, HP 증감
				checkState(map, user_x, user_y, *user); // 객체를 가리키는 포인터도 함께 인자로 넘겨, hp를 조절
				displayMap(map, user_x, user_y, user_choice);
			}
			else if (user_input == "down") {
				// TODO: 아래로 한 칸 내려가기
				user_y += 1;
				bool inMap = checkXY(user_x, mapX, user_y, mapY);
				// 다시 돌아가기 위한 값 받아오기
				int moveValue = inMapFalse(inMap, user_x, user_y); // 맵을 벗어나는지 확인 후 throw 실행
				cout << "아래로 한 칸 내려갑니다." << endl;
				// 이동에 따른 HP값 감소
				user->DecreaseHP(1); // 객체의 멤버 함수를 사용하여 1만큼 감소
				// 어떤 상태를 만났는지 판단 후 문구 출력, HP 증감
				checkState(map, user_x, user_y, *user); // 객체를 가리키는 포인터도 함께 인자로 넘겨, hp를 조절
				displayMap(map, user_x, user_y, user_choice);
			}
			else if (user_input == "left") {
				// TODO: 왼쪽으로 이동하기
				user_x -= 1;
				bool inMap = checkXY(user_x, mapX, user_y, mapY);
				// 다시 돌아가기 위한 값 받아오기
				int moveValue = inMapFalse(inMap, user_x, user_y); // 맵을 벗어나는지 확인 후 throw 실행
				cout << "왼쪽으로 이동합니다." << endl;
				// 이동에 따른 HP값 감소
				user->DecreaseHP(1); // 객체의 멤버 함수를 사용하여 1만큼 감소
				// 어떤 상태를 만났는지 판단 후 문구 출력, HP 증감
				checkState(map, user_x, user_y, *user); // 객체를 가리키는 포인터도 함께 인자로 넘겨, hp를 조절
				displayMap(map, user_x, user_y, user_choice);
			}
			else if (user_input == "right") {
				// TODO: 오른쪽으로 이동하기
				user_x += 1;
				bool inMap = checkXY(user_x, mapX, user_y, mapY);
				// 다시 돌아가기 위한 값 받아오기
				int moveValue = inMapFalse(inMap, user_x, user_y); // 맵을 벗어나는지 확인 후 throw 실행
				cout << "오른쪽으로 이동합니다." << endl;
				// 이동에 따른 HP값 감소
				user->DecreaseHP(1); // 객체의 멤버 함수를 사용하여 1만큼 감소
				// 어떤 상태를 만났는지 판단 후 문구 출력, HP 증감
				checkState(map, user_x, user_y, *user); // 객체를 가리키는 포인터도 함께 인자로 넘겨, hp를 조절
				displayMap(map, user_x, user_y, user_choice);
			}
			else if (user_input == "information") {
				// 현재 객체의 SpeakInformation()을 통해 문구 출력
				user->SpeakInformation();
			}
			else if (user_input == "map") {
				// TODO: 지도 보여주기 함수 호출
				displayMap(map, user_x, user_y, user_choice);
			}
			else if (user_input == "end") {
				cout << "종료합니다.";
				break;
			}
			else {
				// 지정된 명령어 외의 입력이 들어왔을 때 throw
				throw user_input;
			}

			// 목적지에 도달했는지 체크
			bool finish = checkGoal(map, user_x, user_y);
			if (finish == true) {
				cout << user_choice << "가 목적지에 도착했습니다! 축하합니다!" << endl;
				cout << "게임을 종료합니다." << endl;
				break;
			}

			// 플레이어의 HP가 0이하인지 확인
			if (user->GetHP() <= 0) { // 플레이어의 hp값이 0인지 체크하는 함수를 통해 확인
				cout << user_choice <<"의 HP가 0 이하가 되었습니다. 실패했습니다." << endl;
				cout << "게임을 종료합니다.";
				break;
			}
		} // 오류문 출력
		// 맵을 벗어난 경우 catch
		catch (bool e){
			cout << "맵을 벗어났습니다." << endl;

			// 잘못된 이동에 따라 좌표를 원래대로
			if (user_input == "up") user_y++;
			else if (user_input == "down") user_y--;
			else if (user_input == "left") user_x++;
			else if (user_input == "right") user_x--;
		}
		// 잘못된 입력의 경우 catch
		catch (string e) {
			cout << "잘못된 입력입니다." << endl;
		}
	}

	return 0;
}

// 지도와 사용자 위치 출력하는 함수
void displayMap(vector<vector<int>> map, int user_x, int user_y, string user_choice) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x && user_choice == "Magician") // 플레이어가 Magician인 경우
                cout << " MAGI |";
            else if (i == user_y && j == user_x && user_choice == "Warrior") // 플레이어가 Warrior인 경우
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
		// 맵을 벗어난 경우 (inMap == false) throw를 통해 오류문 출력
        throw inMap;
    }
    return 0;
}