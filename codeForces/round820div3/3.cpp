#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

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
        cin>>s;
        int start = s.front();
        int end = s.back();
        vector<int> steps={0};
        int c,m;
        if(start == end)
        {
            for(int i=1;s[i];i++)
            {
                if(s[i]==start && i!=s.size()-1)
                steps.push_back(i);
            }
            c = 0;
            steps.push_back(s.size()-1);
            m = steps.size();
        }
        else
        {
            vector<array<int,2>> sorted;
            for(int i=1;s[i];i++)sorted.push_back({s[i],i});
            sort(sorted.begin(), sorted.end());
            if(start < end)
            {
                for(int i=0;i<sorted.size();i++)
                {
                    if(sorted[i][0]>=start && sorted[i][0]<=end && sorted[i][1]!=s.size()-1)steps.push_back(sorted[i][1]);
                }
            }
            else
            {
                for(int i=sorted.size()-1;i>=0;i--)
                {
                    if(sorted[i][0]<=start && sorted[i][0]>=end && sorted[i][1]!=s.size()-1)steps.push_back(sorted[i][1]);
                }
            }
            c = abs(start-end);
            steps.push_back(s.size()-1);
            m = steps.size();
        }
        cout << c << ' ' << m << '\n';
        for(int i=0;i<steps.size();i++)
        {
            cout<<steps[i]+1;
            if(i+1<steps.size())cout<<' ';
        }cout<<'\n';
        
    }

    return 0;
}