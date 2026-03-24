#include<bits/stdc++.h>

using namespace std;

double power(double a, int n){
	if(n == 0) return 1;
	double temp = power(a,n/2);
	if(n%2==0){
		return temp*temp;
	}
	else return temp * temp * a;
}

int main(){
	double a;
	int n;
	cin>>a;
	cin>>n;
	cout<<power(a,n);
	
	return 0;
}
