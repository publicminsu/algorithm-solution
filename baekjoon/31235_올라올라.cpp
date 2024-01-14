#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, answer = 1, curNum, prevNum, cnt = 1;
    cin >> N;
    cin >> prevNum;
    while (--N)
    {
        cin >> curNum;
        if (curNum < prevNum) // 감소하는 부분
        {
            ++cnt;
        }
        else // 감소하지 않는 부분
        {
            answer = max(answer, cnt);
            cnt = 1;
            prevNum = curNum;
        }
    }
    cout << max(answer, cnt);
    return 0;
}