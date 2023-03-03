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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> cnt(26,0);
        int burls = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                burls+=(cnt[s[i]-'a']<0);
                cnt[s[i]-'a']++;
            }
            else
            {
                burls+=(cnt[s[i]-'A']>0);
                cnt[s[i]-'A']--;
            }
        }
        for(int i=0;i<26&&k;i++)
        {
            int toConvert = min(k, abs(cnt[i])/2);
            burls+=toConvert;
            k-=toConvert;
        }
        cout << burls << '\n';
    }


    return 0;
}