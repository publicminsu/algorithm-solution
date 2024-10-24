#include <iostream>
#include <queue>
using namespace std;
string S, T;
queue<int> indexs[26];
int answer;

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> S >> T;

    for (int index = 0; index < S.size(); ++index)
    {
        indexs[S[index] - 'a'].push(index);
    }
}

bool isFind()
{
    int prevIndex = -1;
    for (char &c : T)
    {
        while (true)
        {
            int i = c - 'a';
            if (indexs[i].empty())
            {
                return false;
            }

            int nextIndex = indexs[i].front();
            indexs[i].pop();

            if (prevIndex < nextIndex)
            {
                prevIndex = nextIndex;
                break;
            }
        }
    }

    ++answer;
    return true;
}

int main()
{
    input();
    while (true)
    {
        if (!isFind())
        {
            break;
        }
    }
    cout << answer;
    return 0;
}