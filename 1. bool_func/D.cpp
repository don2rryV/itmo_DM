#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > a;
vector <long long> start;
long long n,buf, ans;
vector <int> tabl;
vector <int> step;

int bin2(long long k, int ind){
    int i = a[buf].size()-1;
    do{
        a[ind][i] = k%2;
        k /= 2;
        i--;
    }while (k > 0);

}

int bin(long long k, int ind){
    int i = 0;
    do{
        a[ind].push_back(k%2);
        k /= 2;
        i++;
    }while (k > 0);

    for (i= 0; i < a[buf].size()/2; i++) swap(a[buf][i], a[buf][a[buf].size()-1-i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    a.resize(n+1);
    start.resize(n+1);
    long long maxm = -1;
    for (int i = 0; i < n; i++){
        cin >> start[i];
        if (start[i] > maxm) {buf = i;maxm = start[i];}
    }

    cin >> ans;
 //s   cout << "ans " << ans << endl;
    start[n] = ans;
    if (ans > maxm) buf = n;
    if (ans == 0) cout << "1&~1"; else{
    bin(start[buf], buf);

  //  cout << a[buf].size();
    for (int i = 0; i < n+1; i++){
        if (i != buf) a[i].resize(a[buf].size());
    }
    for (int i = 0; i < n+1; i++){
        if (i != buf) bin2(start[i], i);
    }

    step.resize(5);
    for (int i = 0; i < 5; i++){
        step[i] = int(pow(2.0,i));
    }

    tabl.resize(int(pow(2.0, n)));

    for (int i = 0; i < tabl.size(); i++) tabl[i] = -1;

    bool flag = true;

    for (int j = 0; j < a[buf].size(); j++){
        long long rez = 0;
        for (int i = 0; i < n; i++){
            rez += a[i][j]*step[n-1-i];
        }
        if(tabl[rez] == -1) tabl[rez] = a[n][j];
        else if (tabl[rez] != a[n][j]) {flag = false; break;}
    }
/*for (int i = 0; i < n+1; i++){
        for (int j = 0; j < a[i].size(); j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < tabl.size(); i++){
        cout << tabl[i] << " ";
    }
    cout << endl;*/



    string s = ""; long long chet = 0;
    if (!flag) {
        cout << "Impossible";
    } else{
        for (int i = 0; i < tabl.size(); i++){
        if(i == 0 && tabl[i] == 1) {cout << "Impossible"; break;}
            if (tabl[i] == 1) {
                chet++;
                if(chet != 1) //s += '|';
                    cout << '|';
                int ii = i; long long sp = n;
                int chet2 = 0;


                while (ii >= 0 && sp > 0){
                    if (ii%2 == 1){
                        //s += sp;
                        if (sp != 0) cout << sp;
                        sp--;
                        ii /= 2;
                        if (ii == 0) chet2++;
                    if (sp > 0) //s += '&';
                        cout << '&';
                    }else{
                        //s += '~';
                        //s += sp;
                        if (sp != 0) cout << '~' << sp;
                        sp--;
                        ii /= 2;
                        if (ii == 0) chet2++;
                        if (sp > 0) //s += '&';
                            cout << '&';
                    }
                }

            }


        }



    }





    }
   // if (s == "") {
   //     cout << " s == 0";
    //}else
    //cout << s;



}
