#include <iostream>
#include <vector>
using namespace std;
int prevNum, curNum, N;
long long answer, len;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    while (N--)
    {
        cin >> curNum;
        if (curNum > prevNum) // 만약 오름차순이면 길이 증가
        {
            ++len;
        }
        else // 오름차순이 아니면 초기화
        {
            answer += (len + 1) * len / 2;
            len = 1;
        }
        prevNum = curNum;
    }
    answer += (len + 1) * len / 2;
    cout << answer;
    return 0;
}