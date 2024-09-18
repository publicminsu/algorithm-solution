#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pic = pair<int, char>;
int N, I, D;
string S;
vector<pic> v;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    v = vector<pic>(N);

    for (pic &p : v)
    {
        cin >> S >> I >> D;
        p.first = I;

        char c = S[D - 1];
        if (c >= 'a')
        {
            c -= 32;
        }
        p.second = c;
    }

    sort(v.begin(), v.end());

    for (const pic &p : v)
    {
        cout << p.second;
    }
    return 0;
}