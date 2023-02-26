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
        int a, b;
        cin>>a>>b;
        int ans = a+b;
        for(int bit=30;bit>=0;bit--)
        {
            if((a&(1<<bit))&&(b&(1<<bit)))
            {
                ans-=2*(1<<bit);
            }
        }
        cout << ans << '\n';
    }


    return 0;
}