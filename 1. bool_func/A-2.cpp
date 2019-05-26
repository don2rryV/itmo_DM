#include <bits/stdc++.h>

using namespace std;
int n, m;
vector <int> a;
vector <vector <int> > b;
bool flag_main = true;

bool main_main(){
    int p1, p2; bool flag = false;
    for (int i = 0; i < 2*n; i++){
        for (int j = 0; j < i+1; j++){
            if (b[i][j] == 1) {
                    //cout << b[i][j] << " ";
                if(i >= n) p1 = (a[i-n] + 1) %2; else p1 = a[i];
                if(j >= n) p2 = (a[j-n] +1) %2; else p2 = a[j];
               // cout << p1 <<" " << p2 << endl;
                if (p1 == 0 && p2 == 0) flag = true;

            }
        }
        //cout <<endl;
    }
if (flag) return 1; else return 0;

}


bool func (int k, int length){
    if (k<length){
        a[k] = false;
        func(k+1,length);
        a[k] = true;
        func(k+1, length);
    }else{

       /* for (int i = 0; i < length; i++){
            cout << a[i] <<" ";
        }
       cout << endl;*/
    if (main_main() == 0) {flag_main = false;}

    }
}

int main()
{
    cin >> n >> m;
    a.resize(n);
    b.resize(2*n);
    for (int i = 0; i < b.size(); i++) b[i].resize(2*n);
    int buf, buf2;
    for (int i = 0; i < m; i++){
        cin >> buf >> buf2;
        if(buf < 0) buf = abs(buf) - 1 + n; else buf--;
        if (buf2 < 0) buf2 = abs(buf2) - 1 + n; else buf2--;
        b[buf][buf2] = 1;
        b[buf2][buf] = 1;

    }
/*    for (int i = 0; i < 2*n; i++){
        for (int j = 0; j < 2*n; j++){
            cout << b[i][j] << " ";

        }
        cout << endl;
    }*/


    func(0,n);
    if (!flag_main) cout << "NO"; else cout <<"YES";

}
