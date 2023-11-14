#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct node
{
    string num;
    int depth;
};
string ret = "", N;
int K;
bool isVisited[1000001];
void updateRet(string &num)
{
    if (ret.empty())
    {
        ret = num;
    }
    else if (num > ret)
    {
        ret = num;
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    queue<node> q;
    q.push({N, 0});
    while (!q.empty())
    {
        node cur = q.front();
        q.pop();

        if (cur.depth == K) // K만큼 확인한 경우
        {
            updateRet(cur.num);
            continue;
        }

        for (int i = 0; i < N.size() - 1; ++i)
        {
            for (int j = i + 1; j < N.size(); ++j)
            {
                if (!i && cur.num[j] == '0') // 첫 자리와 0을 바꾸려는 경우
                {
                    continue;
                }

                string nextNum = cur.num;
                swap(nextNum[i], nextNum[j]);

                if ((K - cur.depth) & 1) // 만약 다음 남은 횟수가 짝수일 경우
                {
                    int nextInt = stoi(nextNum);

                    if (isVisited[nextInt]) // 이미 도착했는지 확인
                    {
                        continue;
                    }
                    else // 이미 짝수로 도착했다면 다시 도착할 필요가 없다.
                    {
                        isVisited[nextInt] = true;
                        updateRet(nextNum); // 같은 값을 유지할 수 있기에 갱신
                    }
                }
                q.push({nextNum, cur.depth + 1});
            }
        }
    }
    if (ret.empty())
    {
        cout << -1;
    }
    else
    {
        cout << ret;
    }
    return 0;
}