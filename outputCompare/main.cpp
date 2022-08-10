#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

stringstream output;
stringstream input;

//------------------------------------------------------------------------------------------------//
template <class T>
class node
{
public:
    T val;
    bool valid;
    node *back;
    node *front;
    node(T val, bool valid=true, node *back=nullptr, node *front=nullptr):val(val),valid(valid),back(back),front(front){}
    bool operator<(const node& obj)
    {
        return this->val < obj.val;
    }
};

template<class T>
class Compare
{
public:
    bool operator() (const node<T>* obj1, const node<T>* obj2)
    {
        return obj1->val > obj2->val;
    }
};

void testCase()
{
    int n,c;
    input>>n>>c;
    node<int> *start=nullptr;
    priority_queue<node<int>*, vector<node<int>*>, Compare<int>> pq;
    vector<int> locs(n);
    for(int i=0;i<n;i++)
    {
        input>>locs[i];
    }
    sort(locs.begin(),locs.end());
    for(int i=n-1;i>0;i--)
    {
        node<int> *tempNode = new node<int>(locs[i]-locs[i-1]);
        pq.push(tempNode);
        if(start==nullptr)
        {
            start = tempNode;
        }
        else
        {
            tempNode->front = start;
            start->back = tempNode;
            start = tempNode;
        }
    }
    vector<node<int>*> removedNodes;
    for(int i=0;i<(n-c);i++)
    {
        while(pq.top()->valid==false)
        {
            pq.pop();
        }
        node<int> *tempNode = pq.top();
        pq.pop();
        if(tempNode->back==nullptr || (tempNode->front!=nullptr && tempNode->back->val > tempNode->front->val))
        {
            tempNode->front->valid=false;
            tempNode->val += tempNode->front->val;
            removedNodes.push_back(tempNode->front);
            tempNode->front = tempNode->front->front;
            if(tempNode->front)tempNode->front->back = tempNode;
            pq.push(tempNode);
        }
        else
        {
            tempNode->back->valid=false;
            tempNode->val += tempNode->back->val;
            removedNodes.push_back(tempNode->back);
            tempNode->back = tempNode->back->back;
            if(tempNode->back)tempNode->back->front = tempNode;
            pq.push(tempNode);
        }
    }
    while(pq.top()->valid==false)
    {
        pq.pop();
    }
    int ans = pq.top()->val;
    output<<ans<<'\n';
    for(auto it:removedNodes)
    {
        // output<<it->val<<'\t';
        delete it;
    }
    // output<<'\n';
    start = pq.top();
    while(start->back!=nullptr)
    {
        start = start->back;
    }
    while(start)
    {
        // output<<start->val<<'\t';
        node<int> *temp = start;
        start = start->front;
        delete temp;
    }
}
//------------------------------------------------------------------------------------------------//

void getDistance(const vector<int>& locs, vector<int>& assigned, int& maxDist, int cowsLeft)
{
    if(cowsLeft == 0)
    {
        int minDistLocal = INT_MAX;
        for(int i=0;i<assigned.size()-1;i++)
        {
            int dist=locs[assigned[i+1]]-locs[assigned[i]];
            minDistLocal = min(dist, minDistLocal);
        }
        maxDist = max(minDistLocal, maxDist);
        // for(auto it:assigned)
        // {
        //     output<<it<<' ';
        // }
        // output<<": "<<minDistLocal;
        // output<<'\n';
    }
    else
    {
        int assignmentStart = assigned.empty()?0:assigned.back()+1;
        for(int i=assignmentStart;locs.size()-i>=cowsLeft;i++)
        {
            assigned.push_back(i);
            getDistance(locs, assigned, maxDist, cowsLeft-1);
            assigned.pop_back();
        }
    }
}

void testCase1()
{
    int n,c;
    input>>n>>c;
    vector<int> locs(n);
    for(int i=0;i<n;i++)
    {
        input>>locs[i];
    }
    sort(locs.begin(),locs.end());
    vector<int> assigned;
    int maxDist = INT_MIN;
    getDistance(locs, assigned, maxDist, c);
    output<<maxDist<<'\n';
}

string code1(string inp)
{
    input.clear();
    input.str(inp);
    output.clear();
    output.str(string());
    //----------------------------------------------------------------------//
    int n;
    input >> n;
    while(n--)
    {
        testCase();
    }
    //----------------------------------------------------------------------//
    
    return output.str();
}

string code2(string inp)
{
    input.clear();
    input.str(inp);
    output.clear();
    output.str(string());
    //----------------------------------------------------------------------//
    int n;
    input>>n;
    while(n--)
    {
        testCase1();
    }
    //----------------------------------------------------------------------//

    return output.str();
}

int main()
{
    ifstream fin("input.txt");
    stringstream buf;
    string input; 
    buf << fin.rdbuf();
    input = buf.str();
    fin.close();

    // output << code1(input);
    // output << code2(input);
    assert(code1(input) == code2 (input));

}