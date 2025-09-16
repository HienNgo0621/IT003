#include<iostream>
using namespace std;

void merge(int *n1, int a1, int *n2, int a2, int *a){
    // current la vi tri hien tai cua mang a
    int i = 0, j = 0, current = 0;

    // tron hai mang theo thu tu

    while (i < a1 && j < a2){
        if (n1[i] <= n2[j]){
            a[current ++] = n1[i ++];
        }
        else 
            a[current ++] = n2[j ++];
    }
    // neu mang con phan tu thi luu vao a[]

    while (i < a1){
        a[current ++] = n1[i ++];
    }

    while (j < a2){
        a[current ++] = n2[j ++];
    }

}



int main (){
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n, m;
    int t; cin >> t;
    while (cin >> n >> m || t > 0){ 
        t--;
        int *a = new int [n], *b = new int[m], *c = new int[n+m];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

	merge(a, n, b, m, c);
	int nc = n + m;;
        for(int i = 0; i < nc; i++){
            cout << c[i] << " ";
        }
        delete c;
        cout << endl;
    }

    system("pause");
    return 0;
}
