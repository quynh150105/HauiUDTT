#include<bits/stdc++.h>

using namespace std;

void viewConfig(int n, int x[], char label[],  string name[]){
	for(int i = 1; i<=n; i++){
		cout<<label[i-1]<<"-"<<name[x[i]-1]<<" ";
	}
	cout<<endl;
}

void nextConfig(int n, int x[], int i){
	int k = n;
	while(x[k] < x[i]) k--;
	swap(x[i],x[k]);
	int j = n; i++;
	while(i<j){
		swap(x[i],x[j]);
		i++;j--;
	}
}

void listConfig(int n, char label[], string name[]){
	int i;
	int x[n+1];
	for(int i = 1; i<=n; i++){
		x[i] = i;
	}
	do{
		viewConfig(n,x,label,name);
		i = n-1;
		while(i> 0 && x[i] > x[i+1]) i--;
		if(i> 0) nextConfig(n,x,i);
	}while(i>0);
}


int main(){
int n = 4;
	char label[]= {'A', 'B', 'C', 'D'};
	string name[] = {"Tung", "Cuc", "Truc", "Mai"};
	listConfig(n, label, name);
	

	return 0;
}
