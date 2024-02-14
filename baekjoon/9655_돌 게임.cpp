#include <cstdio>
int N;
int main()
{
    scanf("%d", &N);
    printf("%s", (N % 2 ? "SK" : "CY"));
    return 0;
}