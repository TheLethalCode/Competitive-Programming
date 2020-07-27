#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define pa pair<int,int>
#define pal pair<lli,lli>
#define vi vector< int >
#define vli vector< lli >
#define vpa vector< pa >
#define vpal vector< pal >
#define fi first
#define se second
#define pb push_back
#define pp pop_back

#define nl cout<<"\n"
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(int i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector< vpa > v(n);
        map<string,int> ha;
        FOR(i,n)
        {
            string k;
            cin>>k;
            ha[k]=i;
            int m;
            cin>>m;
            FOR(j,m)
            {
                int a,b;
                cin>>a>>b;
                v[i].pb({a-1,b});
            }
        }
        int r;
        cin>>r;
        while(r--)
        {
            vi w(n,0);
            int a,b;
            string c,d;
            cin>>c>>d;
            a = ha[c],b= ha[d];
            priority_queue< pa, vpa > pq;
            pq.push({0,a});
            while(!pq.empty())
            {
                pa u=pq.top();
                if(u.se == b)
                {
                    cout<<-u.fi;nl;
                    break;
                }
                pq.pop();
                if(w[u.se])
                    continue;

                w[u.se]=1;
                u.fi*=-1;
                
                for(auto s:v[u.se])
                    if(!w[s.fi])
                        pq.push({-u.fi-s.se,s.fi});
            }
        } 
    }
}