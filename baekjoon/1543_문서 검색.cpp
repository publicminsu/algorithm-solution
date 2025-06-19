#include <iostream>
using namespace std;

string file, word;
int cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    getline(cin, file);
    getline(cin, word);

    int fileSize = file.size();
    int wordSize = word.size();

    for (int i = 0; i <= fileSize - wordSize;)
    {
        bool isFind = true;

        for (int j = 0; j < wordSize; ++j)
        {
            if (file[i + j] != word[j])
            {
                isFind = false;
                break;
            }
        }

        cnt += isFind;

        i += isFind ? wordSize : 1;
    }

    cout << cnt;
    return 0;
}