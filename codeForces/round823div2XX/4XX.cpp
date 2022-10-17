#include <iostream>
#include <vector>

using namespace std;

#define ld long double

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        vector<int> counts(26,0);
        for(int i=0;s1[i];i++)
        {
            counts[s1[i]-'a']++;
            counts[s2[i]-'a']++;
        }
        bool possible = true;
        for(int i=0;i<26;i++)
        {
            if(counts[i]&1)
            {
                possible = false;
                break;
            }
        }
        if(possible)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}