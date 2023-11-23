#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int M;
    string word;
    deque<char> left, right;
    cin >> word;
    for (char c : word) // 뒤에 추가 후 포인터를 뒤로 이동
    {
        left.push_back(c);
    }

    cin >> M;
    while (M--)
    {
        char cmd;
        cin >> cmd;
        if (cmd == 'L') // 왼쪽을 오른쪽으로 넘기기
        {
            if (left.empty())
            {
                continue;
            }
            right.push_front(left.back());
            left.pop_back();
        }
        else if (cmd == 'D') // 오른쪽을 왼쪽으로 넘기기
        {
            if (right.empty())
            {
                continue;
            }
            left.push_back(right.front());
            right.pop_front();
        }
        else if (cmd == 'B') // 왼쪽 지우기
        {
            if (left.empty())
            {
                continue;
            }
            left.pop_back();
        }
        else if (cmd == 'P') // 왼쪽에 추가
        {
            cin >> cmd;
            left.push_back(cmd);
        }
    }

    // 왼쪽 먼저 소비 후 오른쪽 소비
    while (!left.empty())
    {
        cout << left.front();
        left.pop_front();
    }
    while (!right.empty())
    {
        cout << right.front();
        right.pop_front();
    }
    return 0;
}