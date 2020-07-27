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

#define nl cout<<endl;
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
    int t;
    cin>>t;
    vi kr(1e6+1,0);
    while(t--)
    {
        int n,k,d;
        cin>>n>>k>>d;
        vi v(n);
        FOR(i,n) cin>>v[i];
        
        int cnt = 1e9,temp =0;
        FOR(i,d)
        {
            if(!kr[v[i]])
                temp++;
            kr[v[i]]++;
        }
        cnt = min(cnt,temp);
        FOR(i,n-d)
        {
            kr[v[i]]--;
            if(!kr[v[i]]) temp--;
            kr[v[i+d]]++;
            if(kr[v[i+d]]==1) temp++;
            cnt = min(cnt,temp);
        }
        cout<<cnt<<endl;
        FOR(i,n) kr[v[i]] = 0;
    }
    
}