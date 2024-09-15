#include <iostream>
using namespace std;
int N;

bool isSame(string seq, int i, int size)
{
    for (int j = 0; j < i; ++j)
    {
        int k = size - j - 1;

        if (seq[k] != seq[k - i])
        {
            return false;
        }
    }

    return true;
}

bool isGood(string seq)
{
    int size = seq.size();

    for (int i = 1; i <= size / 2; ++i)
    {
        if (isSame(seq, i, size))
        {
            return false;
        }
    }

    return true;
}

void dfs(string seq)
{
    if (!isGood(seq))
    {
        return;
    }

    if (seq.size() == N)
    {
        cout << seq;
        exit(0);
    }

    for (char i = '1'; i <= '3'; ++i)
    {
        dfs(seq + i);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    dfs("");
    return 0;
}