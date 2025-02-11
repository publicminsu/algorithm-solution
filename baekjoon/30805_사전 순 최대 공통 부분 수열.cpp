#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> A, B, answer;

void arrayInput(vector<int> &arr)
{
    int size;
    cin >> size;

    arr = vector<int>(size);

    for (int &i : arr)
    {
        cin >> i;
    }
}

vector<int> GetSortedArray(int start, vector<int> &arr)
{
    vector<int> ret = vector<int>(arr.begin() + start, arr.end());
    sort(ret.begin(), ret.end(), greater<int>());
    return ret;
}

int findValue(int start1, int start2, vector<int> &arr1, vector<int> &arr2)
{
    auto sortedArr1 = GetSortedArray(start1, arr1);
    auto sortedArr2 = GetSortedArray(start2, arr2);

    int cur1 = 0;
    int cur2 = 0;

    while (cur1 < sortedArr1.size() && cur2 < sortedArr2.size())
    {
        if (sortedArr1[cur1] == sortedArr2[cur2])
        {
            return sortedArr1[cur1];
        }
        else if (sortedArr1[cur1] > sortedArr2[cur2])
        {
            ++cur1;
        }
        else
        {
            ++cur2;
        }
    }

    return -1;
}

int findIndex(int start, int value, vector<int> &arr)
{
    for (int i = start; i < arr.size(); ++i)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }

    return arr.size();
}

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    arrayInput(A);
    arrayInput(B);

    answer.reserve(max(A.size(), B.size()));

    int aStart = 0;
    int bStart = 0;

    while (true)
    {
        int value = findValue(aStart, bStart, A, B);

        if (value == -1)
        {
            break;
        }

        answer.push_back(value);

        aStart = findIndex(aStart, value, A) + 1;
        bStart = findIndex(bStart, value, B) + 1;
    }

    cout << answer.size() << "\n";

    for (int &i : answer)
    {
        cout << i << " ";
    }
}

int main()
{
    input();
    return 0;
}