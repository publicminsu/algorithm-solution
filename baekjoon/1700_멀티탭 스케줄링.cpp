#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> sched, used;
vector<priority_queue<int, vector<int>, greater<int>>> schedQ;
bool isUsed(int i)
{
    for (int j : used)
        if (j == sched[i])
            return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N, K, cnt = 0, initNum = 0;
    cin >> N >> K;
    schedQ = vector<priority_queue<int, vector<int>, greater<int>>>(K + 1, priority_queue<int, vector<int>, greater<int>>());
    for (int i = 0; i < K; ++i)
    {
        int obj;
        cin >> obj;
        sched.push_back(obj);
        schedQ[obj].push(i);
    }
    for (int i = 0; i < K; ++i)
    {
        if (!isUsed(i)) // 이미 사용중인 장비를 추가할 필요가 없다.
        {
            used.push_back(sched[i]);
            ++initNum;
            if (initNum == N)
                break;
        }
    }
    for (int i = initNum; i < K; ++i)
    {
        if (isUsed(i)) // 이미 사용중인 경우라면 뽑을 필요가 없다.
            continue;
        ++cnt;
        int target = 0, far = 0;
        for (int j = 0; j < used.size(); ++j)
        {
            int device = used[j];
            while (!schedQ[device].empty() && schedQ[device].top() < i) // 현재 시간보다 작은 값들은 이미 지나간 기회다.
                schedQ[device].pop();
            if (schedQ[device].empty()) // 없다면 더 이상 사용할 일이 없다.
            {
                target = j;
                break;
            }
            if (schedQ[device].top() > far)
            {
                target = j;
                far = schedQ[device].top();
            }
        }
        used[target] = sched[i];
    }
    cout << cnt;
}