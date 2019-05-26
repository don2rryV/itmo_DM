#include <bits/stdc++.h>

using namespace std;
int n;
vector <vector <int> > a;
vector <vector <int> > ssyl;
vector <int> p, notp;
vector <int> znach;
vector <int> glub;
vector <int> st;
int next(){
    for (int m = 0; m < notp.size(); m++){
        int step = 0; int ans = 0;
        for (int mm = ssyl[notp[m]].size()-1; mm >= 0; mm--){
            ans += znach[ssyl[notp[m]][mm]]*st[step];
            step++;
        }
    znach[notp[m]] = a[notp[m]][ans];
    }
}

bool func (int k, int length){
    if (k<length){
        znach[p[k]] = false;
        func(k+1,length);
        znach[p[k]] = true;
        func(k+1, length);
    }else {
   next();

    /*for (int i = 0; i < n; i++){
            cout << znach[i] <<" ";
        }
       cout << endl;
    */
    cout << znach[znach.size()-1];

}
}

int main()
{
    ios_base::sync_with_stdio(false);
    int buf, buf2;
    cin >> n;
    st.resize(10);
    for (int i =0; i < 10; i++){
        st[i] = int (pow(2.0, i));
    }
    if (n == 0) cout << "0"; else{
    a.resize(n); ssyl.resize(n); glub.resize(n);
    for (int i = 0; i < n; i++){
        cin >> buf;
        a[i].resize(int(pow(2.0, buf)));
        if (buf == 0) {
            ssyl[i].push_back(0);
            p.push_back(i);
            glub[i] = 0;
        } else{
            notp.push_back(i); int maxm = -1;
            for (int j = 0; j < buf; j++){
                cin >> buf2;
                if (glub[buf2-1] > maxm) maxm = glub[buf2-1];
                ssyl[i].push_back(buf2-1);
            }
            glub[i] = maxm + 1;
        }
        if (buf != 0){
            for (int j = 0; j < int(pow(2.0, buf)); j++){
                cin >> a[i][j];
            }
        }
    }

    int cnt_list = p.size();
    znach.resize(n);
  int ans_g = glub[0];


    for (int i = 1; i < glub.size(); i++){
           // cout << glub[i] << " ";
        if (glub[i] > ans_g) ans_g = glub[i];
    }

    cout << ans_g << endl;
    func(0, cnt_list);
    }

/*cout << "a " << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < a[i].size(); j++){
            cout << a[i][j] << " ";
        }
    cout << endl;
    }

    cout << "ssyl" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < ssyl[i].size(); j++){
            cout << ssyl[i][j] << " ";
        }
    cout << endl;
    }

cout << "p" << endl;
    for (int i = 0; i < p.size(); i++){
        cout << p[i] << " ";
    }

cout << endl;
cout << "notp" << endl;
for (int i = 0; i < notp.size(); i++){
        cout << notp[i] << " ";
    }*/




}
