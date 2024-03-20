#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<string> id, newId;
int N, len, k;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    id = newId = vector<string>(N);
    for (string &i : id)
    {
        cin >> i;
    }

    len = id[0].size();

    while (true)
    {
        map<string, bool> m;
        bool isFind = true;

        ++k;

        for (int i = 0; i < id.size(); ++i)
        {
            newId[i] += id[i][len - k];

            if (m[newId[i]]) // 만약 이미 사용한 문자면
            {
                isFind = false;
            }
            m[newId[i]] = true;
        }

        if (isFind)
        {
            break;
        }
    }

    cout << k;
    return 0;
}