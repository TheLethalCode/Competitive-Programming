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
#define pb emplace_back

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) (int)(a.size())
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)
#define perc %

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    vli po(30, 0);
    FOR(i, 29){
        po[i+1] = po[i] + (1LL<<(i<<1)); 
    }
    vli ar = {0, 2, 3, 1};
    while(t--){
        lli n, a, b;
        cin>>n;
        int x = n % 3;
        n = (n + 2)/3;
        int pos = lower_bound(all(po), n) - po.begin();
        n -= po[pos-1]+1;
        a = (1LL<<(2*(pos-1))) + n;
        b = (1LL<<(2*pos-1));
        int i = 0;
        while(2*i < 2*pos-1){
            b += ar[n%4]<<(2*i);
            i++, n/=4;
        }
        lli c = a xor b;
        vli temp = {c, a, b};
        cout<<temp[x]<<endl;
    }
}