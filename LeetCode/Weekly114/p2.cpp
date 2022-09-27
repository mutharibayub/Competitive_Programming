#include <iostream>
#include <vector>
using namespace std;

bool canReorderDoubled(vector<int>& arr) {
    vector<int> pos(int(1e5+1),0);
    vector<int> neg(int(1e5+1),0);  
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>=0)
        {
            pos[arr[i]]++;
        }
        else
        {
            neg[-1*arr[i]]++;
        }
    }
    if(pos[0]%2!=0)return false;
    for(int i=2;i<pos.size();i+=2)
    {
        int minVal;
        minVal = min(pos[i],pos[i/2]);
        if(minVal!=pos[i/2])return false;
        pos[i]-=minVal;
        pos[i/2]-=minVal;
    }
    for(int i=2;i<neg.size();i+=2)
    {
        int minVal;
        minVal = min(neg[i],neg[i/2]);
        if(minVal!=neg[i/2])return false;
        neg[i]-=minVal;
        neg[i/2]-=minVal;
    }
    for(int i=1;i<pos.size();i++)
    {
        if(pos[i]!=0)return false;
    }
    for(int i=1;i<neg.size();i++)
    {
        if(neg[i]!=0)return false;
    }
    return true;
}


int main()
{
    vector<string> a({"kuvp","q"});
    string s = "ngxlkthsjuoqcpavbfdermiywz";
    // cout<<isAlienSorted(a,s);
    return 0;
}