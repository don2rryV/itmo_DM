#include <bits/stdc++.h>

using namespace std;
vector <char> a;
int main()
{
    freopen("mtf.in","r",stdin);
    freopen("mtf.out","w",stdout);
    int k = 97;
    a.resize(26);
    for (int i = 0; i < 26; i++){
        a[i] = char(k);
        k++;
    }


    string s;
    cin >> s;
    int buf;

    for (int i = 0; i < s.length(); i++){
        for (int j = 0; j < 26; j++){
            if (a[j] == s[i]){
                    buf = j;
                    cout << j+1 << " ";
                    break;
            }
        }
        for (int j = buf; j > 0; j--){
            a[j] = a[j-1];
        }
        a[0] = s[i];



    }

}
