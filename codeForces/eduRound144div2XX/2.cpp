#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string a, b;
        cin>>a>>b;
        if(a.back()==b.back())
        {
            cout << "YES" << '\n';
            cout << "*" << a.back() << '\n';
        }
        else if(a.front()==b.front())
        {
            cout << "YES" << '\n';
            cout << a.front() << "*" << '\n';
        }
        else
        {
            vector<vector<bool>> found(26, vector<bool>(26, false));
            for(int i=0;i+1<a.size();i++)
            {
                found[a[i]-'a'][a[i+1]-'a']=true;
            }
            bool ok=false;
            string ans = "aa";
            for(int i=0;i+1<b.size();i++)
            {
                if(found[b[i]-'a'][b[i+1]-'a'])
                {
                    ok=true;
                    ans[0]=b[i];
                    ans[1]=b[i+1];
                    break;
                }       
            }
            if(ok)
            {
                cout << "YES" << '\n';
                cout << "*" << ans << "*" << '\n';
            }
            else
            {
                cout << "NO" << '\n';
            }
        }
    }

    return 0;
}