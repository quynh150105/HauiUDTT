#include<bits/stdc++.h>

using namespace std;

struct Flight{
	string id;
	float cost;
	int cnt;
};

void findCost(Flight *a, vector<Flight>& res, int l, int r){
	if(l==r){
		if(a[l].cost > 700000){
			res.push_back(a[l]);
		}
	}
	else{
		int m = (l+r)/2;
		findCost(a,res,l,m);
		findCost(a,res,m+1,r);
	}
}

int findMin(Flight *a,int l, int r){
	if(l == r){
		return l;
	}
	else{
		int m = (l + r)/2;
		int lMin = findMin(a,l,m);
		int rMin = findMin(a,m+1,r);
		if(a[lMin].cost < a[rMin].cost) return lMin;
		else return rMin;
	}
}

void view(Flight *a, int x[], int k){
	for(int i = 0; i< k; i++){
		cout<<a[x[i]-1].id<<" ";
	}
	cout<<endl;
}

void Try(int n, int k, Flight * a, int x[], int start, int size){
	if(k==size){
		view(a,x,k);
	}
	else{
		for(int i = start; i <= n; i++){
			x[size] = i;
			Try(n,k,a,x,i+1, size+1);
		}
	}
}

/* Sinh

void nextConfig(int k, int x[], int i){
	x[i]++;
	for(int j = i+1; j<=k; j++){
		x[j] = x[j-1] + 1;
	}
}

void listConfig(int n, int k, Flight* a){
	int i;
	int x[100];
	for(int i = 1; i<=k; i++){
		x[i] = i;
	}
	do{
		for(int i = 1; i<= k; i++){
			cout<<a[x[i] -1].id<<" ";
		}
		cout<<endl;
		i = k;
		while(i>0 && x[i] == n-k + i){
			i--;
		}
		if(i>0){
			nextConfig(k,x,i);
		}
	}while(i>0);
}
*/



int main(){
	int n = 6;
	int x[100];
	Flight * a = new Flight[n];
	a[0] = {"VN001", 2000000, 30};
	a[1] = {"VN002", 100000, 40};
	a[2] = {"VN003", 300000, 50};
	a[3] = {"VN004", 5000000, 40};
	a[4] = {"VN005", 300000, 20};
	a[5] = {"VN006", 4000000, 60};
	
	cout<<"Cac chuyen bay lon hon 700000: "<<endl;
	vector<Flight> res;
	findCost(a,res,0,n-1);
	if(res.size()==0){
		cout<<"Khong co chuyen nao"<<endl;
	}
	else{
		for(int i = 0; i< res.size(); i++){
			cout<<res[i].id<<endl;
		}
	}
	
	cout<<"chuyen bay co gia thap nhat: "<<endl;
	int kq = findMin(a,0,n-1);
	cout<<a[kq].id<<endl;
	
	cout<<"cach chon 4 chuyen bay: "<<endl;
	int k = 4;
//	listConfig(n,k,a);
	Try(n,k,a,x,1,0);	
	
	return 0;
}
