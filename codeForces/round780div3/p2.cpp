#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void testCase()
{
    int n;
    cin>>n;
    vector<int> counts(n);
    for(int i=0;i<n;i++)
    {
        cin>>counts[i];
    }
    if(n==1 && counts[0]>1)
    cout<<"NO\n";
    else 
    {
        sort(counts.rbegin(),counts.rend());
        if(counts[0]-counts[1]>1)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        testCase();
    }

    return 0;
}