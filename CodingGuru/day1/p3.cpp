#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <Algorithm>
using namespace std;

string testCase()
{
    int cCount;
    int yasir=0;
    cin >> cCount;
    cCount--;
    vector<int> cousins(cCount);
    cin >> yasir;
    for (int i = 0; i < cCount; i++)
    {
        cin >> cousins[i];
    }
    int count = 0;
    sort(cousins.rbegin(), cousins.rend());
    while (yasir <= cousins[0])
    {
        if (cousins[0] < yasir)
        {
            break;
        }
        for (int i = 0; i < cCount; i++)
        {
            cousins[i]--;
            yasir++;
            count++;
            if (i != cCount - 1)
            {
                if (cousins[i] >= cousins[i + 1] || (cousins[i+1]>=cousins[i] && yasir>cousins[i+1]))
                {
                    break;
                }
            }
        }
    }
    return to_string(count);
}

int main()
{
    int testCases;
    string out = "";
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        out += "Case #" + to_string(i + 1) + ": " + testCase() + "\n";
    }
    cout << out;
    return 0;
}