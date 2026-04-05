#include<bits/stdc++.h>

using namespace std;

struct Job{
	int start, end;

};

bool cmp(Job a, Job b){
	return a.end < b.end;
}

int main(){
	
	int n;
	cin>>n;
	
	vector<Job> a(n);
	for(int i = 0; i< n; i++){
		cin>>a[i].start >> a[i].end;
	}
	
	sort(a.begin(), a.end(), cmp);
	
	int count = 1;
	int lastEnd = a[0].end;
	
    cout << "Chon: (" << a[0].start << ", " << a[0].end << ")\n";
	
	for(int i = 1; i< n; i++){
		if(lastEnd <= a[i].start)
            cout << "Chon: (" << a[i].start << ", " << a[i].end << ")\n";
			lastEnd = a[i].end;
			count++;
		}
	}
	
	cout<<"So cong viec toi da: "<<count;
	
	return 0;
}
