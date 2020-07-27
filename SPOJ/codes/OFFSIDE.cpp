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
    int a,d;
    cin>>a>>d;
    while(a)
    {
        vi A(a),D(d);
        for(int i=0;i<a;i++)
            cin>>A[i];
        for(int i=0;i<d;i++)
            cin>>D[i];
        sort(A.begin(),A.end());
        sort(D.begin(),D.end());
        cout<< ( ( A[0] < D[1] ) ? "Y":"N");
        cout<<endl; 
        cin>>a>>d;
    }
}