#include <iostream>
#include <deque>
using namespace std;

int N, Q, C;
int CAP[2001];

int currentCache;
int currentPage = -1;
deque<int> backHistory;
deque<int> forwardHistory;

void playBack()
{
    if (backHistory.empty())
    {
        return;
    }

    forwardHistory.push_back(currentPage);
    currentPage = backHistory.back();
    backHistory.pop_back();
}

void playForward()
{
    if (forwardHistory.empty())
    {
        return;
    }

    backHistory.push_back(currentPage);
    currentPage = forwardHistory.back();
    forwardHistory.pop_back();
}

void visitPage()
{
    int nextPage;
    cin >> nextPage;

    while (!forwardHistory.empty())
    {
        int page = forwardHistory.back();
        forwardHistory.pop_back();
        currentCache -= CAP[page];
    }

    if (currentPage != -1)
    {
        backHistory.push_back(currentPage);
    }

    currentPage = nextPage;
    currentCache += CAP[currentPage];

    while (currentCache > C && !backHistory.empty())
    {
        int page = backHistory.front();
        backHistory.pop_front();

        currentCache -= CAP[page];
    }
}

void compress()

{
    int prevPage = -1;

    int size = backHistory.size();

    for (int i = 0; i < size; ++i)
    {
        int page = backHistory.back();
        backHistory.pop_back();

        if (prevPage != page)
        {
            backHistory.push_front(page);
            prevPage = page;
        }
        else
        {
            currentCache -= CAP[page];
        }
    }
}

void printHistory(deque<int> &history)
{
    if (history.empty())
    {
        cout << -1;
    }
    else
    {
        while (!history.empty())
        {
            cout << history.back() << " ";
            history.pop_back();
        }
    }
    cout << "\n";
}

void printResult()
{
    cout << currentPage << "\n";

    printHistory(backHistory);
    printHistory(forwardHistory);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> Q >> C;

    for (int i = 1; i <= N; ++i)
    {
        cin >> CAP[i];
    }

    while (Q--)
    {
        char cmd;
        cin >> cmd;

        switch (cmd)
        {
        case 'B':
            playBack();
            break;
        case 'F':
            playForward();
            break;
        case 'A':
            visitPage();
            break;
        default:
            compress();
            break;
        }
    }

    printResult();
    return 0;
}