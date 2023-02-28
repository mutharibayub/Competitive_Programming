#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 1e7+1;

ll d[N];
ll ans[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=1;i<N;i++)
    {
        for(int j=i;j<N;j+=i)
        {
            d[j]+=i;
        }
    }
    for(int i=0;i<N;i++)if(d[i]<N&&d[i]>0&&ans[d[i]]==0)ans[d[i]]=i;
 
    int t;
    cin>>t;
    while(t--)
    {
        int c;
        cin>>c;
        cout << (ans[c]?ans[c]:-1) << '\n';
    }



    return 0;
}