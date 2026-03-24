#include <bits/stdc++.h>
using namespace std;

int n = 3;
int a[100]; 

void print() {
    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
    cout << endl;
}

void backtrack(int i) {
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == n - 1) {
            print();
        } else {
            backtrack(i + 1);
        }
    }
}

int main() {
    backtrack(0);
    return 0;
}
