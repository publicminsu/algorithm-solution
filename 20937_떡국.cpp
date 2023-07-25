#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, ret = 0, bowl;
    cin >> N;
    vector<int> v(50001);
    while (N--)
    {
        cin >> bowl;
        v[bowl]++;
        ret = v[bowl] > ret ? v[bowl] : ret;
    }
    cout << ret;
    return 0;
}