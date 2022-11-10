#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    string s;
    while(n--)
    {
        cin>>s;
        cout<<(((s[0]-'a')*26)+s[1]-'a')-(s[0]-'a')+(s[1]<s[0]?1:0)<<"\n";
    }

}