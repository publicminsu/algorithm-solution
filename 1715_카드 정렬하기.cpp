#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int, vector<int>, greater<int>> lq;
    int N, ret = 0;
    cin >> N;
    while (N--)
    {
        int n;
        cin >> n;
        lq.push(n);
    }
    while (lq.size() != 1)
    {
        int first = lq.top();
        lq.pop();
        int second = lq.top();
        lq.pop();
        ret += first + second;
        lq.push(first + second);
    }
    cout << ret;
    return 0;
}