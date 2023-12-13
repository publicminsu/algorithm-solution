#include <iostream>
#include <string>
using namespace std;
void errorEnd()
{
    cout << "Error!";
    exit(0);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string var, ret;
    int type = 0;
    cin >> var;
    ret.reserve(var.size());
    if (!islower(var.front()) || var.back() == '_') // 맨 앞, 뒤가 밑줄이거나 맨 앞이 대문자인 경우
    {
        errorEnd();
    }
    for (int i = 0; i < var.size(); ++i)
    {
        if (var[i] == '_') // 밑줄일 경우 밑줄 건너뛰고 대문자로
        {
            if (type == 2) // 타입이 다른 경우
            {
                errorEnd();
            }
            type = 1;
            if (!islower(var[i + 1])) // 다음 거가 밑줄이거나 대문자인 경우
            {
                errorEnd();
            }
            ret.push_back(static_cast<char>(var[i + 1] - 32));
            ++i;
        }
        else if (isupper(var[i])) // 대문자일 경우 밑줄 추가하고 소문자로
        {
            if (type == 1) // 타입이 다른 경우
            {
                errorEnd();
            }
            type = 2;
            ret.push_back('_');
            ret.push_back(static_cast<char>(var[i] + 32));
        }
        else
        {
            ret.push_back(var[i]);
        }
    }
    cout << ret;
    return 0;
}