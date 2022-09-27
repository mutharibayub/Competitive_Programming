#include <iostream>
#define ld long
#define lld long long

using namespace std;

#define RED 1
#define YR 2
#define YB 3
#define YG 4

void helper(ld i, ld jumps, ld earned, ld temp, ld buffer, ld& max, int prev, string path)
{
    // cout << "---------------\n";
    // cout << "Jump: " << i << endl;
    // cout << "Prev: " << prev << endl;
    // cout << "Earned: " << earned << endl;
    // cout << "Temp: " << temp << endl;
    // cout << "Buffer: " << buffer << endl;
    // cout << "Max: " << max << endl;
    // cout << "---------------\n";
    if(i == jumps)
    {
        if(max<earned)
        {
            cout<<earned<<" "<<path<<endl;
            max = earned;
        }
        return;
    }
    
    //RED
    helper(i+1, jumps, earned+1, temp, buffer, max, RED, path+"R_");

    //Y _ R
    if(prev != YR && prev != YB && prev != -1)
        helper(i+1, jumps, earned, earned, buffer, max, YR, path+"YR_");

    //Y _ B
    if(prev == YR)
        helper(i+1, jumps, earned, 0, temp, max, YB, path+"YB_");

    //Y _ G
    if(prev != -1 && prev != YR && buffer > 0)
        helper(i+1, jumps, earned+buffer, temp, buffer, max, YG, path+"YG_");
}

void solve(int t)
{
    //cout << "Case #" << t << ": ";

    ld n;
    cin >> n;

    ld max = 0;

    helper(0, n, 0, 0, 0, max, -1, "");

    cout << max << endl;
}

int main()
{
    int t;
    cin >> t;

    for(int i = 1 ; i <= t ; i ++)
    {
        solve(i);
    }
}