#include<bits/stdc++.h>

using namespace std;

int max(vector<int>& a, int l, int r){
	if(l==r) return a[l];
	int m = (l + r)/2;
	return max(max(a,l,m),max(a,m+1,r));
}

int main(){
	vector<int> a = {3,9,9,1,5};
	cout<<max(a,0,a.size()-1);
	return 0;
}
