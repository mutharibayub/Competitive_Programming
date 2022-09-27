// Segment tree implementation
#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int64_t high=0;
    int64_t low=0;
    int64_t val=0;
    int64_t lazyVal=0;
};

void initVal(vector<node>& smt, int64_t root, int64_t low, int64_t high, int64_t val)
{
    smt[root].low = low;
    smt[root].high = high;
    if(low==high)
    {
        smt[root].val = val;
        return;
    }
    initVal(smt, root*2, low, (low+high)/2, val);
    initVal(smt, root*2+1, (low+high)/2 + 1, high, val);
}

void addVal(vector<node> &smt, int64_t root, const int64_t &low, const int64_t &high, const int64_t &val)
{
    if(smt[root].lazyVal!=0)
    {
        if(smt[root].high!=smt[root].low)
        {
            smt[root*2].lazyVal += smt[root].lazyVal;
            smt[root*2+1].lazyVal += smt[root].lazyVal;
        }
        smt[root].val += smt[root].lazyVal*(smt[root].high-smt[root].low+1);
        smt[root].lazyVal = 0;
    }
    if(smt[root].low > high || smt[root].high < low)return;
    else if(smt[root].high <= high && smt[root].low >= low)
    {
        smt[root].val += (smt[root].high-smt[root].low+1)*val;
        if(smt[root].high!=smt[root].low)
        {
            smt[root*2].lazyVal += val;
            smt[root*2+1].lazyVal += val;
        }
        return;
    }
    addVal(smt, root*2, low, high, val);
    addVal(smt, root*2+1, low, high, val);
    smt[root].val = smt[root*2].val+smt[root*2+1].val;
}

int64_t getVal(vector<node> &smt, int64_t root, const int64_t &low, const int64_t &high)
{
    if(smt[root].lazyVal!=0)
    {
        if(smt[root].high!=smt[root].low)
        {
            smt[root*2].lazyVal += smt[root].lazyVal;
            smt[root*2+1].lazyVal += smt[root].lazyVal;
        }
        smt[root].val += smt[root].lazyVal*(smt[root].high-smt[root].low+1);
        smt[root].lazyVal = 0;
    }    
    int64_t sum = 0;
    if(smt[root].low > high || smt[root].high < low)return sum;
    else if(smt[root].high <= high && smt[root].low >= low)
    {
        sum += smt[root].val;
        return sum; 
    }
    sum += getVal(smt, root*2, low, high);
    sum += getVal(smt, root*2+1, low, high);
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int64_t n,m;
        cin>>n>>m;
        vector<node> segmentTree(4*n+1);
        initVal(segmentTree, 1, 0, n-1, 0);
        for(int i=0;i<m;i++)
        {
            int64_t a,p,q,v;
            cin>>a>>p>>q;
            p--,q--;
            if(a)
            {
                //query
                cout <<getVal(segmentTree, 1, p, q) << '\n';
            }
            else
            {
                //insertion
                cin>>v;
                addVal(segmentTree, 1, p, q, v);
            }
        }
    }

    return 0;
}