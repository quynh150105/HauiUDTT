#include<bits/stdc++.h>

using namespace std;

void merge(vector<float>&a, int l, int m, int r){
	vector<float> temp;
	int i = l, j = m + 1;
	
	while(i <= m && j<=r){
		if(a[i] < a[j]) temp.push_back(a[i++]);
		else{
			temp.push_back(a[j++]);
		}
	}
	
	while( i<= m) temp.push_back(a[i++]);
	while( j<= r) temp.push_back(a[j++]);
	
	for(int k = 0; k<temp.size(); k++){
		a[l + k] = temp[k];
	}
}
void mergeSort(vector<float> & a, int l, int r){
	if(l>=r) return;
	int m = (l + r )/2;
	mergeSort(a,l,m);
	mergeSort(a,m+1,r);
	merge(a,l,m,r);
}

int main(){
	vector<float> a = {3.2, 1.5, 7.8, 2.4, 9.0, 0.6};
    mergeSort(a, 0, a.size() - 1);
	
	for(float x : a){
		cout<<x<<" ";
	}
	
		return 0;
}
