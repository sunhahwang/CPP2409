# include <iostream>
# include <string>
using namespace std;

int main()
{
    float f_temp;
    float c_temp;

    cout << "화씨온도 : ";
    cin >> f_temp;
    c_temp = (5.0 / 9.0) * (f_temp - 32);
    cout << "섭씨온도 : " << c_temp << endl;

    return 0;
}