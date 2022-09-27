#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

string testCase()
{
    string out = "";
    int64_t f,a,c;
    cin>>f>>a>>c;
    int64_t t;
    if(f<a && f<c){t=f;}
    else if(a<c){t=a;}
    else{t=c;}
    out += to_string(t)+"\n";
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