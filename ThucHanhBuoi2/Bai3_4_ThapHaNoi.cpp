#include<bits/stdc++.h>

using namespace std;

void chuyen(int n, char A, char B, char C) {
    if (n == 1) {
		cout<<"Chuyen: "<< A << "sang "<<C<<endl;
        return;
    }
    chuyen(n - 1, A, C, B);
	cout<<"Chuyen: "<< A << " sang "<<C<<endl;
    chuyen(n - 1, B, A, C);
}

int main(){
	chuyen(3,'A','B','C');
	return 0;
}
