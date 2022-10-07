#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int pairSum(ListNode* head) {
    ListNode* ptr = head;
    ListNode* mid = head;
    for(int i=0;ptr;i++)
    {
        ptr = ptr->next;
        if(i%2==1)mid=mid->next;
    }
    stack<int> stk;
    while(mid)
    {
        stk.push(mid->val);
        mid = mid->next;
    }
    ptr=head;
    int maxVal = INT_MIN;
    while(!stk.empty())
    {   
        maxVal = max(maxVal, ptr->val+stk.top());
        ptr=ptr->next;
        stk.pop();
    }
    return maxVal;
}

int main()
{

    return 0;
}