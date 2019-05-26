#include <bits/stdc++.h>

using namespace std;
int n;
string s;
vector <vector <int> > a;
vector <vector <int> > out;
int prov = 0;

int mon(int ii, int left, int right, int len){
    if(len > 0){
    for(int h = left; h < right; h++){
        if (a[ii][h] > a[ii][h+len]) prov ++;
    }
    mon(ii, left, (right-left)/2, (right-left)/2);
    mon(ii, right, right + len/2, (right-left)/2);
    }
    return prov;
}

int main()
{
    int buf;
    cin >> n;
    out.resize(5);

    for (int i = 0; i < 5; i++) out[i].resize(n);

    a.resize(n);
    for (int i = 0; i < n; i++){
        cin >> buf >> s;
        a[i].resize(int(pow(2.0, buf)));
        for (int j = 0; j < int (pow(2.0, buf)); j++){
            if (s[j] == '0') a[i][j] = 0; else a[i][j] = 1;
        }
    }


    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < a[i].size(); j++){
            cout << a[i][j] << " ";
        }
     S   cout << endl;
    }*/


    for (int i = 0; i < n; i++){
       if ((a[i].size() == 1) && (a[i][0] == 0)) {
            out[0][i] = 1;
            out[1][i] = 0;
            out[2][i] = 0;
            out[3][i] = 1;
            out[4][i] = 1;
        }else if(a[i].size() == 1 && a[i][0] == 1){
            out[0][i] = 0;
            out[1][i] = 1;
            out[2][i] = 0;
            out[3][i] = 1;
            out[4][i] = 1;

        }else{

        if(a[i][0] == 0) out[0][i] = 1; //сохраняет 0

        if(a[i][a[i].size()-1] == 1) out[1][i] = 1; //сохраняет 1



        int flag = 0;
        for (int j = 0; j < a[i].size()/2; j++){
            if (a[i][j] != a[i][a[i].size()-1-j]) flag++;
        }
        if (flag == a[i].size()/2) out[2][i] = 1; else out[2][i] = 0;


        prov = 0;
        if (mon(i, 0, (a[i].size())/2, a[i].size()/2) != 0){
            out[3][i] = 0;
        } else out[3][i] = 1;
       // mon(i, a[i].size()/2, a[i].size()-1, a[i].size()/2);



      /*  flag = 1;
        for (int j = 1; j < a[i].size(); j++){
            if (a[i][j] < a[i][j-1]) flag = 0;
        }
        out[3][i] = flag;*/


        vector <vector <int > > b;
        b.resize(a[i].size());
        for (int j = 0; j < b.size(); j++){
            b[j].resize(a[i].size());
        }
        for (int j = 0; j < b.size(); j++){
            b[j][0] = a[i][j];
        }

        for (int j = 1; j < b.size(); j++){
        for (int k = 0; k < b.size()-j; k++){
            b[k][j] = (b[k][j-1] + b[k+1][j-1]) % 2;
        }
        }

       // if (b[0][0] == 1) out[4][i] = 1; else{
       out[4][i] = 1;
            int p = 0; //cout << int(pow(2.0, 0)) << endl;
            for (int j = 1; j < b.size(); j++){
                if (j != int (pow(2.0, p))){
                    if (b[0][j] == 1) out[4][i] = 0;


                }else{p++;}
            }
        //}
//cout << "proshlo 4" << endl;

     /*  for (int k = 0; k < b.size(); k++){
        for (int j = 0; j < b.size(); j++){
         cout << b[k][j] << " ";
        }
        cout << endl;
        }

    cout << endl;*/}
    }

   /* for (int i = 0; i< 5; i++){
        for (int j= 0; j < n; j++){
            cout << out[i][j];
        }
        cout<< endl;

    }*/
    int sum;
    bool flag_main = true;

    for (int i = 0; i < 5; i++){
        sum = 0;
        for (int j = 0; j < n; j++){
            sum += out[i][j];
        }
        if (sum == out[i].size()){
            flag_main = false;
        }
    }

    if (flag_main) cout << "YES"; else cout << "NO";


}
