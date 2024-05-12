#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using psi = pair<string, int>;
string nums[] = {"z", "o", "tw", "th", "fo", "fi", "si", "se", "e", "n"};
vector<psi> v;
int M, N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> M >> N;

    v.reserve(N - M + 1);

    for (int i = M; i <= N; ++i)
    {
        string str;

        int ten = i / 10;

        if (ten)
        {
            str = nums[ten];
        }

        str += nums[i % 10];

        v.push_back({str, i});
    }

    sort(v.begin(), v.end());

    for (int i = 0, ten = 0; i < v.size(); ++i)
    {
        cout << v[i].second << " ";
        if (++ten == 10)
        {
            ten = 0;
            cout << "\n";
        }
    }
    return 0;
}