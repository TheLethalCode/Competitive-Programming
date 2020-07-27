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
    int n;
    cin>>n;

    string s;
    cin>>s;
    
    vi A,B;
    FOR(i,n) if(s[i]=='A') A.pb(i); else B.pb(i);
    
    lli As = A.size(), Bs = B.size();
    lli ans = As*(As-1)/2 + Bs*(Bs-1)/2;
    A.pb(mod), B.pb(mod);
    
    for(int a : A)
    {
        if(a == mod)
            break;

        int apos = upper_bound(all(A),a) - A.begin();
        int bpos = upper_bound(all(B),a) - B.begin();
        int fin = upper_bound(all(B),max(A[apos],B[bpos])) - B.begin();
        ans += max(0LL, Bs - fin);
    }
    
    for(int b : B)
    {
        if(b==mod)
            break;

        int apos = upper_bound(all(A),b) - A.begin();
        int bpos = upper_bound(all(B),b) - B.begin();
        int fin = upper_bound(all(A),max(A[apos],B[bpos])) - A.begin();
        ans += max(0LL,As - fin);
    }

    cout<<ans<<endl;
}