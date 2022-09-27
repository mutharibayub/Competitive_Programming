#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string,vector<string>> fileVector;
    vector<vector<string>> out;
    for(int i=0;i<paths.size();i++)
    {
        string path = "";
        string file="";
        string content="";
        bool pathFind=true;
        bool fileFind=false;
        for(int j=0;paths[i][j];j++)
        {
            if(paths[i][j]==' ' && fileFind)continue;
            if(pathFind)
            {
                if(paths[i][j]!=' ' && paths[i][j]!=0)
                {
                    path.push_back(paths[i][j]);
                }
                else
                {
                    pathFind=false;
                    fileFind=true;
                }
            }
            else if(fileFind)
            {
                if(paths[i][j]!='(')
                {
                    file.push_back(paths[i][j]);
                }
                else
                {
                    fileFind=false;
                }
            }
            else
            {
                if(paths[i][j]!=')')
                {
                    content.push_back(paths[i][j]);
                }
                else
                {
                    // cout<<"File: "<<path+"/"+file<<"\ncontent: "<<content<<"__\n";
                    fileVector[content].push_back(path+"/"+file);
                    content="";
                    file="";
                    fileFind=true;
                }
            }
        }
    }    
    // cout<<"**\n";
    for(auto it:fileVector)
    {
        // for(int i=0;i<it.second.size();i++)
        // {
        //     cout<<it.second[i]<<" ";
        // }
        // cout<<endl;
        if(it.second.size()>1)
        {
            out.push_back(it.second);
        }
    }
    return out;
}

int main()
{
    
    return 0;
}