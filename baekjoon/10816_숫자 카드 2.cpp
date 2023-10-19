#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> card;
int binarySearch(int start, int end, int target)
{
    if (start == end)
        return start;
    int mid = (start + end) >> 1;
    if (target <= card[mid])
        return binarySearch(start, mid, target);
    else
        return binarySearch(mid + 1, end, target);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    card = vector<int>(N);
    for (int i = 0; i < N; ++i)
        cin >> card[i];
    sort(card.begin(), card.end());
    cin >> M;
    while (M--)
    {
        int target, start, end;
        cin >> target;
        start = binarySearch(0, N, target);
        if (card[start] != target)
            cout << 0;
        else
        {
            end = binarySearch(0, N, target + 1);
            cout << end - start;
        }
        cout << " ";
    }
    return 0;
}