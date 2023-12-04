#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int myVote, vote, n, ret = 1;
    cin >> n >> myVote;
    while (--n)
    {
        cin >> vote;
        if (myVote < vote)
        {
            ++ret;
        }
    }
    cout << ret;
    return 0;
}