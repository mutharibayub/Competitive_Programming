#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int p, curP=0;
        cin>>s>>p;
        vector<int> counts(26,0);
        for(int i=0;s[i];i++)
        {
            counts[s[i]-'a']++;
            curP+=s[i]-'a'+1;
        }
        for(int i=25;i>=0;i--)
        {
            if(curP-((i+1)*counts[i]) > p)
            {
                curP-=(i+1)*counts[i];
                counts[i]=0;
            }
            else
            {
                int toRemove = (curP-p+i)/(i+1);
                counts[i]-=toRemove;
                curP-=(toRemove*(i+1));
                break;
            }
        }
        for(int i=0;s[i];i++)
        {
            if(counts[s[i]-'a'])
            {
                cout << s[i];
                counts[s[i]-'a']--;
            }
        }cout << '\n';
    }

    return 0;
}