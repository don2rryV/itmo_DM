#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("lzw.in","r",stdin);
    freopen("lzw.out","w",stdout);
    vector <string> a;
    a.resize(100000);
    int m = 97;
    for (int i = 0; i < 26; i++){
        a[i] = char(m);
        m++;
    }
    string s, buf1, buf2;
    cin >> s;
    int k = 26;
    if (s.length() != 0) {
    buf1 = s[0]; bool flag = true;
    for (int i = 1; i < s.length(); i++){
        buf2 = s[i];
       // cout << buf1 + buf2 << endl;
        flag = true;
        for (int j = 0; j < a.size(); j++){
            if (buf1+buf2 == a[j]){
                flag = false;
                buf1 = buf1+ buf2;
                break;
            }
        }
            if (flag){
                for (int j = 0; j < a.size(); j++){
                    if (buf1 == a[j]) {
                            cout << j << " ";
                            a[k] = buf1+buf2;
                            buf1 = buf2;
                            k++;
                            break;
                    }
                }
            }



    if (i == s.length() - 1){
        for (int j = 0; j < a.size(); j++){
                if (buf1 == a[j]) {
                        cout << j << " ";
                }
        }
    }

    }
    }
    if (s.length() == 1){
        for (int j = 0; j < a.size(); j++){
                if (buf1 == a[j]) {
                        cout << j << " ";
                }
        }
    }

}
