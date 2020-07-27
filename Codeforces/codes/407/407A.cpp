#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define vi vector< int >
#define vli vector< lli >
#define endl "\n"
#define pa pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int main()
{
    crap;
    int a,b;
    cin>>a>>b;
    vi v(1e6+1,0),sq;
    for(int i=0;i<a;i++)
        v[i*i]=1,sq.pb(i*i);
    
    int z = a*a,ch=0,x1,x2,y1,y2;
    for(int x : sq)
    {
        if(v[z-x])
        {
            x1=sqrt(x),y1=sqrt(z-x);
            if(((b*x1) % a) || ((b*y1) % a))
                continue;
            x2=y1*b/a,y2=-x1*b/a;
            if(x1 == x2 || y1 == y2)
                x2=-y1*b/a,y2=x1*b/a;
            if(x1 == x2 || y1 == y2)
                continue;
            ch=1;
            break;
        }
    }
    if(ch)
    {
        printf("YES\n%d %d \n%d %d\n%d %d\n",0,0,x1,y1,x2,y2);
    }
    else
        printf("NO\n");
}