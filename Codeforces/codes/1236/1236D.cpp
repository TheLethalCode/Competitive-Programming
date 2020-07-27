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
#define perc %
#define xors ^

lli powmod(lli n, lli p)
{
    if(!p) return 1;
    if(p perc 2) return powmod(n,p-1)*n perc mod;
    lli t = powmod(n,p/2);
    return t*t perc mod;
}

int main(int argc, char **argv)
{
    crap;
    lli n, m, k;
    cin>>n>>m>>k;
    vector< vi > row(n),column(m);
    FOR(i,k)
    {
        int a,b;
        cin>>a>>b;
        row[a-1].pb(b-1);
        column[b-1].pb(a-1);
    }
    FOR(i,n)
        sort(all(row[i]));
    FOR(i,m)
        sort(all(column[i]));
    lli cnt = 1;
    int cu_r=0,cu_c=0,dir=0, fl=0;
    int sm_r = -1,bi_r = n,sm_c = -1, bi_c = m;
    while(true)
    {
        // cout<<cu_r<<" "<<cu_c<<" "<<dir<<" "<<cnt<<endl;
        if(dir==0)
        {
            int ob = bi_c;
            auto it = upper_bound(all(row[cu_r]),cu_c);
            if(it != row[cu_r].end())
                ob = min(ob,*it);

            if(fl && cu_c == ob-1)
                break;
            
            cnt += ob - 1 - cu_c, cu_c = ob-1, dir = 1;
            sm_r = cu_r, fl = 1;
        }
        else if(dir == 1)
        {
            int ob = bi_r;
            auto it = upper_bound(all(column[cu_c]),cu_r);
            if(it != column[cu_c].end())
                ob = min(ob,*it);

            if(fl && cu_r == ob-1)
                break;
            
            cnt += ob - 1 - cu_r, cu_r = ob-1, dir = 2;
            bi_c = cu_c;
        }
        else if(dir == 2)
        {
            int ob = sm_c;
            auto it = upper_bound(all(row[cu_r]),cu_c);
            if(it != row[cu_r].begin())
                it--, ob = max(ob,*it);

            if(fl && cu_c == ob+1)
                break;
            
            cnt += cu_c - ob - 1, cu_c = ob+1, dir = 3;
            bi_r = cu_r;
        }
        else
        {
            int ob = sm_r;
            auto it = upper_bound(all(column[cu_c]),cu_r);
            if(it != column[cu_c].begin())
                it--, ob = max(ob,*it);

            if(fl && cu_r == ob+1)
                break;
            
            cnt += cu_r - ob - 1, cu_r = ob+1, dir = 0;
            sm_c = cu_c;
        }
    }

    if(cnt == n*m - k)
        cout<<"YES";
    else
        cout<<"NO";
    cout<<endl;
    return 0;
}