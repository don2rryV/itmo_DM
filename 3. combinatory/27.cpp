#include <bits/stdc++.h>

using namespace std;
int n;
vector <char> a;

bool next_sk(){
    int cnt_close = 0;
    int cnt_open = 0;
    for (int i = a.size()-1; i > -1; i--){
        if (a[i] == '('){
                cnt_open++;
                if (cnt_close > cnt_open) break;
        } else {
            cnt_close++;
        }
    }
    for (int i = 2*n -1 - cnt_open - cnt_close; i < 2*n-1; i++){
        a.pop_back();
    }

    if (a.size() == 0){
        return false;
    } else {
        a.push_back(')');
        for (int j = 0; j < cnt_open; j++){
            a.push_back('(');
        }
        for (int j = 0; j < cnt_close - 1; j++){
            a.push_back(')');
        }
    }
    return true;
}


int main()
{
    freopen("nextbrackets.in","r",stdin);
    freopen("nextbrackets.out","w",stdout);
    string s;
    cin >> s;
    a.resize(s.length());
    for (int i = 0; i < a.size(); i++){
        a[i] = s[i];
    }
    if (next_sk()){
    for (int i = 0; i < a.size(); i++){
        cout << a[i];
    }
    cout << endl;}else{
        cout << "-";}
}
