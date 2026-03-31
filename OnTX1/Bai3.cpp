#include<bits/stdc++.h>

using namespace std;

void haNoiTower(int n, char a, char b, char c){
	if(n==1){
		cout<<"chuyen tu: "<<a<<" sang: "<<c<<endl;
	}
	else{
		haNoiTower(n-1,a,c,b);
		cout<<"chuyen tu: "<<a<<" sang: "<<c<<endl;
		haNoiTower(n-1,b,a,c);
	}
}

int main(){
	haNoiTower(3,'A','B','C');

	return 0;
}
