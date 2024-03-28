#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
string A, B;
int alpha[] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
int l, r;
queue<int> q, nextQ;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> A >> B;
    for (int i = 0; i < A.size(); ++i)
    {
        q.push(alpha[A[i] - 'A']);
        q.push(alpha[B[i] - 'A']);
    }

    while (true)
    {
        l = q.front();
        q.pop();

        while (!q.empty())
        {
            r = q.front();
            nextQ.push((l + r) % 10);
            l = r;
            q.pop();
        }

        q = nextQ;
        nextQ = queue<int>();

        if (q.size() == 2)
        {
            break;
        }
    }

    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }
    return 0;
}