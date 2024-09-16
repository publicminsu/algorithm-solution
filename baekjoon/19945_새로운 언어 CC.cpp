#include <cstdio>
int n, answer;
int main()
{
    scanf("%d", &n);
    if (n < 0)
    {
        answer = 32;
    }
    else
    {
        if (n == 0)
        {
            answer = 1;
        }
        while (n)
        {
            n >>= 1;
            ++answer;
        }
    }
    printf("%d", answer);
}