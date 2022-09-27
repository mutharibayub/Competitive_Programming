#include <iostream>
#include <vector>
using namespace std;

vector<string> letterCasePermutation(string s) {
    vector<string> possibs({s});
    for(int i=0;s[i];i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            int size=possibs.size();
            string tmp;
            for(int j=0;j<size;j++)
            {
                tmp=possibs[j];
                tmp[i]=s[i]-32;
                possibs.push_back(tmp);
            }
        }
        else if(s[i]>='A' && s[i]<='Z')
        {
            int size=possibs.size();
            string tmp;
            for(int j=0;j<size;j++)
            {
                tmp=possibs[j];
                tmp[i]=s[i]+32;
                possibs.push_back(tmp);
            }
        }
    }
    return possibs;
}

int main()
{

    return 0;
}