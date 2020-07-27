#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define vi vector< int >
#define vli vector< lli >
#define endl "\n"
// #define pa pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int main()
{
    crap;
    int t,te=0;
    cin>>t;
    while(te++<t)
    {
        int n,m;
        cin>>n>>m;
        vector< set<int> > v(n);
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            v[a-1].insert(b-1);
            v[b-1].insert(a-1);
        }
        vi q,pa(n,-1),le(n,-1);
        int fl=0;
        for(int i=0;i<n;i++)
        {
            if(le[i] == -1)
                q.push_back(i);
            while(!q.empty())
            {
                int u=q.back();
                q.pop_back();
                for(auto r:v[u])
                {
                    if(pa[r] == u)
                        continue;
                    if(pa[r] != -1 && ((le[u] - le[r]) % 2 == 0))
                    {
                        fl=1;
                        goto lab;
                    }
                    else if(pa[r] != -1)
                    {
                        // cout<<r<<" "<<u<<endl;
                        continue;
                    }
                    pa[r]=u,le[r]=le[u]+1;
                    q.push_back(r);
                }
            }
        }
        lab:;
        cout<<"Scenario #"<<te<<":"<<endl<<( (fl)? "Suspicious bugs found!": "No suspicious bugs found!");
        cout<<endl; 
    }
}