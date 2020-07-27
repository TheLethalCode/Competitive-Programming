#include<bits/stdc++.h>
#include<unistd.h>
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

string rep(int x)
{
    if(x==1)
        return "2(0)";
    if(x==2)
        return "2";
    if(x%2)
        return rep(x-1)+"+2(0)";
    if(x%4)
        return rep(x-2)+"+2";
    int a=x - (1<<(int)(log2(x)));
    return "2("+rep(log2(x))+")" + (a?"+"+rep(a):"");
}

int main()
{
    crap;
    int arr[]={137,1315,73,136,255,1384,16385};
    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<"="<<rep(arr[i])<<endl;
        cout<<flush;
    }
}