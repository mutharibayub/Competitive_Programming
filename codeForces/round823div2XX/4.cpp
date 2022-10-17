#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        vector<int> count(26*26, 0);
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        if(n==1 && s1[0]!=s2[0])
        {
            cout << "NO\n";
            continue;
        }
        for(int i=0;s1[i];i++)
        {
            count[(min(s1[i],s2[s2.size()-i-1])-'a')*26 + (max(s1[i],s2[s2.size()-i-1])-'a')]++;
        }
        bool odd = false;
        bool possible = true;
        for(int i=0;i<count.size();i++)
        {
            if(count[i]&1)
            {
                if(odd || i/26!=i%26)
                {
                    possible = false;
                    break;
                }
                odd = true;
            }
        }
        cout << (possible?"YES\n":"NO\n");
    }

    return 0;
}