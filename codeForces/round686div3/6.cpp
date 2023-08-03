#include <iostream>
#include <vector>
#include <map>
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
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        map<int,vector<int>> inds;
        for(int i=0;i<n;i++)inds[arr[i]].push_back(i);
        
        vector<int> lmx(n),lmn(n),rmx(n),rmn(n);
        vector<int> stk;
        for(int i=0;i<n;i++)
        {
            while(!stk.empty() && arr[stk.back()]<=arr[i])stk.pop_back();
            lmx[i]=stk.empty()?-1:stk.back();
            stk.push_back(i);
        }stk.clear();
        for(int i=0;i<n;i++)
        {
            while(!stk.empty() && arr[stk.back()]>=arr[i])stk.pop_back();
            lmn[i]=stk.empty()?-1:stk.back();
            stk.push_back(i);
        }stk.clear();
        for(int i=n-1;i>=0;i--)
        {
            while(!stk.empty() && arr[stk.back()]<=arr[i])stk.pop_back();
            rmx[i]=stk.empty()?n:stk.back();
            stk.push_back(i);
        }stk.clear();
        for(int i=n-1;i>=0;i--)
        {
            while(!stk.empty() && arr[stk.back()]>=arr[i])stk.pop_back();
            rmn[i]=stk.empty()?n:stk.back();
            stk.push_back(i);
        }stk.clear();

        bool found = false;
        int xx=-1, yy=-1, zz=-1;
        for(auto pr:inds)
        {
            int num=pr.first;
            vector<int> &idxx=pr.second;
            if(idxx.size()<3)continue;
            if(lmx[idxx[0]]==-1&&rmx[idxx.back()]==n)
            {
                int ll = rmx[idxx[0]], rr = lmx[idxx.back()];
                if(ll>rr)
                {
                    found=true;
                    xx = idxx[1], yy = 1, zz = n-xx-yy;
                }
                else
                {
                    for(int i=1;i<idxx.size()-1;i++)
                    {
                        if(idxx[i]<ll && rmn[idxx[i]]>=rr)
                        {
                            found=true;
                            xx = idxx[i], yy = rr-xx+1, zz = n-yy-xx;
                            break;
                        }
                        else if(idxx[i]>rr && lmn[idxx[i]]<=ll)
                        {
                            found=true;
                            xx = ll, yy = idxx[i]-ll+1, zz = n-yy-xx;
                            break;
                        }
                        else if(idxx[i]>ll && i<rr && lmn[idxx[i]]<=ll && rmn[idxx[i]]>=rr)
                        {
                            found=true;
                            xx = ll, yy = rr-ll+1, zz = n-xx-yy;
                            break;
                        }
                    }
                }
            }
            if(found)break;
        }
        if(found)
        {
            cout << "YES\n" << xx << ' ' << yy << ' ' << zz << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }

    return 0;
}