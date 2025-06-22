#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

struct node
{
    string A;
    string B;
    string C;
    int count;

    string moveTop(const string &x)
    {
        string ret;
        for (int i = 0; i < x.size() - 1; ++i)
        {
            ret += x[i];
        }
        return ret;
    }
};

unordered_map<string, unordered_map<string, unordered_map<string, bool>>> isVisited;
queue<node> q;

void push(const string &A, const string &B, const string &C, const int &count)
{
    if (isVisited[A][B][C])
    {
        return;
    }

    isVisited[A][B][C] = true;

    q.push({A, B, C, count});
}

void inputDisks(string &x)
{
    int count;
    cin >> count;

    while (count--)
    {
        char c;
        cin >> c;
        x += c;
    }
}

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);

    node x;

    inputDisks(x.A);
    inputDisks(x.B);
    inputDisks(x.C);
    x.count = 0;

    push(x.A, x.B, x.C, x.count);
}

bool checkRod(const string &rod, const char diskType)
{
    for (char c : rod)
    {
        if (c != diskType)
        {
            return false;
        }
    }

    return true;
}

bool checkGoal(const node &x)
{
    return checkRod(x.A, 'A') && checkRod(x.B, 'B') && checkRod(x.C, 'C');
}

void bfs()
{
    while (!q.empty())
    {
        node curNode = q.front();
        q.pop();

        if (checkGoal(curNode))
        {
            cout << curNode.count;
            return;
        }

        int nextCount = curNode.count + 1;

        if (!curNode.A.empty())
        {
            char aBack = curNode.A.back();
            string A = curNode.moveTop(curNode.A);

            string B = curNode.B + aBack;
            string C = curNode.C + aBack;

            push(A, B, curNode.C, nextCount);
            push(A, curNode.B, C, nextCount);
        }

        if (!curNode.B.empty())
        {
            char bBack = curNode.B.back();
            string B = curNode.moveTop(curNode.B);

            string A = curNode.A + bBack;
            string C = curNode.C + bBack;

            push(curNode.A, B, C, nextCount);
            push(A, B, curNode.C, nextCount);
        }

        if (!curNode.C.empty())
        {
            char cBack = curNode.C.back();
            string C = curNode.moveTop(curNode.C);

            string A = curNode.A + cBack;
            string B = curNode.B + cBack;

            push(curNode.A, B, C, nextCount);
            push(A, curNode.B, C, nextCount);
        }
    }
}

int main()
{
    input();
    bfs();
    return 0;
}