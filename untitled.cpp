#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int ans=0;
	int c=0;
	char l='A';
	string s;
	cin >> s;
	for(char d: s)
	{
		if(l==d)
		{
			c++;
			ans=max(c,ans);
		}
		else
		{
			d=l;
			c=1;
		}
	}
	cout<<ans;
}

