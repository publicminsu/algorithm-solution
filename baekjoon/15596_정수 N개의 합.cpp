#include <vector>
using namespace std;

long long sum(vector<int> &a)
{
    long long ret = 0;

    for (int i : a)
    {
        ret += i;
    }

    return ret;
}
