#include <iostream>
#include <queue>
using namespace std;
struct node
{
    int time, weight;
};
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, w, L, curWeight = 0, curTime = 0;
    queue<int> wait;    // 진입 대기 중인 트럭
    queue<node> bridge; // 다리 위에 트럭
    cin >> n >> w >> L;
    while (n--)
    {
        int truck;
        cin >> truck;
        wait.push(truck);
    }

    while (!wait.empty()) // 진입 대기 중인 트럭을 모두 다리 위로 보내는 과정
    {
        ++curTime;
        if (!bridge.empty() && bridge.front().time + w <= curTime) // 다리가 비어있지 않다면 다리에서 나올 수 있는지 확인
        {
            curWeight -= bridge.front().weight;
            bridge.pop();
        }
        int nextWeight = wait.front();
        if (nextWeight + curWeight > L) // 무게를 초과한다면 무시
        {
            continue;
        }
        curWeight += nextWeight;
        bridge.push({curTime, nextWeight});
        wait.pop();
    }
    cout << curTime + w; // 다리 위에 있는 트럭이 모두 지나는 시간
    return 0;
}