#include<bits/stdc++.h>

using namespace std;

void sapXepGiamDan(int a[], int n){
	for(int i = 0; i< n-1; i++){
		for(int j = i+1; j<n; j++){
			if(a[i] < a[j]){
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main(){
	int n, amount;
	cout<<"Nhap so luong menh gia tien: ";
	cin>>n;
	int menhgia[n];
	for(int &x : menhgia) cin>>x;
	
	cout<<"Nhap so tien can doi: ";
	cin>>amount;
	
	sapXepGiamDan(menhgia,n);
	
	for(int i = 0; i< n; i++){
		while(menhgia[i] <= amount){
			cout<<menhgia[i]<<" ";
			amount -= menhgia[i];
		}
	}
	
	return 0;
}
