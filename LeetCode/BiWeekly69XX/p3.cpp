#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestPalindrome(vector<string>& words) {
    unordered_map<string,int> strs;
    string temp = "  ";
    int maxLen=0;
    for(int i=0;i<words.size();i++)
    {
        temp[0]=words[i][1];
        temp[1]=words[i][0];
        if(strs.find(temp)!=strs.end())
        {
            strs[temp]--;
            if(strs[temp]==0)
            {
                strs.erase(temp);
            }
            maxLen+=4;
        }
        else
        {
            if(strs.find(words[i])!=strs.end())
            {
                strs[words[i]]++;
            }
            else
            {
                strs[words[i]]=1;
            }
        }
    }
    for(auto it:strs)
    {
        if(it.second!=0 && it.first[0]==it.first[1])
        {
            maxLen+=2;
            break;
        }
    }
    return maxLen;
}

int main()
{
    vector<string> a({"qo","fo","fq","qf","fo","ff","qq","qf","of","of","oo","of","of","qf","qf","of"});
    cout<<longestPalindrome(a);
    return 0;
}