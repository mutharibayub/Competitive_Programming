#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        map<string,int> last;
        cin>>n>>s;
        bool possible=false;
        for(int i=0;i+1<s.size();i++)
        {
            string tmp="";
            tmp.push_back(s[i]);
            tmp.push_back(s[i+1]);
            auto it = last.find(tmp);
            if(it!=last.end())
            {
                int index = it->second;
                if(index+1<i)
                {
                    possible=true;
                    break;
                }
            }
            else
            {
                last[tmp]=i;
            }
        }
        cout << (possible?"YES":"NO") << '\n';
    }


    return 0;
}