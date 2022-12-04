#include <iostream>
#include <map>
using namespace std;
map<char, pair<char, char>> tree;
void left(char p)
{
    if (p == '.')
        return;
    cout << p;
    left(tree[p].first);
    left(tree[p].second);
}
void mid(char p)
{
    if (p == '.')
        return;
    mid(tree[p].first);
    cout << p;
    mid(tree[p].second);
}
void right(char p)
{
    if (p == '.')
        return;
    right(tree[p].first);
    right(tree[p].second);
    cout << p;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        char p, c1, c2;
        cin >> p >> c1 >> c2;
        tree[p] = {c1, c2};
    }
    left('A');
    cout << '\n';
    mid('A');
    cout << '\n';
    right('A');
    return 0;
}