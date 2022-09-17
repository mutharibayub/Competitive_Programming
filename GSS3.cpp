#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int high = 0;
    int low = 0;
    int leftMax = -1000000;
    int rightMax = -1000000;
    int sum = -1000000;
    int max = -1000000;
};

void initSmt(vector<node> &smt, int root, int low, int high, const vector<int> &arr)
{
    if(low==high)
    {
        smt[root].high = smt[root].low = low; 
        smt[root].leftMax = smt[root].rightMax = smt[root].sum = smt[root].max = arr[low]; 
    }
    else
    {
        smt[root].high = high;
        smt[root].low = low;
        initSmt(smt, root*2+1, low, (low+high)/2, arr);
        initSmt(smt, root*2+2, (low+high)/2 +1, high, arr);
        smt[root].sum = smt[root*2+1].sum + smt[root*2+2].sum;
        smt[root].leftMax = max(smt[root*2+1].leftMax, smt[root*2+1].sum+smt[root*2+2].leftMax);
        smt[root].rightMax = max(smt[root*2+2].rightMax, smt[root*2+2].sum+smt[root*2+1].rightMax);
        smt[root].max = max(smt[root*2+1].rightMax+smt[root*2+2].leftMax,max(smt[root*2+1].max, smt[root*2+2].max));
    }
}

void getSum(const vector<node> &smt, int root, const int &low, const int &high, node &maxSum)
{
    if(smt[root].low > high || smt[root].high < low)return;
    else if(smt[root].low >= low && smt[root].high <= high)
    {
        node tmp;
        tmp.sum = maxSum.sum+smt[root].sum;
        tmp.leftMax = max(maxSum.leftMax, maxSum.sum+smt[root].leftMax);
        tmp.rightMax = max(smt[root].rightMax, smt[root].sum+maxSum.rightMax);
        tmp.max = max(smt[root].leftMax+maxSum.rightMax,max(maxSum.max, smt[root].max));
        maxSum = tmp;
    }
    else
    {
        getSum(smt, root*2+1, low, high, maxSum);
        getSum(smt, root*2+2, low, high, maxSum);
    }
}

void changeVal(vector<node> &smt, int root, int index, int newVal)
{
    if(smt[root].low==smt[root].high && smt[root].low==index)
    {
        smt[root].leftMax = smt[root].rightMax = smt[root].max = smt[root].sum = newVal;
    }
    else if(index < smt[root].low || index > smt[root].high)return;
    else
    {   
        changeVal(smt, root*2+1, index, newVal);
        changeVal(smt, root*2+2, index, newVal);
        smt[root].sum = smt[root*2+1].sum + smt[root*2+2].sum;
        smt[root].leftMax = max(smt[root*2+1].leftMax, smt[root*2+1].sum+smt[root*2+2].leftMax);
        smt[root].rightMax = max(smt[root*2+2].rightMax, smt[root*2+2].sum+smt[root*2+1].rightMax);
        smt[root].max = max(smt[root*2+1].rightMax+smt[root*2+2].leftMax,max(smt[root*2+1].max, smt[root*2+2].max));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> arr(n);
    vector<node> smt(4*n);
    for(int i=0;i<n;i++)cin>>arr[i];
    initSmt(smt, 0, 0, n-1, arr);
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int c,a,b;
        cin>>c>>a>>b;
        if(c==0)
        {
            changeVal(smt, 0, a-1, b);
        }
        else
        {
            node tmp;
            getSum(smt, 0, a-1, b-1, tmp);
            cout<<tmp.max<<'\n';   
        }
    }


    return 0;
}