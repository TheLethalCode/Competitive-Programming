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

int hm,am,dm;

bool decide(int hy,int ay,int dy)
{
    if(ay-dm <= 0)
        return false;
    else if(am-dy <= 0)
        return true;
    return ceil(hm*1.0/(ay-dm)) < ceil(hy*1.0/(am-dy));
}

int main()
{
    crap;
    int hy,ay,dy;
    cin>>hy>>ay>>dy>>hm>>am>>dm;
    int h,a,d;
    cin>>h>>a>>d;
    int cost=1e9;
    
    int store[1001][201][101];
    for(int i=0;i<1001;i++)
        for(int j=0;j<201;j++)
            for(int k=0;k<101;k++)
                store[i][j][k]= 1e9;

    for(int i=hy;i<=1000;i++)
        for(int j=ay;j<=200;j++)
            for(int k=dy;k<=100;k++)
            {
                if(decide(i,j,k))
                    store[i][j][k] = (i-hy)*h + (j-ay)*a + (k-dy)*d;
            }

    int x,y,z;
    for(int i=0;i<=1000;i++)
        for(int j=0;j<=200;j++)
            for(int k=0;k<=100;k++)
            {
                if(store[i][j][k] < cost)
                    x=i,y=j,z=k,cost=store[i][j][k];
            }
    
    cout<<cost<<endl;
}