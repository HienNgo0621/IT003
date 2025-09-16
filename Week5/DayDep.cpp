#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> freq;
    for (int &x : arr){
        cin >> x;
    }
    for (int x : arr){
        freq[x]++;
    }
    int step = 0;
    for (const auto& [x, count] : freq){
        if (count == x) continue;
        else if (count > x) {
            step += count - x;
        }
        else step += count;
    }

    cout << step << endl;

    system("pause");
    return 0;
}