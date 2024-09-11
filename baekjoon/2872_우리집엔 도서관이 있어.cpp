#include <iostream>
#include <stack>
using namespace std;
int N;
stack<int> books;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    for (int i = 0, j; i < N; ++i)
    {
        cin >> j;

        while (!books.empty() && books.top() < j && books.top() + 1 != j)
        {
            books.pop();
        }

        if (books.empty() || books.top() + 1 == j)
        {
            books.push(j);
        }
    }

    cout << N - books.size();
    return 0;
}