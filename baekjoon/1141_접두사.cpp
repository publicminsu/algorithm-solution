#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
string arr[50];
vector<string> v;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N, greater<string>());

    v.reserve(50);

    for (int i = 0; i < N; ++i)
    {
        bool isPrefix = false;

        for (int j = 0; j < v.size(); ++j)
        {
            string str1 = arr[i];
            string str2 = v[j];

            if (str1.length() > str2.length())
            {
                swap(str1, str2);
            }

            bool isFind = true;

            for (int k = 0; k < str1.length(); ++k)
            {
                if (str1[k] != str2[k])
                {
                    isFind = false;
                }
            }

            if (isFind)
            {
                isPrefix = true;
                break;
            }
        }

        if (!isPrefix)
        {
            v.push_back(arr[i]);
        }
    }

    cout << v.size();
    return 0;
}