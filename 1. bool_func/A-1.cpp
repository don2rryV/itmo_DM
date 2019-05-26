#include <bits/stdc++.h>

using namespace std;
vector <bool> a;
int m;

vector < vector <int> > f;
bool out = true;

bool prov(){
    for (int j = 0; j < m; j++){
        if (f[j][0] == 0 && f[j][2] == 0 && !(!a[f[j][1]-1] || !a[f[j][3]-1]))
        {return true;}
        else if ( f[j][0] == 0 && f[j][2] == 1 && !(!a[f[j][1]-1] || a[f[j][3]-1]) ) return true;
        else if ( f[j][0] == 1 && f[j][2] == 0 && !(a[f[j][1]-1] || !a[f[j][3]-1]) ) return true;
        else if ( f[j][0] == 1 && f[j][2] == 1 && !(a[f[j][1]-1] || a[f[j][3]-1]) ) return true;
    }
    return false;
}

bool func (int k, int length){
    if (k<length){
        a[k] = false;
        func(k+1,length);
        a[k] = true;
        func(k+1, length);
    }else{

    if (prov() == false){
        out = false;
    }
    }
}

int main()
{
    int n, buf;
    a.resize(32769);
    f.resize(4);
    cin >> n >> m;
    for (int i = 0; i < 4; i++) f[i].resize(m);

    for (int i = 0; i < m; i++){
        cin >> buf;
        if (buf < 0) {
            f[i][0] = 0;
            f[i][1] = abs(buf);
        } else {
            f[i][0] = 1;
            f[i][1] = buf;
        }
        cin >> buf;
        if (buf < 0) {
            f[i][2] = 0;
            f[i][3] = abs(buf);
        } else {
            f[i][2] = 1;
            f[i][3] = buf;
        }

    }


    func(0, n);
    if (out) cout << "YES";
    else cout << "NO";


}
