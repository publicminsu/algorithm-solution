#include <iostream>
using namespace std;
string str;
int N, sum;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    cin.ignore();

    while (N--)
    {
        getline(cin, str);

        sum = 0;

        for (char c : str)
        {
            if (c >= 'A' && c <= 'Z')
            {
                sum += c - 'A' + 1;
            }
        }

        cout << (sum == 100 ? "PERFECT LIFE" : to_string(sum)) << "\n";
    }
    return 0;
}