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

#define nl cout<<endl
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(int i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

#define perc %
#define xors ^

#define dame pair< pal, int >

bool can(lli med, vpal &st, vpal &en, vpal &v, lli sum)
{
    int n = st.size();
    lli ans  = 0;
    vi mark(n,0);
    int cnt = 0;
    FOR(i,n)
        if(st[i].fi >= med)
            ans += st[i].fi, mark[st[i].se] = 1, cnt++;

    set< pal > wtf; 
    FOR(i,n)
        if(en[i].fi >= med && !mark[en[i].se])
            wtf.insert({-v[en[i].se].fi,en[i].se});
    for(auto temp : wtf)
    {
        if(cnt >= (n/2 + 1))
            break;
        ans+=max(med,-temp.fi),cnt++,mark[temp.se]=1;
    }
    if(cnt <= n/2)
        return false;

    FOR(i,n)
        if(!mark[i])
            ans+=v[i].fi;
    if(ans > sum)
        return false;

    return true;
}

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        int n; lli s;
        cin>>n>>s;
        vpal st(n),en(n),v(n);
        FOR(i,n)
        {
            cin>>st[i].fi>>en[i].fi;
            st[i].se = en[i].se = i;
            v[i].fi = st[i].fi;
            v[i].se = en[i].fi;
        }
        sort(all(st));
        sort(all(en));

        lli ans = 0;
        for(int i = 40; i >= 0;i--)
            if(can(ans + (1LL << i),st,en,v,s))
                ans += (1LL << i);
        cout<<ans;nl;
    }
}