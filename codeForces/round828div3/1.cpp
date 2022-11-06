#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        char map[50];
        for(int i=0;i<50;i++)map[i]=0;
        int n;
        cin>>n;
        vector<int> arr(n);
        string s;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            arr[i]--;
        }
        cin>>s;
        bool possible = true;
        for(int i=0;i<n;i++)
        {
            if(!map[arr[i]])
            {
                map[arr[i]] = s[i];
            }
            else if(map[arr[i]]!=s[i])
            {
                possible=false;
                break;
            }
        }
        if(possible)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}