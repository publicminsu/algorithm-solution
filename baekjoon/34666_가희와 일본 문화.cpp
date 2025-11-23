#include <iostream>
using namespace std;

int Q;
int grade, langScore, readingScore, listeningScore;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> Q;

    while (Q--)
    {
        cin >> grade >> langScore >> readingScore >> listeningScore;

        if (grade <= 2 && listeningScore >= 50)
        {
            int cutOff = grade == 1 ? 100 : 90;

            if (langScore * 3 < cutOff && readingScore * 3 < cutOff)
            {
                cout << "YES";
            }
            else if (langScore <= 21 || readingScore <= 21)
            {
                cout << "YES";
            }
            else
            {
                cout << "NO";
            }
        }
        else
        {
            cout << "NO";
        }

        cout << "\n";
    }
    return 0;
}