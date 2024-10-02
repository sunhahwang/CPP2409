#include <iostream>
using namespace std;

int main() {
    const int numCell = 3;
    char board[numCell][numCell]{};
    int x, y; // 사용자에게 입력받는 x, y 좌표를 저장할 변수

    // 보드판 초기화
    for (x = 0; x < numCell; x++){
        for (y = 0; y < numCell; y++){
            board[x][y] = ' ';
        }
    }

    // 게임하는 코드
    int k = 0; // 누구 차례인지 체크하기 위한 변수
    char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 변수;
    while (true) {
        // 1. 누구 차례인지 출력
        switch (k % 2) {
        case 0:
            cout << "첫 번째 유저(X)의 차례입니다 -> ";
            currentUser = 'X';
            break;
        case 1:
            cout << "두 번째 유저(0)의 차례입니다 -> ";
            currentUser = '0';
            break;
        }

        // 2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요 : ";     
        cin >> y >> x;           // x, y 좌표를 제대로 입력받기 위한 수정

        // 3. 입력받은 좌표의 유효성 체크
        if (x >= numCell || y >= numCell){ 
            cout << x << ", " << y << ": ";
            cout << "x와 y 둘 중 하나가 칸은 벗어납니다." << endl;
            continue;
        }
        if (board[x][y] != ' '){
            cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
            continue;
        }

        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드 판 출력
        for (int i = 0; i < numCell; i++){
            cout << "---|---|---" << endl;
            for (int j = 0; i < numCell; j++){
                cout << board[i][j];
                if(j == numCell - 1) {
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;
        k++;

        // 6. 빙고 시 승자 출력 후 종료
        bool win = false;

        // 가로와 세로 판단
        for (int i = 0; i < numCell; i++) {
            if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser ){
                win = true;
            }
            if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser ){
                win = true;
            }
        }
        // 대각선 판단
        if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
            win = true;
        }
        if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
            win = true;
        } 

        if (win == true) {
            cout << currentUser<< "의 승리입니다." << endl;
            break;
        }

        // 7. 모든 칸이 찼으면 종료
        int full = 0;
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                if (board[i][j] != ' ') 
                    continue;
                else
                    full++;
            }
        }

        if (full == 0) {
            cout << "모든 칸이 찼습니다." << endl;
            break;
        }
    }
    return 0;
}