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
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %

lli pomo(lli n, lli p){
    if(!p) return 1;
    if(p&1) return (pomo(n, p-1)*n)%mod;
    lli t = pomo(n, p>>1);
    return (t*t)%mod;
}

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--){
        lli n, p;
        cin>>n>>p;
        vli k(n);
        FOR(i, n) cin>>k[i];
        sort(all(k)); reverse(all(k));
        
        if(p==1){
            cout<<((n&1)?1:0)<<endl;
            continue;
        }

        int po = 18/log(p); vli pri(po+1, 1);
        FOR(i, po)
            pri[i+1] = pri[i]*p;

        lli ac = 0, bc = 0, A1=0;
        int cnt=0, fl=0, pk=k[cnt]; 
        while(cnt<n){
            A1=(A1+pomo(p, k[cnt]))%mod, ac+=pri[po-pk+k[cnt]], cnt++;
            while(ac > bc && cnt<n){
                while(ac-bc <= pri[po-1] && pk-k[cnt]>0)
                    ac-=bc, ac*=p, bc=0, pk--;
                if(po>=pk-k[cnt])
                    bc+=pri[po-pk+k[cnt]];
                A1=(A1+mod-pomo(p, k[cnt]))%mod, cnt++;
            }
            if(ac == bc) ac=0, bc=0, pk=k[cnt];
        }
        cout<<A1<<endl;
    }
}