#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int evenCount=0, oddCount=0;
        ll sum = 0;
        int n,q;
        cin>>n>>q;
        for(int i=0;i<n;i++)
        {
            int num;
            cin>>num;
            sum+=num;
            evenCount += (num&1)==0;
            oddCount += (num&1)==1;
        }
        // cout << "EvenCount: " << evenCount << " OddCount: " << oddCount << " Sum: " << sum << '\n';
        for(int i=0;i<q;i++)
        {
            int qt, v;
            cin>>qt>>v;
            sum += 1ll*(qt?oddCount:evenCount)*v;
            if(v&1)
            {
                if(qt)
                {
                    evenCount+=oddCount;
                    oddCount=0;
                }
                else
                {
                    oddCount+=evenCount;
                    evenCount=0;
                }
            }
            cout << sum << '\n';
        }
    }

    return 0;
}