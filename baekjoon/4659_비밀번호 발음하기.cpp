#include <iostream>
using namespace std;
string password;
bool isAcceptable()
{
    int cnt1 = 0, cnt2 = 0;
    bool isFind = false;
    for (int i = 0; i < password.size(); ++i)
    {
        if (!(password[i] == 'e' || password[i] == 'o')) // e 또는 o가 아닌 경우
        {
            if (i + 1 < password.size() && password[i] == password[i + 1]) // 연속하는지 확인
            {
                return false;
            }
        }
        if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u') // 모음인 경우
        {
            isFind = true;
            ++cnt1;
            cnt2 = 0;
            if (cnt1 == 3)
            {
                return false;
            }
        }
        else // 자음인 경우
        {
            ++cnt2;
            cnt1 = 0;
            if (cnt2 == 3)
            {
                return false;
            }
        }
    }
    return isFind;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (true)
    {
        cin >> password;
        if (password == "end")
        {
            break;
        }
        cout << "<" << password << "> is " << (isAcceptable() ? "acceptable." : "not acceptable.") << "\n";
    }
    return 0;
}