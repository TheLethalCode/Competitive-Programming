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

lli calc(vi sum)
{
    lli ans = 0, pro = 1;
    for(int k : sum)
        ans += pro * k, pro *= 3;
    return ans;
}

int main(int argc, char **argv)
{
    crap;
    int q;
    cin>>q;
    while(q--)
    {
        lli n;
        cin>>n;
        vi sum;
        while(n)
            sum.pb(n perc 3), n/= 3;
        int r = sum.size(), k = -1;
        FOR(i,r)
            if(sum[i] == 2)
                k = i;
        if( k == -1)
            cout<<calc(sum)<<endl;
        else
        {
            for(int i = 0; i < r; i++)
            {
                if(i < k)
                    sum[i] = 0;
                else if(sum[i] >= 2 && i!=r-1)
                    sum[i] =0, sum[i+1]++;
                else if(sum[i] >= 2)
                    sum[i] = 0, sum.pb(1);
            }
            cout<<calc(sum)<<endl;
        }
    }
}