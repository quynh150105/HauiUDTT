#include<bits/stdc++.h>

using namespace std;

struct Item{
	int m;
	int k;
};

// sap xep theo m/k
bool cmp(Item a, Item b){
	return (double)a.m/a.k > (double)b.m/b.k;
}

int main(){
	int n,K;
	cin>>n;
	vector<Item> a(n);
	
	for(int i = 0; i< n; i++){
		cin>>a[i].m>>a[i].k;
	}
	
	cin>> K;
	
	sort(a.begin(),a.end(), cmp);
	
	int totalWeight = 0;
	int totalSize = 0;
	
	for(int i = 0; i< n; i++){
		if(totalSize + a[i].k <= K){
			totalSize += a[i].k;
			totalWeight += a[i].m;
		    cout << "(" << a[i].m << ", " << a[i].k << ")\n";
		}
	}
	
    cout << "Tong khoi luong: " << totalWeight;
	return 0;
}
