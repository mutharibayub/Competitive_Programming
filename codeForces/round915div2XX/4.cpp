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


struct Node {
    ll sum = 0;
    ll mx = 0;
    Node() {}
    Node(ll sum, ll mx): sum(sum), mx(mx) {}
    Node operator+(const Node &right) const {
        Node out;
        out.sum = this->sum + right.sum;
        out.mx = max(this->mx, right.mx);
        return out;
    }
};

struct SegmentTreeNode {
    Node val;
    int l=-1;
    int r=-1;
    ll prop=-1;
    SegmentTreeNode(){}
    SegmentTreeNode(Node val, int l, int r, int prop): val(val), l(l), r(r), prop(prop){}
};

class SegmentTree {
    vector<SegmentTreeNode> __tree;
    vector<Node> __init;
    int __n;

    SegmentTreeNode _merge(const SegmentTreeNode &left, const SegmentTreeNode &right) {
        if(left.l == -1) {
            return right;
        } else if(right.l == -1) {
            return left;
        }
        return SegmentTreeNode(left.val + right.val, left.l, right.r, -1);
    }

    void _propagate(int i) {
        if(__tree[i].prop == -1) {
            return;
        }
        __tree[i].val = Node(
                            1ll * (__tree[i].r - __tree[i].l + 1) * __tree[i].prop,
                            __tree[i].prop
                        );
        if(__tree[i].l != __tree[i].r) {
            __tree[i*2+1].prop = __tree[i].prop;
            __tree[i*2+2].prop = __tree[i].prop;
        }
        __tree[i].prop = -1;
    }

    void _init(int i, int l, int r) {
        if(l == r) {
            __tree[i].l = __tree[i].r = l;
            __tree[i].val = __init[l];
            __tree[i].prop = -1;
            return;
        }
        _init(i*2+1, l, (l+r)/2);
        _init(i*2+2, (l+r)/2+1, r);
        __tree[i] = _merge(__tree[i*2+1], __tree[i*2+2]);
    }

    void _update(int i, int l, int r, int x) {
        _propagate(i);
        if(l > __tree[i].r || r < __tree[i].l) {
            return;
        }
        else if(__tree[i].l >= l && __tree[i].r <= r) {
            __tree[i].prop = x;
            _propagate(i);
            return;
        }
        _update(i*2+1, l, r, x);
        _update(i*2+2, l, r, x);
        __tree[i] = _merge(__tree[i*2+1], __tree[i*2+2]);
    }

    int _lower_bound(int i, int l, int r, int val) {
        _propagate(i);
        if(__tree[i].l == __tree[i].r) {
            return __tree[i].l;
        }
        if(__tree[i*2+1].r < l || __tree[i*2+1].l > r) {
            return _lower_bound(i*2+2, l, r, val);
        }
        if(__tree[i*2+2].r < l || __tree[i*2+2].l > r) {
            return _lower_bound(i*2+1, l, r, val);
        }
        if(__tree[i*2+1].val.mx >= val) {
            return _lower_bound(i*2+1, l, r, val);
        }
        return _lower_bound(i*2+2, l, r, val);
    }

    SegmentTreeNode _query(int i, int l, int r) {
        _propagate(i);
        if(l > __tree[i].r || r < __tree[i].l) {
            return SegmentTreeNode();
        }
        else if(__tree[i].l >= l && __tree[i].r <= r) {
            return __tree[i];
        }
        const SegmentTreeNode left = _query(i*2+1, l, r);
        const SegmentTreeNode right = _query(i*2+2, l, r);
        return _merge(left, right);
    }

public:
    SegmentTree(const vector<Node> &arr) {
        __init = arr;
        __n = arr.size();
        __tree.resize(4*__n);
        _init(0, 0, __n-1);
    }

    Node query(int l, int r) {
        return _query(0, l, r).val;
    }

    void update(int l, int r, int x) {
        _update(0, l, r, x);
    }

    int lower_bound(int l, int r, int val) {
        return _lower_bound(0, l, r, val);
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
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        SegmentTree st = vector<Node>(2*n);
        vector<int> not_in(n+1, true);
        int not_in_idx = 0;
        ll best_sm = 0;
        for(int i = 0; i < n; i++) {
            not_in[arr[i]] = false;
            while(not_in[not_in_idx] == false) {
                not_in_idx++;
            }
            st.update(i, i, not_in_idx);
        }
        best_sm = st.query(0, n-1).sum;
        for(int i = 0; i < n - 1; i++) {
            int first_greater = st.lower_bound(i, n+i-1, arr[i]);
            st.update(first_greater, n+i-1, arr[i]);
            st.update(n+i, n+i, n);
            best_sm = max(best_sm, st.query(i+1, n+i).sum);
        }
        cout << best_sm << '\n';
    }
    return 0;
}