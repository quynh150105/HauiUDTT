#include<bits/stdc++.h>

using namespace std;

float sum(vector<float>&a, int l, int r){
	if(l == r){
		if(a[l] > 0) return a[l];
		else return 0;
	}
	
	int m = (l + r)/2;
	return sum(a,l,m) + sum(a,m+1,r);
}


int main(){
	 vector<float> a = {1.5, -2.3, 4.0, -1.2, 3.3};
    cout << "Tong duong = " << sum(a, 0, a.size() - 1);
	return 0;
}
