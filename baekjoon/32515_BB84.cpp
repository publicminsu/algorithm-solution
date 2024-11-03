#include <iostream>
using namespace std;
int N;
string str[4], answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 0; i < 4; ++i)
    {
        cin >> str[i];
    }

    answer.reserve(N);

    for (int i = 0; i < N; ++i)
    {
        if (str[0][i] == str[2][i])
        {
            if (str[1][i] == str[3][i])
            {
                answer += str[1][i];
            }
            else
            {
                cout << "htg!";
                return 0;
            }
        }
    }

    cout << answer;
    return 0;
}