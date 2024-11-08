#include<bits/stdc++.h>
#include "queueArray.cpp"
using namespace std;

int main() {
    int thao_tac;
    cin >> thao_tac;
    Queue<int> q;
    int lua_chon, n;
    while (thao_tac--) {
        cin >> lua_chon;
        if (lua_chon == 1) {
            cout<<"Nhap so can them:";
            cin >> n;
            q.push(n);
        } else if (lua_chon == 2) {
            if (!q.empty()) {
                q.pop();
                cout<<"Da xoa phan tu dau tien!"<<endl;
            }
        } else if (lua_chon == 3) {
            if (!q.empty()) {
                cout <<"Phan tu dau hang doi la:"<<q.front()<< endl;
            } else {
                cout << "Empty!" << endl;
            }
        }
    }
    return 0;
}