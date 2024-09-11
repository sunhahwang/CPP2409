# include <iostream>
# include <string>
using namespace std;

int main()
{
    int money;
    int price;
    int max_candy;
    int remain_money;

    cout << "현재 가지고 있는 돈 : ";
    cin >> money;
    cout << "캔디의 가격 : ";
    cin >> price;
    max_candy = money / price;
    remain_money = money % price;

    cout << "최대로 살 수 있는 캔디 = " << max_candy << endl;
    cout << "캔디 구입 후 남은 돈 = " << remain_money << endl;

    return 0;
}