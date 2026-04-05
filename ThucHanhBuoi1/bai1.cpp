#include <bits/stdc++.h>

using namespace std;

//int n, a[100], isFinal;
//
//void khoitao(){
//	for(int i = 1; i<=n; i++){
//		a[i] = 0;
//	}
//}
//
//void sinh(){
//	int i = n;
//	while(i>=1 && a[i] == 1){
//		a[i] = 0;
//		i--;
//	}
//	if(i==0){
//		isFinal = 0;
//	}
//	else{
//		a[i] = 1;
//	}
//	
//cin>>n;
//	isFinal = 1;
//	khoitao();
//	while(isFinal){
//		for(int i = 1; i<=n; i++){
//			cout<<a[i];
//		}
//		cout<<endl;
//		sinh();
//	}
//}


void next_config(int x[], int n, int i){
	x[i] = 1;
	i++;
	while(i<=n){
		x[i] = 0;
		i++;
	}	
}

void view_config(int x[], int n ){
	for(int i = 1; i<=n; i++){
		cout<<x[i];
	}
	cout<<endl;
}

void listing_config(int n){
	int i;
	int x[n+1] = {0};
	do{
		view_config(x,n);
		i = n;
		while(i> 0 && x[i] == 1){
			i--;
		}
		if(i>0){
			next_config(x,n,i);
		}
	}while(i>0);
}

int main(){
	int n;
	cin>>n;
	listing_config(n);	
	return 0;
}






















