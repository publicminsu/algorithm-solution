#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int r, c, s;
};

int N, A, B, answer;

vector<node> nodes;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> A >> B;

    nodes = vector<node>(N);

    for (node &n : nodes)
    {
        cin >> n.r >> n.c >> n.s;
    }

    for (int i = 0; i < N; ++i)
    {
        node s = nodes[i];

        for (int j = i + 1; j < N; ++j)
        {
            node e = nodes[j];

            if (abs(s.r - e.r) < A && abs(s.c - e.c) < B)
            {
                answer = max(answer, abs(s.s - e.s));
            }
        }
    }

    cout << answer;
    return 0;
}