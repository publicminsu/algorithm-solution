#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define bucketCnt 2
using namespace std;
map<pair<int, int>, int> visted;
int abcd[4];
struct node
{
    int bucket[bucketCnt];
};
queue<node> q;
void input(node prevNode, node nextNode)
{
    if (!visted[{nextNode.bucket[0], nextNode.bucket[1]}])
    {
        visted[{nextNode.bucket[0], nextNode.bucket[1]}] = visted[{prevNode.bucket[0], prevNode.bucket[1]}] + 1;
        if (nextNode.bucket[0] == abcd[2] && nextNode.bucket[1] == abcd[3])
        {
            cout << visted[{nextNode.bucket[0], nextNode.bucket[1]}] - 1;
            exit(0);
        }
        q.push(nextNode);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> abcd[0] >> abcd[1] >> abcd[2] >> abcd[3];
    if (!abcd[2] && !abcd[3])
    {
        cout << 0;
        return 0;
    }
    q.push({0, 0});
    visted[{0, 0}] = 1;
    while (!q.empty())
    {
        node cur = q.front();
        q.pop();
        for (int i = 0; i < bucketCnt; ++i)
        {
            node next = {cur.bucket[0], cur.bucket[1]};

            node move = next;
            int j = (i + 1) % bucketCnt;
            move.bucket[j] += move.bucket[i];
            move.bucket[i] = 0;
            if (abcd[j] < move.bucket[j])
            {
                move.bucket[i] = move.bucket[j] - abcd[j];
                move.bucket[j] = abcd[j];
            }
            input(cur, move);

            next.bucket[i] = abcd[i];
            input(cur, next);

            next.bucket[i] = 0;
            input(cur, next);
        }
    }
    cout << -1;
    return 0;
}