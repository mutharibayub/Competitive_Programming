#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <Algorithm>
using namespace std;

string testCase()
{
    int red, green, both, k;
    cin >> red >> green >> both >> k;
    vector<int> rpacks;
    vector<int> gpacks;
    rpacks.reserve(k);
    gpacks.reserve(k);
    for (int i = 0; i < k; i++)
    {
        string color;
        int price;
        cin >> price >> color;
        if (color == "green")
        {
            gpacks.push_back(price);
        }
        else
        {
            rpacks.push_back(price);
        }
    }
    sort(gpacks.begin(), gpacks.end());
    sort(rpacks.begin(), rpacks.end());
    int gStart = 0;
    int rStart = 0;
    int totalCost = 0;
    int painted = 0;
    for (int i = 0; i < gpacks.size() && i<green; i++)
    {
        totalCost += gpacks[i];
        gStart = i+1;
        painted++;
    }
    green -= gStart;
    for (int i = 0; i < rpacks.size() && i < red; i++)
    {
        totalCost += rpacks[i];
        rStart = i + 1;
        painted++;
    }
    while ((rStart < rpacks.size() || gStart < gpacks.size()) && both>0)
    {
        if (rStart < rpacks.size() && gStart < gpacks.size())
        {
            if (rpacks[rStart] < gpacks[gStart])
            {
                totalCost += rpacks[rStart];
                rStart++;
            }
            else
            {
                totalCost += gpacks[gStart];
                gStart++;
            }
        }
        else if (rStart < rpacks.size())
        {
            totalCost += rpacks[rStart];
            rStart++;
        }
        else
        {
            totalCost += gpacks[gStart];
            gStart++;
        }
        painted++;
        both--;
    }
    return to_string(painted)+" "+to_string(totalCost);
}

int main()
{
    int testCases;
    string out = "";
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        out += "Case #"+to_string(i+1)+": "+testCase() + "\n";
    }
    cout << out;
    return 0;
}