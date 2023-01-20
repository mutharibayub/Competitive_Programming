#include <iostream>
#include <vector>
#include <string>
using namespace std;

void testCase()
{
    string s;
    char c;
    cin>>s>>c;
    for(int i=0;s[i];i++)
    {
        if(s[i]==c && i%2==0)
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    while(n--)
    {
        testCase();
    }

    return 0;
}