#include <iostream>
using namespace std;
int cnt[3], N;
char alpha[3] = {'B', 'S', 'A'};
string note;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> note;

    for (char c : note)
    {
        switch (c)
        {
        case 'A':
            ++cnt[2];
            break;
        case 'B':
            ++cnt[0];
            break;
        default:
            ++cnt[1];
            break;
        }
    }

    if (cnt[0] == cnt[1] && cnt[1] == cnt[2]) // 3개의 수가 같으면
    {
        cout << "SCU";
    }
    else
    {
        int val = max(max(cnt[0], cnt[1]), cnt[2]); // 가장 큰 값 찾기
        for (int i = 0; i < 3; ++i)
        {
            if (cnt[i] == val)
            {
                cout << alpha[i];
            }
        }
    }
    return 0;
}