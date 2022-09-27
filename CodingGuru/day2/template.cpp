#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

string testCase()
{
    string out = "";

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