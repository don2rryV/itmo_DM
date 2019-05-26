#include <bits/stdc++.h>

using namespace std;
string s;
vector <int> a;
int k;
bool next_sum(){
    a[k-1]--; a[k-2]++;
    if (a[k-2] > a[k-1]){
        a[k-2] += a[k-1];
        a.pop_back();
        k--;
    } else{
        while (a[k-2] * 2 <= a[k-1]){
            a.push_back(a[k-1] - a[k-2]);
            k = a.size();
            a[k-2] = a[k-3];
        }
    }
}


int main()
{
    freopen("nextpartition.in","r",stdin);
    freopen("nextpartition.out","w",stdout);
    cin >> s;
    //a.resize(1);
    int ind = 0;
    int n = 0;
    while (s[ind] != '='){
        n = 10*n + int(s[ind]) - 48;
        ind++;
    }
    ind++;
    int buf;
    while (ind < s.length()){
        buf = 0;
        while(s[ind] != '+' && ind < s.length()){
            buf = buf*10 + int(s[ind]) - 48;
            ind++;
        }
        a.push_back(buf);
        ind++;
    }
    if (a.size()==1){
        cout << "No solution";
    }else{



    k = a.size();
    next_sum();
            cout << n << "=";
    for (int i = 0 ; i < a.size(); i++){
      /*  if (i != a.size() - 1){
            if (a[i] != 0 && a[i+1] != 0) cout << a[i] << "+";
            else if (a[i] != 0) cout << a[i];
        } else {
            if (a[i] != 0) cout << a[i];
        }*/
        if (i != a.size()-1)
        cout << a[i] << "+"; else
        cout << a[i];
    }

    }
}
