#include<bits/stdc++.h>

using namespace std;

struct Work{
	string id;
	string begin;
	string end;	
};

void Show(Work a){
	cout << "ID: " << a.id << "\n";
	cout << "Thoi gian bat dau: " << a.begin << "\n";
	cout << "Thoi gian thuc hien: " << a.end << "\n";
}

void hienNguoc(Work *a, int n){
	if(n==0) return;
	else{
		Show(a[n-1]);
		hienNguoc(a,n-1);
	}
}

void viewConfig(int k, int x[], Work *a){
	for(int i = 1; i<=k; i++){
		cout<<a[x[i]-1].id<<" ";
	}
	cout<<endl;
}

void nextConfig(int k, int x[], int i){
	x[i]++;
	for(int j = i+1; j<=k; j++){
		x[j] = x[j-1] + 1;
	}
}

void listConfig(int n, int k, Work * a){
	int i;
	int x[100] = {0};
	for(int i = 1; i<=k; i++){
		x[i] = i;
	}
	do{
		viewConfig(k,x,a);
		i = k;
		while(i> 0 && x[i] == n-k + i) i--;
		if(i>0) nextConfig(k,x,i);
	}
	while(i>0);
}


int main(){
		int n = 6;
	Work *a = new Work[n];
	a[0] = {"W001", "12:30", "01:30"};
	a[1] = {"W002", "12:30", "00:30"};
	a[2] = {"W003", "12:30", "02:30"};
	a[3] = {"W004", "12:30", "04:30"};
	a[4] = {"W005", "12:30", "00:30"};
	a[5] = {"W006", "12:30", "02:30"};
	
	cout<<"Danh sach cong viec: "<<endl;
	hienNguoc(a,n);
	listConfig(n,5,a);
	return 0;
}
