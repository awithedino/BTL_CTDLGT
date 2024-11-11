#include "queueList.cpp"
using namespace std;

void dao_nguoc(Queue<int>& q) {
    int s = q.size();
    Queue<int> temp;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < q.size() - 1; j++) {
            int t = q.front();
            q.pop();
            q.push(t);
        }
        temp.push(q.front());
        q.pop();
    }

    while (!temp.empty()) {
        q.push(temp.front());
        temp.pop();
    }
}

int main() {
    Queue<int> B;
    long long n;

    cout << "Nhap so luong so can them: ";
    cin >> n;

    while (n < 0 || n > 105 * 2) {
        cout << "Moi ban nhap lai:" << endl;
        cout << "Nhap so luong so can them: ";
        cin >> n;
    }

    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        while (a < 0 || a > 109) {
            cout << "Nhap lai so can them: ";
            cin >> a;
        }
        B.push(a);
        dao_nguoc(B);
    }

    while (B.size()) {
        cout << B.front() << " ";
        B.pop();
    }
    cout << endl;
    return 0;
}