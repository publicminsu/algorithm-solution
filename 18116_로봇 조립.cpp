#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000001
int component[MAX], sum[MAX];
int find(int a)
{
    if (component[a])
        return component[a] = find(component[a]);
    else
        return a;
}
void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (!sum[a])
        sum[a] = 1;
    if (!sum[b])
        sum[b] = 1;
    if (a > b)
    {
        component[b] = a;
        sum[a] += sum[b];
    }
    else if (a < b)
    {
        component[a] = b;
        sum[b] += sum[a];
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, a, b;
    char cmd;
    cin >> N;
    while (N--)
    {
        cin >> cmd;
        if (cmd == 'I')
        {
            cin >> a >> b;
            merge(a, b);
        }
        else
        {
            cin >> a;
            a = find(a);
            if (sum[a])
                cout << sum[a];
            else
                cout << 1;
            cout << "\n";
        }
    }
    return 0;
}