#include<bits/stdc++.h>

using namespace std;

long f[1000];

long fibn(int n){
	if(f[n] != -1){
		return f[n];
	}
	if(n<=1){
		return f[n] = n;
	}
	return f[n] = fibn(n-1) + fibn(n-2);
	
}

int main(){
	for (int i = 0; i < 1000; i++) f[i] = -1; // kh?i t?o
	int n;
	cin>>n;
	cout<<"fib "<<n<<" la: "<<fibn(n)<<endl;
	
	return 0;
}