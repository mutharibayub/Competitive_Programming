#include <iostream>
#include <vector>
using namespace std;

int minDeletionSize(vector<string>& strs) {
    vector<bool> deleted(100,0);
    int deleteCount = 0;
    //loop between each pair of strings
    for(int i=0;i<strs.size()-1;i++)
    {
        //check if lexographically proper
        bool reset=false;        
        for(int j=0;j<strs[i][j];j++)
        {
            if(deleted[j])continue;
            //if yes continue
            if(strs[i][j]<strs[i+1][j])break;
            //if not, add the index where they mismatch to deleted index and continue to next iteration of check 
            else if(strs[i][j]>strs[i+1][j])
            {
                deleted[j] = true;
                deleteCount++;
                reset=true;
            }
        }
        if(reset)i=-1;
    }   
    return deleteCount;
}

int main()
{
    // ["vdy","vei","zvc","zld"]
    vector<string> s({"vdy","vei","zvc","zld"});
    cout<<minDeletionSize(s);
    return 0;
}