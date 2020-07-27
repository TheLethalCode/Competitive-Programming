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

// %

int main(int argc, char **argv)
{
    crap;
    int q;
    cin>>q;
    while(q--)
    {
        lli n,m;
        cin>>n>>m;
        vector< pair< lli, pal > > v(n);
        FOR(i,n) cin>>v[i].fi>>v[i].se.fi>>v[i].se.se;
        int fl = 0;
        lli cur = m, ti = 0, last = 0, i=0;
        lli st = -1e9, en = 1e9;
        for(int i=0;i<n;i++)
        {
            st = v[i].se.fi, en = v[i].se.se;
            if(cur < st)
                ti += st - cur, cur = st;
            if(cur > en)
                ti += cur - en, cur = en;
            if(ti > v[i].fi)
            {
                fl = 1;
                break;
            }
            int j = i+1;
            lli prev = cur, prevti = ti;
            while(j < n && ti < v[i].fi)
            {
                // if(!(v[j].se.fi >= st && v[j].se.fi <= en) && !(v[j].se.se >= st && v[j].se.se <= en))
                //     break;
                if(v[j].se.se < st)
                {
                    ti += min(cur - st, v[i].fi - prevti);
                    cur -= min(cur - st, v[i].fi - prevti);
                    break;
                }
                if(v[j].se.fi > en)
                {
                    ti += min(en - cur, v[i].fi - prevti);
                    cur += min(en - cur, v[i].fi - prevti);
                    break;
                }
                st = max(st, v[j].se.fi), en = min(en, v[j].se.se);
                if(cur < st)
                    ti += min(st - cur, v[i].fi - prevti), cur += min(st - cur, v[i].fi - prevti);
                if(cur > en)
                    ti += min(cur - en, v[i].fi - prevti), cur -= min(cur - en, v[i].fi - prevti);
                prevti = ti;
                j++;
            }
            ti = v[i].fi;
        }
        if(fl)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }   
}