#include <iostream>
#include <vector>
#include <string>
#include <Algorithm>
#include <map>
using namespace std;

string testCase()
{
    string out = "";
    int64_t fabrics;
    int64_t cartons;
    map<int, int> cd;
    cin >> fabrics >> cartons;
    vector<int> f(fabrics, 0);
    for (int i = 0; i < fabrics; i++)
    {
        cin >> f[i];
    }
    for (int i = 1, count=1; i < f.size(); i++)
    {
        if (f[i] == f[i - 1] || i+1==f.size())
        {
            if (i + 1 == f.size())count++;
            if (cd.find(count) != cd.end())
            {
                cd[count]++;
            }
            else
            {
                cd[count] = 1;
            }
            count = 1;
        }
        else
        {
            count++;
        }
    }
    int worth = 0;
    for (auto iter = cd.rbegin(); iter != cd.rend(); iter++)
    {
        if (cartons >= iter->second)
        {
            cartons -= iter->second;
            worth += iter->second * iter->first;
        }
        else
        {
            worth += cartons * iter->first;
            break;
        }
    }
    return to_string(worth) + "\n";
    return out;
}

int main()
{
    int testCases;
    string out;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        out += "Case #"+to_string(i+1)+": "+testCase();
    }
    cout << out;
    return 0;
}