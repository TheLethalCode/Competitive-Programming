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

int main(int argc, char **argv)
{
    crap;
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        int cnt = 0;
        vector< string > v(n);
        FOR(i,n)
            cin>>v[i];

        int val00 = 0, val01 = 0, val10 = 0, val11 = 0;
        FOR(i,n)
        {
            int r = v[i].size();
            int ze = 0, on = 0;
            FOR(j,r) if(v[i][j] == '0') ze++; else on++;
            if((ze perc 2) && (on perc 2))
                val11++;
            else if(ze perc 2)
                val10++;
            else if(on perc 2)
                val01++;
            else
                val00++;
        }
        cnt = val00 + val01 + val10 + val11;
        cnt -= (val01 + val10)? 0: val11 perc 2;
        cout<<cnt;
        nl;
    }
}