#include <iostream>
#include <vector>
using namespace std;
int N, K, Q, qIdx;
int unreadCnt[26];
bool hasUnread;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K >> Q;

    for (int i = 0; i < Q; ++i)
    {
        int r;
        char p;
        cin >> r >> p;

        int pIdx = p - 'A';
        unreadCnt[pIdx] = r;
        qIdx = pIdx;
    }

    for (int i = Q; i < K; ++i)
    {
        int r;
        char p;
        cin >> r >> p;

        unreadCnt[p - 'A'] = unreadCnt[qIdx];
    }

    for (int i = 1; i < N; ++i)
    {
        if (unreadCnt[i] != unreadCnt[qIdx])
        {
            cout << (char)(i + 'A') << " ";
            hasUnread = true;
        }
    }

    if (!hasUnread)
    {
        cout << -1;
    }

    return 0;
}