#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    vector<int> count(int(5e5+5),0);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        count[arr[i]]++;
    }

    for(int i=1;i<x;i++)
    {
        if(count[i]%(i+1))
        {
            cout << "No\n";
            return 0;
        }
        else
        {
            count[i+1]+=count[i]/(i+1);
            count[i]=0;
        }
    }
    if(bool(count[x]) ^ bool(count[x+1]))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}