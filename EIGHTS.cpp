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
        int64_t k;
        cin>>k;
        cout<<((k-1)*250+192)<<'\n';
    } 
    return 0;
}