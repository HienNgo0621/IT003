#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void input(vector<int> &a){
    for (int &i : a){
        cin >> i;
    }
}

int LinearSearch(vector<int> &a){
    sort(a.begin(), a.end()); // Sắp xếp mảng A

    // Tính trọng số của 2 dãy con tối ưu
    int weight1 = a[a.size() - 1] - a[0];
    int weight2 = (a.size() > 2) ? (a[a.size() - 2] - a[1]) : 0;

    return (weight1 + weight2);
}

int main (){
    int n;
    cin >> n;
    vector<int> res;
    for (int i = 0; i < n; i ++){
        int a;
        cin >> a;
        vector<int> v(a, 0);
        input(v);
        res.push_back(LinearSearch(v));
    }
    for (int i : res){
        cout << i << endl << endl;
    }

    system("pause");
    return 0;
}