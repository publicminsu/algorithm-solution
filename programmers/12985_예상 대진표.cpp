#include <iostream>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while (true)
    {
        if (a == b)
        {
            break;
        }
        a = ((a + 1) >> 1);
        b = ((b + 1) >> 1);
        ++answer;
    }

    return answer;
}