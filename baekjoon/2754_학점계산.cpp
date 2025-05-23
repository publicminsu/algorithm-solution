#include <iostream>
using namespace std;

string str;
float score;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> str;

    if (str == "F")
    {
        score = 0;
    }
    else
    {
        score = 4 - (str[0] - 'A');

        switch (str[1])
        {
        case '+':
            score += 0.3;
            break;
        case '-':
            score -= 0.3;
            break;
        }
    }

    cout << fixed;
    cout.precision(1);

    cout << score;
    return 0;
}