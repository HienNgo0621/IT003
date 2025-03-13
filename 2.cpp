#include<iostream>
#include<string>
using namespace std;

void checkBonusCombo(const string &pass, int &bonusnums, const char symbols[], int symsize){
    bool has_special = false, has_upper = false, has_num = false;

    for (char c : pass){ 
        if ('A' <= c && c <= 'Z') has_upper = true;
        if ('0' <= c && c <= '9') has_num = true;
        for (int i = 0; i < symsize; i++) {
            if (symbols[i] == c) {
                has_special = true;
                break;
            }
        }
    }
    if ((has_special) && (has_num) && (has_upper)) bonusnums = 25;
    else if (((has_special) && (has_num)) || ((has_num) && (has_upper)) || ((has_special) && (has_upper))) bonusnums = 15;
    else bonusnums = 0;
}

void checkBonusFlatLower(const string &pass, int &flatlower){
    bool all_lower = true;
    for (char c : pass){
        if (!('a' <= c && c <= 'z')){
            all_lower = false;
            break;
        }
    }
    flatlower = all_lower ? -15 : 0;
}

void checkBonusFlatNumber(const string &pass, int &flatnum){
    bool all_digit = true;
    for (char c : pass){
        if (!('0' <= c && c <= '9')){
            all_digit = false;
            break;
        } 
    }
    flatnum = all_digit ? -35 : 0;
}


int main (){
    int BaseScore = 40, Bonus_Excess = 3, Bonus_Upper = 4, Bonus_Numbers = 5, Bonus_Symbols = 5; 
    int Bonus_Combo = 0, Bonus_FlatLower = 0, Bonus_FlatNumber = 0;
    int Number_Upper = 0, Number_Numbers = 0, Number_Symbols = 0;
    
    char special_char[] = {'!' , '@' , '#' , '$' , '%' , '^' , '&' , '*' , '?' , '_'  , '~'};
    char invalid_char[] = {'.' , '\\' , '/', '"', '\''};

    string pass;
    cin >> pass;

    //Number_Execess_check
    int Number_Execess = (pass.size() > 8) ? (pass.size() - 8) : 0;


    //Number_Numbers_check
    for (char c : pass){
        if ('0' <= c && c <= '9') Number_Numbers ++;
    }

    //Number_Upper_check
    for (char c : pass){
        if ('A' <= c && c <= 'Z') Number_Upper ++;
    }

    //Number_Symbols_check
    for (char c : pass){
        for (char sc : special_char){
            if (sc == c) Number_Symbols ++;
        }
    }

    //khong hop le

    if (pass.size() < 8) {
        cout << "KhongHopLe" << endl;
        return 0;
    }

    for (char c : pass){
        for (char ic : invalid_char){
            if (ic == c){
                cout << "KhongHopLe" << endl;
                return 0;
            }
        }
    }

    checkBonusCombo(pass, Bonus_Combo, special_char, sizeof(special_char) / sizeof(special_char[0]));
    checkBonusFlatLower(pass, Bonus_FlatLower);
    checkBonusFlatNumber(pass, Bonus_FlatNumber);

    int score = BaseScore + (Number_Execess * Bonus_Excess) + (Number_Upper * Bonus_Upper) + 
    (Number_Numbers * Bonus_Numbers) + (Number_Symbols * Bonus_Symbols) + Bonus_Combo + Bonus_FlatLower + Bonus_FlatNumber;

    if (score < 50) cout << "Yeu" << endl;
    else if (score < 75) cout << "Vua" << endl;
    else if (score < 100) cout << "Manh" << endl;
    else cout << "RatManh" << endl;

    system("pause");
    return 0;
};