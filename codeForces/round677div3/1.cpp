#include <iostream>
#include <vector>

using namespace std;

int digitCount(int n)
{
    int cnt=0;
    while(n)cnt++, n/=10;
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cnt[]={1,3,6,10};

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout << (n%10-1)*cnt[3]+cnt[digitCount(n)-1] << '\n';
    }


    return 0;
}