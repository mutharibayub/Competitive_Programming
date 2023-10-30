#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>

using namespace std;

typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
struct SegmentTreeNode
{
    int l, r;
    T mn;
    int mnCount;
    bool ignore;
    T prop;
    SegmentTreeNode(): l(-1), r(-1), mn(T()), mnCount(0), ignore(false), prop(T()){}
    SegmentTreeNode(int l, int r, const T &mn, int mnCount, bool ignore, const T &prop): 
        l(l), r(r), mn(mn), mnCount(mnCount), ignore(false), prop(prop){}
};
 
template<typename T>
class SegmentTree
{
    int n;
    vector<T> __init;
    vector<SegmentTreeNode<T>> __tree;
 
    inline void _propagate(int i)
    {
        if(__tree[i].ignore)
            return;
        if(__tree[i].l!=__tree[i].r)
        {
            if(!__tree[i*2+1].ignore)
                __tree[i*2+1].prop += __tree[i].prop;
            if(!__tree[i*2+2].ignore)
                __tree[i*2+2].prop += __tree[i].prop;
        }
        __tree[i].mn += __tree[i].prop;
        __tree[i].prop = T();
    }

    void _init(int i, int l, int r)
    {
        if(l==r)
        {
            __tree[i].l=__tree[i].r=l;
            __tree[i].mn=__init[l];
            __tree[i].mnCount=1;
        }
        else
        {
            _init(i*2+1, l, (l+r)/2);
            _init(i*2+2, (l+r)/2+1, r);
            __tree[i].l = l;
            __tree[i].r = r;
            __tree[i].mn = min(__tree[i*2+1].mn, __tree[i*2+2].mn);
            __tree[i].mnCount = 0;
            if(__tree[i].mn == __tree[i*2+1].mn)
                __tree[i].mnCount += __tree[i*2+1].mnCount;
            if(__tree[i].mn == __tree[i*2+2].mn)
                __tree[i].mnCount += __tree[i*2+2].mnCount;
        }
    }
 
    void _update(int i, int l, int r, const T &change)
    {
        _propagate(i);
        if(__tree[i].r<l || __tree[i].l>r || __tree[i].ignore)
            return;
        if(__tree[i].l >= l && __tree[i].r <= r)
        {
            __tree[i].prop += change;
            _propagate(i);
            return;
        }
        _update(i*2+1, l, r, change);
        _update(i*2+2, l, r, change);
        if(__tree[i*2+1].ignore || __tree[i*2+2].ignore)
        {
            assert(!(__tree[i*2+1].ignore && __tree[i*2+2].ignore));
            __tree[i].mn = __tree[i*2+1].ignore? __tree[i*2+2].mn: __tree[i*2+1].mn;
            __tree[i].mnCount = __tree[i*2+1].mnCount + __tree[i*2+2].mnCount;
            return;
        }
        __tree[i].mn = min(__tree[i*2+1].mn, __tree[i*2+2].mn);
        __tree[i].mnCount = 0;
        if(__tree[i].mn == __tree[i*2+1].mn)
            __tree[i].mnCount += __tree[i*2+1].mnCount;
        if(__tree[i].mn == __tree[i*2+2].mn)
            __tree[i].mnCount += __tree[i*2+2].mnCount;
    }

    void _setIgnores(int i) // starts ignoring all segments which don't have any element with min value
    {
        _propagate(i);
        if(__tree[i].mn != __tree[0].mn) // start ignoring if min doesn't match with min of root
        {
            __tree[i].ignore = true;
            __tree[i].mnCount = __tree[i].r - __tree[i].l + 1; // for min this is always true
            return;
        }
        if(__tree[i].mnCount == __tree[i].r - __tree[i].l + 1) // return if all elements under this are equal to min (also covers already ignored elements)
            return;
        _setIgnores(i*2+1);
        _setIgnores(i*2+2);
        if(__tree[i*2+1].ignore && __tree[i*2+2].ignore)
        {
            __tree[i].ignore = true;
            __tree[i].mnCount = __tree[i].r - __tree[i].l + 1;
            return;
        }
        __tree[i].mnCount = __tree[i*2+1].mnCount + __tree[i*2+2].mnCount;
        assert(__tree[i].mnCount == __tree[i].r - __tree[i].l + 1);
    }

public:
 
    SegmentTree(const vector<T> &init)
    {
        __init = init;
        n = __init.size();
        __tree.assign(4*n, SegmentTreeNode<T>());
        _init(0, 0, n-1);
    }
 
    T get()
    {
        return __tree[0].mn;
    }
 
    void update(int l, int r, const T &chg)
    {
        _update(0, l, r, chg);
    }

    void setIgnores()
    {
        _setIgnores(0);
        assert(!__tree[0].ignore);
    }

};

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(auto &ele: arr)
            cin>>ele;
        int q;
        cin>>q;
        vector<vector<pair<int, int>>> chgq(n+1);
        for(int i = 0; i < q; i++)
        {
            int l, r, chg;
            cin>>l>>r>>chg;
            l--;
            chgq[l].push_back({i+1, chg});
            chgq[r].push_back({i+1, -chg});
        }
        long long offset = 0;
        vector<long long> init(q+1, arr[0]);
        SegmentTree<long long> st(init);
        vector<long long> ans(n);
        for(int i = 0; i < n; i++)
        {   
            for(auto [idx, chg]: chgq[i])
            {
                st.update(idx, q, chg);
            }
            st.setIgnores();
            ans[i] = st.get()+offset;
            if(i+1 < n)
                offset += arr[i+1]-arr[i];
        }
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " \n"[i==ans.size()-1];
        }
    }
    return 0;
}