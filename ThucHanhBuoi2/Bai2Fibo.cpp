#include<bits/stdc++.h>

using namespace std;

int fibo(int n){
	if(n<=1){
		return 1;
	}
	return fibo(n-1) + fibo(n-2);
}

int fibo(int n){
	if(n <=1){
		return 1;
	}
	for(int i = 2; i<=n; i++){
		int c = a + b;
		a = b;
		b = c;
	}
	return b;
}

int main(){
	return 0;
}
