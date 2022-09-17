#include <iostream>
#include <vector>

using namespace std;

#define nMax int(1e6+1)
#define ull unsigned long long

int main()
{
    vector<ull> straight(nMax, 0),inverted(nMax, 0);
    straight[1]=1;
    for(ull i=2;i<=nMax;i++)
    {
        straight[i]=straight[i-1]+(i*(i+1))/2;
        inverted[i]=inverted[i-2]+(i*(i-1))/2;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<straight[n]+inverted[n]<<'\n';
    }
}