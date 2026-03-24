#include <bits/stdc++.h>
using namespace std;

int n = 3;
int a[100];
bool used[100];

void print() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void backtrack(int i) {
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            a[i] = j;
            used[j] = true;

            if (i == n - 1) {
                print();
            } else {
                backtrack(i + 1);
            }

            used[j] = false; // quay lui
        }
    }
}

int main() {
    backtrack(0);
    return 0;
}
