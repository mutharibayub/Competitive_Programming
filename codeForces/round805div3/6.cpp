#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        unordered_map<int,int> counts;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            while(a[i] && !(a[i]&1))
            {
                a[i] = a[i]>>1;
            }
            counts[a[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            while(b[i] && !(b[i]&1))
            {
                b[i] = b[i]>>1;
            }
        }

        bool notPossible=false;
        for(int i=0;i<n;i++)
        {
            while(!counts[b[i]] && b[i])
            {
                b[i] = b[i]>>1;
            }
            if(!b[i])
            {
                notPossible=true;
                break;
            }
            counts[b[i]]--;
        }
        if(notPossible)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }


    return 0;
}