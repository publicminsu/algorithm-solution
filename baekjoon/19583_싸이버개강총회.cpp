#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string, int> nicknames;
string S, E, Q, time, nickname;
int answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> S >> E >> Q;

    while (cin >> time >> nickname)
    {
        if (time <= S) // 개강총회를 시작하기 전에 입장한 경우
        {
            nicknames[nickname] = 1;
        }
        else if (time >= E && time <= Q) // 시간 안에 채팅을 친 경우
        {
            if (nicknames[nickname] == 1)
            {
                nicknames[nickname] = 2; // 중복 채팅을 무시하기 위해 2로 변경
                ++answer;
            }
        }
    }

    cout << answer;
    return 0;
}