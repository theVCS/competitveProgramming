#include <iostream>
using namespace std;

int main() {
	int t, n, sum, dum;
	
	cin>>t;
	
	while(t--)
	{
	    cin>>n;
	    sum = 0;
	    for(int i = 0; i < n; i++)
	    {
	        cin>>dum;
	        sum += dum;
	    }
	    cout<<sum<<endl;
	}
}