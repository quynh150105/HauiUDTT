#include<bits/stdc++.h>

using namespace std;

void viewConfig(int k, int x[], char label[]){
	for(int i = 1; i<=k; i++){
		cout<<label[x[i]-1];
	}
	cout<<endl;
}

void nextConfig(int k, int x[], int i){
	x[i] = x[i] + 1;
	i++;
	int j = k;
	while(i<=j){
		x[i] = x[i-1] + 1;
		j--;
		i++;
	}
}

void listConfig(int n, int k, char label[]){
	int i;
	int x[n+1] = {0};
	for(int i = 1; i<=k; i++){
		x[i] = i;
	}
	do{
		viewConfig(k,x,label);
		i = k;
		while(i>0 && x[i] == n-k + i) i--;
		if (i>0) nextConfig(k,x,i);
	}while(i>0);
}

void Try(int k, int n, int x[], int start, int size, char label[]){
	if(size == k){
		for(int i = 0; i<k; i++){
			cout<<label[x[i]-1];
		}
		cout<<endl;
	}else{
		for(int i = start; i<=n; i++){
			x[size] = i;
			Try(k,n,x,i+1,size+1, label);
		}
	}
}

void view(int n, int k, int x[]){
	for(int i = 0; i< k; i++){
		cout<<x[i];
	}
	cout<<endl;
}


int main(){
	int n=7,k=6;
	char label[] = {'A','B','C','D','E','F','G'};
	cout<<"phuong phap sinh"<<endl;
	listConfig(n,k,label);
	cout<<"Quay lui"<<endl;
	int x1[100];
	Try(k,n,x1,1,0, label);
	return 0;
}
