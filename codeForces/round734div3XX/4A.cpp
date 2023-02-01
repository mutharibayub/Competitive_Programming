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
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> left(m, n);
        bool check=true;
        for(int i=0;i<m;i++)
        {
            if(left[i]%2)
            {
                if(!k||i+1>=m)
                {
                    check=false;
                    break;
                }
                else
                {
                    k--;
                    left[i]--;
                    left[i+1]--;
                }
            }
        }
        if(k%2)check=false;
        for(int i=0;i+1<m&&k&&check;i+=2)
        {
            int toAdd=min(k, left[i]);
            k-=toAdd;
            left[i]=left[i+1]=left[i]-toAdd;
        }
        if(!k&&check)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }

    return 0;
}