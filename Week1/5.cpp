#include<iostream>
#include<vector>
#include<string>

using namespace std;

void input(vector<string> &v){
    for (string &x : v){
        cin >> x;
    }
}

int BinarySearch(const vector<string> &v, string x, int &cnt){
    int l = 0, r = v.size() - 1;
    while(l <= r){
        cnt ++;
        int m = (l + r) / 2;
        if (v[m] == x){
            return m;
        }
        else if (v[m] < x){
            l = m + 1;
        } 
        else {
            r = m - 1;
        }

    }
    return -1;
}

int main(){
    int n, cnt = 0;
    cin >> n;
    vector<string> v(n);
    input(v);
    string x;
    cin >> x;
    int result = BinarySearch(v, x, cnt);
    cout << result << endl << endl;
    if (result != -1) cout << cnt << endl;

    system("pause");
    return 0;
}