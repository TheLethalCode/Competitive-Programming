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
#define mp make_pair

#define nl cout<<endl;
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

lli gcd(lli a, lli b, lli& x, lli& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    lli x1, y1;
    lli d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void calc(lli &x, lli A, lli B, int i, int j){
    if(i<0) A=-A, i=-i;
    while(i>0 && j>0){
        x += A, i--;
        while(x + B < 1LL*mod*mod && x + B > -1LL*mod*mod && j>0)
            x += B, j--;
    }
    while(i>0) x+=A, i--;
    while(j>0) x+=B, j--; 
}

// %
int main(int argc, char **argv)
{
    crap;
    lli n, p, w, d;
    cin>>n>>p>>w>>d;
    if(!p){
        cout<<"0 0 "<<n<<endl;
        return 0;
    }
    lli a, b, gc = gcd(w, d, a, b);
    if(p % gc) {
        cout<<-1<<endl;
        return 0;
    }
    lli l = -a*(p/d) + ceil((-1.0*a/d)*(p%d));
    lli r = b*(p/w) + floor((1.0*b/w)*(p%w)); 
    lli great = (a+b)*(p/(w-d)) + floor((1.0*(a+b)/(w-d))*(p%(w-d)));
    if(l > r) {
        cout<<-1<<endl;
        return 0;
    }
    lli sh = min(max(l, great), r), x = 0, y=0;
    calc(x, p/gc, sh, a, d/gc), calc(y, p/gc, -sh, b, w/gc);
    if(x+y>n){
        cout<<-1<<endl;
        return 0;
    }
    cout<<x<<" "<<y<<" "<<n-x-y<<endl;
}