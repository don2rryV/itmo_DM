#include <bits/stdc++.h>
#include <fstream>

using namespace std;

fstream in ("nextsetpartition.in");
ofstream out ("nextsetpartition.out");

void nextSetPartition(vector<vector<int> > a){

    vector <int> used;

    bool fl = false;
    int i = a.size()-1;
    int for_u;
    int len = a.size() -1;
    for (i = len; i >= 0; i--){

            if (used.size() != 0 && used[used.size() - 1] > a[i][a[i].size() - 1]) {
                int u = used.size() - 1;
                while (used[u] > a[i][a[i].size() - 1]) u--;
                u++;
                for_u = used[u];
                a[i].push_back(used[u]);
                //used.pop_back();

                break;
            }
        int j = a[i].size()-1;

        for (j = a[i].size() - 1; j >= 0; j--){

            if ((used.size() != 0) && (j != 0) && (used[used.size() - 1] > a[i][j])){
                int u = used.size() - 1;
                while (u >= 0 && used[u] > a[i][j]) u--;
                u++;

                used.push_back(a[i][j]);
                for_u = used[u];

                a[i][j] = used[u];
                if (used.size() > 1)
                    sort(used.begin(), used.end());
                fl = true;
                break;
            }
            if (!fl) used.push_back(a[i][j]);
            if (used.size() > 1)
                sort(used.begin(), used.end());
            a[i].pop_back();
            if (a[i].size() == 0) a.resize(a.size()-1);



        }

        if (fl) break;

    }

// if (used.size() != 0) a.push_back({used[0]});

 for(int x = 0 ; x < used.size(); x++){
    if (used[x] != for_u)
        a.push_back({used[x]});
 }

cout << a.size() << endl;

 for (int i = 0; i < a.size(); i++){
    for (int j = 0; j < a[i].size(); j++){
        cout << a[i][j] <<" ";
    }
    cout << endl;
 }
cout << endl;


}
int main()
{

    int n, k;
    //in >> n >> k;
    vector <vector <int> >a;

    /*while (true){

        string s = "";
        //in >> n >> k;
        //cout << n <<" " <<  k << endl;
        getline(in,s);
        int j = 0; int buf = 0;
                while(s[j] != ' ' && j < s.length()){
                    buf = 10*buf + int(s[j]) - 48;
                    //cout << "buf = " << buf << endl;
                    j++;
                }
                n = buf;
                j++;
                buf = 0;
                while(s[j] != ' ' && j < s.length()){
                    buf = 10*buf + int(s[j]) - 48;
                    //cout << "buf = " << buf << endl;
                    j++;
                }
                k = buf;



        a.resize(0);

        if (n == 0 && k == 0) break;
        cout << n << " ";
        a.resize(k);
        getline(in,s);
        //cout << s;
        for (int i = 0; i < k; i++){
            getline(in, s);
            //cout << s;
            int j = 0;
            while (j < s.length()){
                int buf = 0;
                while(s[j] != ' ' && j < s.length()){
                    buf = 10*buf + int(s[j]) - 48;
                    //cout << "buf = " << buf << endl;
                    j++;
                }
                a[i].push_back(buf);
                j++;
            }



        }

             for (int m = 0; m < a.size(); m++){
    for (int mm = 0; mm < a[m].size(); mm++){
        cout << a[m][mm] <<" ";
    }
    cout << endl;
 }
        nextSetPartition(a);
        getline(in,s);
    }

    in.close();
    out.close();


    //nextSetPartition(a);*/







}
