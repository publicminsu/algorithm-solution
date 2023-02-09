#include <iostream>
#include <vector>
using namespace std;
int N, target, ret = 0;
vector<int> numArr;
void choice(int idx, int sum, bool isSelect)
{
    if (idx == N)
    {
        if (isSelect && target == sum)
        {
            ++ret;
        }
        return;
    }
    choice(idx + 1, sum, isSelect);
    choice(idx + 1, sum + numArr[idx], true);
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> target;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        numArr.push_back(num);
    }
    choice(0, 0, false);
    cout << ret;
    return 0;
}