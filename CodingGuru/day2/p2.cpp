#include <iostream>
#include <vector>
#include <string>
#include <Algorithm>
#include <unordered_map>
using namespace std;

bool checkValid(int64_t t, int64_t n)
{
    int64_t half = t / 2;
    if (t % 2 != 0)
    {
        half++;
    }
    int64_t minDays = half / n;
    if (half % n != 0)
    {
        minDays++;
    }
    int64_t sum2 = 0;
    int64_t currT = t;
    for (int i = 0; i < minDays; i++)
    {
        int64_t newT = currT - n + int64_t(n/10-t/10);
        sum2 += currT - newT;
        currT = newT;
        if (sum2 > half)
        {
            return false;
        }
    }
    if (sum2 > half)
    {
        return false;
    }
    return true;
}

string testCase()
{
    string out = "";
    int64_t t;
    cin >> t;
    for (int64_t i = 1; 1 <= t / 2 + 1; i++)
    {
        if (checkValid(t, i))
        {
            return to_string(i)+"\n";
        }
    }


    return out;
}

int main()
{
    int testCases;
    string out;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        out += testCase();
    }
    cout << out;
    return 0;
}