#include <iostream>
#include <algorithm>
using namespace std;

int T;
string word;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> word;

        if (!next_permutation(word.begin(), word.end()))
        {
            prev_permutation(word.begin(), word.end());
        }

        cout << word << "\n";
    }

    return 0;
}