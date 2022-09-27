#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <Algorithm>
using namespace std;

string testCase()
{
    int tanka, tankb, days=-1;
    cin >> tanka >> tankb;
    while (true)
    {
        if (tanka < 2 && tankb < 2)
        {
            break;
        }
        if (tanka < tankb)
        {
            tanka++;
            tankb -= 2;
            if (tankb <= 1 && tanka == 0)
            {
                break;
            }
        }
        else
        {
            tankb++;
            tanka -= 2;
            if (tanka <= 1 && tankb == 0)
            {
                break;
            }
        }
        days++;
    }
    return to_string(days);
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