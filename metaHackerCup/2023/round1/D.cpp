#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <iomanip>
using namespace std;

template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

struct MinMaxNode
{
    int mn = 1e9+7;
    int mx = 0;
    int mnIdx = -1;
    int mxIdx = -1;
    MinMaxNode operator+(const MinMaxNode &obj) const
    {
        MinMaxNode out = *this;
        if(out.mn > obj.mn || (out.mn==obj.mn && out.mnIdx > obj.mnIdx))
        {
            out.mn=obj.mn;
            out.mnIdx=obj.mnIdx;
        }
        if(out.mx < obj.mx || (out.mx==obj.mx && out.mxIdx > obj.mxIdx))
        {
            out.mx=obj.mx;
            out.mxIdx=obj.mxIdx;
        }
        return out;
    }
    void operator^=(bool val)
    {
        if(val)
        {
            swap(mn, mx);
            swap(mnIdx, mxIdx);
            mn = int(1e9+7)-mn;
            mx = int(1e9+7)-mx;
        }
    }
};

template<typename T>
struct SegmentTreeNode
{
    int l, r;
    T val;
    bool prop;
    SegmentTreeNode(): l(-1), r(-1), val(T()), prop(bool()){}
    SegmentTreeNode(int l, int r, const T &val): l(l), r(r), val(val), prop(bool()){}
};
 
template<typename T>
class SegmentTree
{
    int n;
    vector<T> __init;
    vector<SegmentTreeNode<T>> __tree;
 
    inline SegmentTreeNode<T> _merge(const SegmentTreeNode<T> &left, const SegmentTreeNode<T> &right)
    {
        if(left.l==-1)return right;
        if(right.l==-1)return left;
        return SegmentTreeNode<T>(left.l, right.r, left.val + right.val);
    }
 
    inline void _propagate(int i)
    {
        if(__tree[i].l!=__tree[i].r)
        {
            __tree[i*2+1].prop ^= __tree[i].prop;
            __tree[i*2+2].prop ^= __tree[i].prop;
        }
        __tree[i].val ^= __tree[i].prop;
        __tree[i].prop = bool();
    }
 
    void _init(int i, int l, int r)
    {
        if(l==r)
        {
            __tree[i].l=__tree[i].r=l;
            __tree[i].val=__init[l];
        }
        else
        {
            _init(i*2+1, l, (l+r)/2);
            _init(i*2+2, (l+r)/2+1, r);
            __tree[i]=_merge(__tree[i*2+1], __tree[i*2+2]);
        }
    }
 
    SegmentTreeNode<T> _get(int i, int l, int r)
    {
        _propagate(i);
        if(__tree[i].l>=l&&__tree[i].r<=r)return __tree[i];
        else if(__tree[i].r<l||__tree[i].l>r)return SegmentTreeNode<T>();
        else
        {
            SegmentTreeNode<T> stn;
            SegmentTreeNode<T> nxt = _get(i*2+1, l, r);
            if(nxt.l!=-1)stn = _merge(stn, nxt);
            nxt = _get(i*2+2, l, r);
            if(nxt.l!=-1)stn = _merge(stn, nxt);
            return stn;
        }
    }
 
    void _update(int i, int l, int r, bool xr)
    {
        _propagate(i);
        if(__tree[i].r<l||__tree[i].l>r)
            return;
        if(__tree[i].l>=l&&__tree[i].r<=r)
            __tree[i].prop ^= xr;
        else
        {
            _update(i*2+1, l, r, xr);
            _update(i*2+2, l, r, xr);
            _propagate(i*2+1);
            _propagate(i*2+2);
            __tree[i]=_merge(__tree[i*2+1], __tree[i*2+2]);
        }
    }

public:
 
    SegmentTree(const vector<T> &init)
    {
        __init = init;
        n = __init.size();
        __tree.assign(4*n, SegmentTreeNode<T>());
        _init(0, 0, n-1);
    }
 
    T get(int l, int r)
    {
        return _get(0, l, r).val;
    }
 
    void update(int l, int r, bool xr)
    {
        _update(0, l, r, xr);
    }
};

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int tttt;
    cin>>tttt;
    for(int ttt=1;ttt<=tttt;ttt++)
    {
        int n;
        cin>>n;
        vector<MinMaxNode> arr(n);
        for(int i=0;i<n;i++)
        {
            auto &ele = arr[i];
            cin>>ele.mn, ele.mx=ele.mn, ele.mnIdx=ele.mxIdx=i;
        }
        long long ans = 0;
        SegmentTree<MinMaxNode> st(arr);
        int q;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            int l, r;
            cin>>l>>r;
            l--, r--;
            st.update(l, r, 1);
            ans += st.get(0, n-1).mxIdx+1;
        }
        cout << "Case #" << ttt << ": " << ans << '\n';
    }

    return 0;
}
