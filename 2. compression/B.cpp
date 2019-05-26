#include <bits/stdc++.h>

using namespace std;
vector <string> a;
int main()
{
    freopen("bwt.in","r",stdin);
    freopen("bwt.out","w",stdout);
    string s, buf;
    char buf_;
    cin >> s;
    a.resize(s.length());

    a[0] = s; int k = 1;
    for (int i = 1; i < s.length(); i++){
        buf_ = s[0];
        for (int j = 0; j < s.length()-1; j++){
            buf += s[j+1];
        }
        buf += buf_;
        s = buf;
        a[k] = buf;
        buf = "";
        k++;
    }






    sort(a.begin(), a.end());
    for (int i = 0; i < s.length(); i++){
        cout << a[i][s.length()-1];
    }



}
