#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define vi vector< int >
#define vli vector< lli >
#define endl "\n"
#define pa pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int main()
{
    crap;
    int n;
    cin>>n;
    vi p(5*1e5+1,0),b(5*1e5+1,0);
    for(int i=0;i<n;i++)
    {
        string a;
        cin>>a;
        vector< char > temp;
        for(int i=0;i<a.length();i++)
        {
            if(temp.empty())
                temp.pb(a[i]);
            else
            {
                if(a[i]=='(')
                    temp.pb(a[i]);
                else
                {
                    if(temp.back() == '(')
                        temp.pop_back();
                    else
                        temp.pb(a[i]);
                }
            }
        }
        int x=0,y=0;
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i] == '(')
                x++;
            else
                y++;
        }
        if(x==0 && y==0)
            p[0]++;
        else if(x==0)
            b[y]++;
        else if(y==0)
            p[x]++;
    }
    int ans=0;
    ans+=p[0]/2;
    for(int i=1;i<=5*1e5;i++)
        ans+=min(p[i],b[i]);
    cout<<ans<<endl;    
}