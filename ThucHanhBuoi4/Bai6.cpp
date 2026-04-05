#include<bits/stdc++.h>

using namespace std;

struct Item{
	int s;
	int m;
};

bool cmp(Item a, Item b){
	return a.m < b.m;
}

int main(){
	int n, K;
	cin>>n;
	
	vector<Item> a(n);
	for(int i = 0; i< n; i++){
		cin>>a[i].s>>a[i].m;
	}
	
	cin>>K;
	
	sort(a.begin(), a.end(), cmp);
	
	int totalSize = 0;
	int totalWeight = 0;
	
	for(int i =0; i<n; i++){
		if(totalSize + a[i].s <= K){
			totalSize += a[i].s;
			totalWeight += a[i].m;	
		    cout << "(" << a[i].s << ", " << a[i].m << ")\n";
		}
	}

	cout << "Tong khoi luong: " << totalWeight;
	
	return 0;
}
