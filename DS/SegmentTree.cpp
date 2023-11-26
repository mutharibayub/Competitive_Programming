#include <vector>
using namespace std;

struct SegmentTreeNode {
    int val;
    int l=-1;
    int r=-1;
    int prop;
    SegmentTreeNode(){}
    SegmentTreeNode(int val, int l, int r, int prop): val(val), l(l), r(r), prop(prop){}
};

class SegmentTree {
    vector<SegmentTreeNode> __tree;
    vector<int> __init;
    int __n;

    SegmentTreeNode _merge(const SegmentTreeNode &left, const SegmentTreeNode &right) {
        if(left.l == -1) {
            return right;
        } else if(right.l == -1) {
            return left;
        }
        return SegmentTreeNode(max(left.val, right.val), left.l, right.r, 0);
    }

    void _propagate(int i) {
        __tree[i].val += __tree[i].prop;
        if(__tree[i].l != __tree[i].r) {
            __tree[i*2+1].prop += __tree[i].prop;
            __tree[i*2+2].prop += __tree[i].prop;
        }
        __tree[i].prop = 0;
    }

    void _init(int i, int l, int r) {
        if(l == r) {
            __tree[i].l = __tree[i].r = l;
            __tree[i].val = __init[l];
            __tree[i].prop = 0;
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
            __tree[i].prop += x;
            _propagate(i);
            return;
        }
        _update(i*2+1, l, r, x);
        _update(i*2+2, l, r, x);
        __tree[i] = _merge(__tree[i*2+1], __tree[i*2+2]);
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
    SegmentTree(const vector<int> &arr) {
        __init = arr;
        __n = arr.size();
        __tree.resize(4*__n);
        _init(0, 0, __n-1);
    }

    int query(int l, int r) {
        return _query(0, l, r).val;
    }

    void update(int l, int r, int x) {
        _update(0, l, r, x);
    }

};