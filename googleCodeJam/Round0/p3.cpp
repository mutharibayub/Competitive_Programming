#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void testCase()
{
    int n;
    cin>>n;
    vector<int> die(n);
    for(int i=0;i<n;i++)
    {
        cin>>die[i];
    }
    sort(die.begin(), die.end());
    int shift=0;
    for(int i=1;i+shift<=n;i++)
    {
        if(i>die[i+shift-1])
        {
            shift++;
            i--;
        }
    }
    cout<<to_string(n-shift)<<'\n';
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cout<<"Case #"<<to_string(i+1)<<": ";
        testCase();
    }
    return 0;
}