#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pis = pair<int, string>;
using piis = pair<int, pis>;
vector<piis> guitars;
int N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    guitars = vector<piis>(N);

    for (piis &guitar : guitars)
    {
        cin >> guitar.second.second;

        guitar.first = guitar.second.second.size();

        int sum = 0;
        for (const char &c : guitar.second.second)
        {
            if ('0' <= c && '9' >= c)
            {
                sum += c - '0';
            }
        }

        guitar.second.first = sum;
    }

    sort(guitars.begin(), guitars.end());

    for (const piis &guitar : guitars)
    {
        cout << guitar.second.second << "\n";
    }
    return 0;
}