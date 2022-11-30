#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, l, time = 0, dir = 0;
    int xPos[] = {1, 0, -1, 0}, yPos[] = {0, -1, 0, 1}; // 오른쪽 90도 +1 왼쪽 90도 -1
    bool appleBoard[101][101];
    bool bodyBoard[101][101];
    queue<pair<int, int>> snake;
    queue<pair<int, int>> dirTurn;
    cin >> n >> k;
    memset(appleBoard, false, sizeof(appleBoard));
    memset(bodyBoard, false, sizeof(bodyBoard));
    for (int i = 0; i < k; ++i)
    {
        int x, y;
        cin >> y >> x;
        appleBoard[x - 1][n - y] = true;
    }
    cin >> l;
    for (int i = 0; i < l; ++i)
    {
        int t;
        char d;
        cin >> t >> d;
        dirTurn.push({t, d == 'L' ? -1 : 1});
    }
    snake.push({0, n - 1}); // 맨위 맨좌측
    bodyBoard[0][n - 1] = true;
    while (true)
    {
        time++;
        int count = 0;
        pair<int, int> next;
        bool eatApple = false;

        while (count < snake.size())
        {
            if (count == 0) // 머리 사과, 몸통 충돌을 감지하고 앞서간다.
            {
                next = snake.front();
                snake.pop();
                pair<int, int> headPos = {next.first + xPos[dir],
                                          next.second + yPos[dir]};
                if (headPos.first < 0 || headPos.first >= n || headPos.second < 0 || headPos.second >= n || bodyBoard[headPos.first][headPos.second])
                {
                    cout << time;
                    return 0;
                }
                if (appleBoard[headPos.first][headPos.second])
                {
                    eatApple = true;
                    appleBoard[headPos.first][headPos.second] = false;
                }
                bodyBoard[headPos.first][headPos.second] = true;
                snake.push({headPos.first, headPos.second});
            }
            else // 몸통 : 앞부분을 따라간다.
            {
                pair<int, int> temp = snake.front();
                snake.pop();
                snake.push(next);
                next = temp;
            }
            ++count;
        }
        if (eatApple) // 꼬리 : 사과를 먹으면 몸통은 증가한다.
        {
            snake.push(next);
        }
        else // 아니면 꼬리 부분이 빠져줘야 한다.
        {
            bodyBoard[next.first][next.second] = false;
        }
        if (!dirTurn.empty() && dirTurn.front().first == time) // 방향 결정
        {
            dir += dirTurn.front().second + 4;
            dir %= 4;
            dirTurn.pop();
        }
    }
    return 0;
}