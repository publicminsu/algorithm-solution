#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string bar;
    cin >> bar;
    int pipe = 1, sum = 0;
    for (int i = 1; i < bar.size(); ++i)
    {
        if (bar[i] == '(')
        {
            ++pipe;
        }
        else
        {
            --pipe;
            if (bar[i - 1] == '(') // 레이저 확인
            {
                sum += pipe; // 자르기
            }
            else
            {
                ++sum; // 막대기 끝
            }
        }
    }
    cout << sum;
    return 0;
}