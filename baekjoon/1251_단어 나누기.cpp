#include <iostream>
using namespace std;
string answer, str;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> str;

    for (int i = 0; i < str.size() - 2; ++i)
    {
        for (int j = i + 1; j < str.size() - 1; ++j)
        {
            for (int k = j + 1; k < str.size(); ++k)
            {
                string temp = "";

                for (int l = j - 1; l >= 0; --l)
                {
                    temp += str[l];
                }
                for (int l = k - 1; l >= j; --l)
                {
                    temp += str[l];
                }
                for (int l = str.size() - 1; l >= k; --l)
                {
                    temp += str[l];
                }

                if (answer.empty())
                {
                    answer = temp;
                }
                answer = min(answer, temp);
            }
        }
    }

    cout << answer;
    return 0;
}