#include<iostream>
#include<stack>
using namespace std;

bool Valid (string str){
    stack<char> st;
    for (int i = 0; i < str.size(); i ++){ //opening
        if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
            st.push(str[i]);
        } else if (str[i] == '}' || str[i] == ']' || str[i] == ')'){ //closing
            if (st.size() == 0) return false; //co closing khong co opening
            if ((st.top() == '{' && str[i] == '}') ||
            (st.top() == '[' && str[i] == ']') ||
            (st.top() == '(' && str[i] == ')')){
                st.pop();
            } else { //no match
                return false;
            }
        }
    }
    return st.size() == 0;
}

int main (){
    string s;
    cin >> s;
    cout << (Valid(s) ? "1" : "0");
    
    system("pause");
    return 0;
}