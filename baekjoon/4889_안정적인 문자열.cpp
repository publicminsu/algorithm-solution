#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string str;
    int index = 1, answer, cnt;
    while (true)
    {
        answer = cnt = 0;

        cin >> str;

        if (str.front() == '-') // 마지막 줄
        {
            break;
        }

        for (char &c : str)
        {
            if (c == '{') // 여는 괄호
            {
                ++cnt;
            }
            else // 닫는 괄호
            {
                if (cnt == 0) // 여는 괄호가 없다면
                {
                    ++answer;
                }
                else
                {
                    --cnt;
                }
            }
        }

        cout << index++ << ". " << (answer + 1) / 2 + (cnt + 1) / 2 << "\n";
    }
    return 0;
}