#include <iostream>
#include <set>
typedef unsigned long long ull;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    set<ull> s; // 중복을 제거하는 set
    ull min, max;
    cin >> min >> max;
    for (ull i = 2; i * i <= max; ++i)
    {
        ull j = (min / (i * i)); // 제곱수로 나누었을 때 값이 가장 가까운 제곱수의 m
        if (min % (i * i))       // 나머지가 있다면 n^2*m보다 크다는 것이므로 +1
            ++j;
        for (j *= (i * i); j <= max; j += i * i) // 제곱수만큼 커짐 (제곱수에 나누어떨어지므로)
        {
            s.insert(j);
        }
    }
    ull ret = max - min + 1 - s.size(); // 범위 내 수의 개수에서 제곱수로 나누어지는 수의 개수만큼 빼기
    cout << ret;
    return 0;
}