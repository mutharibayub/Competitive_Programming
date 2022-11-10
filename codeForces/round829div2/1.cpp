#include <iostream>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int count=0;
        int n;
        string inp;
        cin>>n>>inp;
        for(int i=0;inp[i];i++)
        {
            if(inp[i]=='A')
            {
                count = max(0, count-1);
            }
            else
            {
                count++;
            }
        }
        if(count)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
    }


    return 0;
}