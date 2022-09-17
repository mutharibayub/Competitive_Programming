#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Sums
{
    int low;
    int high;
    int64_t leftMax;
    int64_t rightMax;
    int64_t max;
    int64_t sum;
};

void init(vector<Sums>& segmentTree, const vector<int64_t>& arr, int i, int a, int b)
{
    if(a==b)
    {
        segmentTree[i].low = segmentTree[i].high = a;
        segmentTree[i].leftMax = segmentTree[i].rightMax = segmentTree[i].max = segmentTree[i].sum = arr[a];
        return;
    }
    init(segmentTree, arr, 2*i, a, (a+b)/2);
    init(segmentTree, arr, 2*i+1, (a+b)/2+1, b);
    segmentTree[i].leftMax = max(segmentTree[2*i].leftMax, segmentTree[2*i].sum+segmentTree[2*i+1].leftMax);
    segmentTree[i].rightMax = max(segmentTree[2*i+1].rightMax, segmentTree[2*i+1].sum+segmentTree[2*i].rightMax);
    segmentTree[i].sum = segmentTree[2*i].sum+segmentTree[2*i+1].sum;
    segmentTree[i].max = max(segmentTree[2*i].rightMax+segmentTree[2*i+1].leftMax,max(segmentTree[2*i].max, segmentTree[2*i+1].max));    
    segmentTree[i].low = a;
    segmentTree[i].high = b;
}

Sums getMax(vector<Sums>& segmentTree, int i, int a, int b)
{
    Sums out;
    if(segmentTree[i].low > b || segmentTree[i].high < a)
    {
        out.high = -1;
        return out;
    }
    if(segmentTree[i].low >= a && segmentTree[i].high <= b)
    {
        return segmentTree[i];
    }
    Sums s1 = getMax(segmentTree, 2*i, a, b);
    Sums s2 = getMax(segmentTree, 2*i+1, a, b);
    if(s1.high==-1)return s2;
    if(s2.high==-1)return s1;
    out.low = s2.low;
    out.high = s2.high;
    out.leftMax = max(s1.leftMax, s1.sum+s2.leftMax);
    out.rightMax = max(s2.rightMax, s2.sum+s1.rightMax);
    out.sum = s1.sum+s2.sum;
    out.max = max(s1.rightMax+s2.leftMax,max(s1.max, s2.max));    
    return out;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int64_t> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    vector<Sums> segmentTree(4*n+1);
    init(segmentTree, arr, 1, 0, n-1);
 
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        cout << getMax(segmentTree, 1, a-1, b-1).max<<'\n';
    }

    return 0;
}