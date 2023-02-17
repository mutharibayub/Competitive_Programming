#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SegmentTreeNode
{
    int l;
    int r;
    int minVal;
    int minValCnt;
    int change;
    SegmentTreeNode(){}
    SegmentTreeNode(int l, int r, int mv, int mvc, int c):
            l(l),r(r),minVal(mv),minValCnt(mvc),change(c){}
};

class SegmentTree
{
    vector<SegmentTreeNode> arr;
    int n;

    inline int lc(int idx){return 2*idx+1;}
    inline int rc(int idx){return 2*idx+2;}
    void init(int l, int r, int idx, int val)
    {
        if(l==r)
        {
            arr[idx]=SegmentTreeNode(l, r, val, 1, 0);
        }
        else
        {
            init(l, (l+r)/2, lc(idx), val);
            init((l+r)/2+1, r, rc(idx), val);
            int minVal=min(arr[lc(idx)].minVal, arr[rc(idx)].minVal);
            int minValCnt = 0;
            if(arr[lc(idx)].minVal==minVal)minValCnt+=arr[lc(idx)].minValCnt;
            if(arr[rc(idx)].minVal==minVal)minValCnt+=arr[rc(idx)].minValCnt;
            arr[idx]=SegmentTreeNode(l, r, minVal, minValCnt, 0);
        }
    }
    inline void moveChangeDown(int idx)
    {
        if(arr[idx].change)
        {
            arr[idx].minVal+=arr[idx].change;
            if(arr[idx].l!=arr[idx].r)
            {
                arr[lc(idx)].change+=arr[idx].change;
                arr[rc(idx)].change+=arr[idx].change;
            }
            arr[idx].change=0;
        }
    }
    inline void moveMinValUp(int idx)
    {
        int minVal=min(arr[lc(idx)].minVal+arr[lc(idx)].change, arr[rc(idx)].minVal+arr[rc(idx)].change);
        int minValCnt = 0;
        if(arr[lc(idx)].minVal+arr[lc(idx)].change==minVal)minValCnt+=arr[lc(idx)].minValCnt;
        if(arr[rc(idx)].minVal+arr[rc(idx)].change==minVal)minValCnt+=arr[rc(idx)].minValCnt;
        arr[idx].minVal=minVal;
        arr[idx].minValCnt=minValCnt;        
    }
    void upd(int l, int r, int idx, int change)
    {
        moveChangeDown(idx);
        if(arr[idx].l>=l&&arr[idx].r<=r)
        {
            arr[idx].change+=change;
            moveChangeDown(idx);
        }
        else if(!(arr[idx].l>r||arr[idx].r<l))
        {
            upd(l, r, lc(idx), change);
            upd(l, r, rc(idx), change);
            moveMinValUp(idx);
        }
    }
    void gmin(int l, int r, int idx, pair<int,int> &mn)
    {
        moveChangeDown(idx);
        if(arr[idx].l>=l&&arr[idx].r<=r)
        {
            if(mn.first==arr[idx].minVal)
            {
                mn.second+=arr[idx].minValCnt;
            }
            else if(mn.first>arr[idx].minVal)
            {
                mn.first=arr[idx].minVal;
                mn.second=arr[idx].minValCnt;
            }
        }
        else if(!(arr[idx].l>r||arr[idx].r<l))
        {
            gmin(l, r, lc(idx), mn);
            gmin(l, r, rc(idx), mn);
        }
    }
public:
    SegmentTree(int n):n(n)
    {
        arr.resize(4*n);
        init(0, n-1, 0, 0);
    }
    void update(int l, int r, int change)
    {
        upd(l, r, 0, change);
    }
    pair<int, int> getMin(int l, int r)
    {
        pair<int, int> mn = {1e9+7, 0};
        gmin(l, r, 0, mn);
        return mn;
    }
};

const int N = 1e6+1;
vector<int> occ[N];
int occIdx[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        occ[arr[i]].push_back(i);
    }
    long long ans = 0;
    SegmentTree st(n);
    for(int i=0;i<n;i++)
    {   
        int next=arr[i];
        if(occIdx[next]>=k)
        {
            int leftRange=(occIdx[next]-k?occ[next][occIdx[next]-k-1]:-1)+1;
            int rightRange=occ[next][occIdx[next]-k];
            st.update(leftRange, rightRange, -1);
        }
        occIdx[next]++;
        if(occIdx[next]>=k)
        {
            int leftRange=(occIdx[next]-k?occ[next][occIdx[next]-k-1]:-1)+1;
            int rightRange=occ[next][occIdx[next]-k];
            st.update(leftRange, rightRange, +1);
        }    
        pair<int, int> mn=st.getMin(0, i);
        if(mn.first==0)ans+=mn.second;
    }
    cout << ans << '\n';

    return 0;
}