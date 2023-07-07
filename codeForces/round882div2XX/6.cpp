#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

ll pwr(ll n, ll e)
{
    ll o=1;
    while(e)
    {
        if(e%2)o=o*n%MOD;
        e/=2;
        n=n*n%MOD;
    }return o;
}

ll gcd(ll a, ll b)
{
    if(a<b)swap(a, b);
    return b?gcd(b, a%b):a;
}

int n;

struct Range
{
    int l=0;
    int r=n-1;
    Range(){}
    Range(int l, int r):l(l),r(r){}
    bool operator<(const Range &other) const
    {
        if(r-l<other.r-other.l)return true;
        else if(r-l>other.r-other.l)return false;
        if(r>=n&&other.r<n)return true;
        else if(r<n&&other.r>=n)return false;
        return l<other.l;
    }
};

// template<typename T>
// struct SegmentTreeNode
// {
//     int l;
//     int r;
//     T val;
//     SegmentTreeNode(){}
//     SegmentTreeNode(int l, int r, T val):l(l), r(r), val(val){}
// };

// template<typename T>
// class SegmentTree
// {
//     vector<T> __init;
//     vector<SegmentTreeNode<T>> __tree;
//     int n;

//     SegmentTreeNode<T> _merge(const SegmentTreeNode<T> &obj1, const SegmentTreeNode<T> &obj2)
//     {
//         SegmentTreeNode<T> out = obj1;
//         out.r=obj2.r;
//         out.val=min(out.val, obj2.val);
//         return out;
//     }
//     void _init(int i, int l, int r)
//     {
//         if(l==r)
//         {
//             __tree[i].l=__tree[i].r=l;
//             __tree[i].val=__init[l];
//         }
//         else
//         {
//             _init(i*2+1, l, (l+r)/2);
//             _init(i*2+2, (l+r)/2+1, r);
//             __tree[i]=_merge(__tree[i*2+1], __tree[i*2+2]);
//         }
//     }
//     SegmentTreeNode<T> _get(int i, int l, int r)
//     {
//         if(__tree[i].l>=l&&__tree[i].r<=r)
//         {
//             return __tree[i];
//         }
//         else if(__tree[i].r<l||__tree[i].l>r){return SegmentTreeNode<T>(-1,-1,T());}
//         else 
//         {
//             SegmentTreeNode s1 = _get(i*2+1, l, r);
//             SegmentTreeNode s2 = _get(i*2+2, l, r);
//             if(s1.l==-1)return s2;
//             else if(s2.l==-1)return s1;
//             else return _merge(s1, s2);
//         }
        
//     }
// public:
//     SegmentTree(const vector<T> &init)
//     {
//         __init=init;
//         n=__init.size();
//         __tree.resize(4*n);
//         _init(0, 0, n-1);
//     }
//     T get(int l, int r)
//     {
//         return _get(0, l, r).val;
//     }
// };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int q;
        cin>>n>>q;
        vector<int> arr(2*n);
        for(int i=0;i<n;i++)cin>>arr[i],arr[i+n]=arr[i];
        vector<vector<int>> loc(31);
        for(int i=0;i<2*n;i++)
        {
            for(int j=0;j<31;j++)
            {
                if(arr[i]&(1<<j))
                {
                    loc[j].push_back(i);
                }
            }
        }
        map<int, Range> mp;
        for(int i=0;i<n;i++)
        {
            set<int> st;
            for(int j=0;j<31;j++)
            {
                if(!bool(arr[i]&(1<<j)))
                {
                    auto first = lower_bound(loc[j].begin(), loc[j].end(), i+1);
                    if(first!=loc[j].end())st.insert(*first);
                }
            }
            int ele = arr[i];
            mp[ele]=min(mp[ele], Range(i, i));
            for(auto right:st)
            {
                ele|=arr[right];
                mp[ele]=min(mp[ele], Range(i, right+(right==n)));
            }
        }
        vector<int> nums;
        vector<Range> rngs;
        for(auto ele:mp)
        {
            nums.push_back(ele.first);
            rngs.push_back(ele.second);
        }
        for(int i=rngs.size()-2;i>=0;i--)
        {
            rngs[i]=min(rngs[i], rngs[i+1]);
        }
        for(int i=0;i<q;i++)
        {
            int v;
            cin>>v;
            if(v>=nums.back())
            {
                cout << -1 << '\n';
            }
            else
            {
                int idx = lower_bound(nums.begin(), nums.end(), v+1)-nums.begin();
                Range bestRange = rngs[idx];
                int rangeLen = bestRange.r-bestRange.l+1;
                ll ans = -1;
                if(rangeLen==1)ans=bestRange.l+1;
                else 
                {
                    ans = 1ll*(rangeLen-1)*(n-1)+1;
                    ans += (bestRange.l+rangeLen-1)%n;
                }
                cout << ans << '\n';
            }
        }
    }    

    return 0;
}