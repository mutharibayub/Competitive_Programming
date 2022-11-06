#include <iostream>
#include <vector>
#include <array>
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
        int n;
        cin>>n;
        int minVal;
        bool aliceWin = false;
        for(int i=0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            if(aliceWin==true)continue;
            if(i==0)
            {
                minVal = tmp-1;
            }
            else if(tmp<=minVal)
            {
               aliceWin=true; 
            }
        }
        cout << (aliceWin?"Alice":"Bob") << '\n';
    }

    return 0;
}