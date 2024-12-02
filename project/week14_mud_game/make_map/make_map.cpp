// map.txt 파일 생성

#include <iostream>
#include <fstream>
using namespace std;

// 맵의 크기
const int mapX = 5;
const int mapY = 5;

int main() {
    // 파일 생성
    ofstream os{ "map.txt" };
    if (!os) {
        cerr << "파일 오픈에 실패하였습니다." << endl;
        exit(1);
    }
    
    // 맵을 나타내는 배열
    int map[mapY][mapX] = {{0, 1, 2, 0, 4},
                        {1, 0, 0, 2, 0},
                        {0, 0, 0, 0, 0},
                        {0, 2, 3, 0, 0},
                        {3, 0, 0, 0, 2}};

    // 배열에서 값을 차례로 읽어, txt파일에 적기
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            os << map[i][j] << " ";
        }
        os << endl;
    }
    return 0;
}