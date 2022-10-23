#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <assert.h>

using namespace std;

const int N = 5e3+1;
int n;

int getRef(int r, int c, int shift)
{
    return n*r+c-shift;
}

bool getLastVal(unordered_map<int, bool> &lastVal, int ref)
{
    auto ans = lastVal.find(ref);
    assert(ans!=lastVal.end());
    return ans->second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin>>n>>q;
    unordered_map<int, bool> lastVal;
    lastVal.reserve(N*N+N);
    vector<int> rowCounts(n,0);
    vector<int> colCounts(n,0);
    for(int i=0;i<n;i++)
    {
        string inp;
        cin>>inp;
        for(int j=0;inp[j];j++)
        {
            rowCounts[i]+=(inp[j]=='1');
            colCounts[j]+=(inp[j]=='1');
            lastVal[getRef(i, j, 0)] = (inp[j]=='1');
        }
    }
    
    int shift = 0;
    for(int i=0;i<q;i++)
    {
        int qt;
        cin>>qt;
        if(qt==1)
        {
            int r,c,v;
            cin>>r>>c>>v;
            r--,c--;

            rowCounts[r]-=getLastVal(lastVal, getRef(r,c,shift));
            rowCounts[r]+=v;
            
            colCounts[(c-shift+N*n)%n]-=getLastVal(lastVal, getRef(r,c,shift));
            colCounts[(c-shift+N*n)%n]+=v;
        
            lastVal[getRef(r,c,shift)] = v;
        }
        else
        {
            int v, tmp;
            cin>>v;
            tmp = v;
            for(int j=0;j<n;j++)
            {
                rowCounts[j]+=v;
                v = getLastVal(lastVal, getRef(j, n-1, shift));
                rowCounts[j]-=v;
            }
            v = tmp;
            int lastCol = (N*n-shift-1)%n;
            colCounts[lastCol]+=v;
            colCounts[lastCol]-=getLastVal(lastVal, getRef(n-1,n-1, shift));
            shift++;
            lastVal[getRef(0,0,shift)] = v;
        }
        int score = 0;
        for(int i=0;i<n;i++)
        {
            score+=(colCounts[i]==n);
            score+=(rowCounts[i]==n);
        }
        cout << score << '\n';
    }


    return 0;
}