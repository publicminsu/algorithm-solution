#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> boxes;
int n, box;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    boxes.reserve(n);

    while (n--)
    {
        cin >> box;

        vector<int>::iterator iter = lower_bound(boxes.begin(), boxes.end(), box); // 처음으로 같거나 큰 값 찾기

        if (iter == boxes.end()) // 존재하지 않으면 뒤에 추가
        {
            boxes.push_back(box);
        }
        else // 존재하면 교체
        {
            *iter = box;
        }
    }

    cout << boxes.size();
    return 0;
}