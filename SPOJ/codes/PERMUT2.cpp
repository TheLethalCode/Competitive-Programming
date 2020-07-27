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
    int n;
    cin>>n;
    while(n)
    {
        vi v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        int val=1;
        for(int i=0;i<n;i++)
            if(v[v[i]-1]!=i+1)
            {
                val=0;
                break;
            }
        if(val)
            cout<<"ambiguous";
        else
            cout<<"not ambiguous";
        cout<<endl;
        cin>>n;
    }
}