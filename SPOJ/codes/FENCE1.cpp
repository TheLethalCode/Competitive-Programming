#include <bits/stdc++.h>
using namespace std;
 
int main() {
	long long l;
	cin>>l;
	while(l)
	{
		cout<<fixed<<setprecision(2)<<(l*l*1.0)/(2*acos(-1))<<endl;
		cin>>l;
	}
	return 0;
} 