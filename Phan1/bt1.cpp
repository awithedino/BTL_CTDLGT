#include <bits/stdc++.h>
using namespace std;

class Student {
private:
    string studentID;
    string fullName;
    int age;
    double score;

public:
    Student() : studentID(""), fullName(""), age(0), score(0.0) {}
    ~Student() {}

    friend istream& operator>>(istream& is, Student& s) {
        cout << "Ma sinh vien: ";
        getline(is >> ws, s.studentID); // `ws` to discard any whitespace before input
        cout << "Ho va ten: ";
        getline(is, s.fullName);
        cout << "Tuoi: ";
        is >> s.age;
        cout << "Diem so: ";
        is >> s.score;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Student& s) {
        os << '|' << setw(15) << s.studentID
           << '|' << setw(20) << s.fullName
           << '|' << setw(5) << s.age
           << '|' << setw(8) << s.score << '|';
        return os;
    }

    bool operator<(const Student& s) const {
        return this->score < s.score;
    }

    string getName() const {
        return fullName;
    }

    double getScore() const {
        return score;
    }
};

class StudentList {
private:
    list<Student> studentList;

public:
    StudentList() {}
    ~StudentList() {}

    void input() {
        int n;
        cout << "Nhap so luong sinh vien: ";
        cin >> n;
        for (int i = 0; i < n; ++i) {
            Student s;
            cin >> s;
            studentList.push_back(s);
        }
    }

    void output() {
        cout << "+---------------+----------------------+-----+--------+\n";
        cout << '|' << setw(15) << "Ma SV"
             << '|' << setw(20) << "Ho va ten"
             << '|' << setw(5) << "Tuoi"
             << '|' << setw(8) << "Diem" << "|\n";
        cout << "+---------------+----------------------+-----+--------+\n";
        for (const auto& s : studentList) {
            cout << s << endl;
        }
        cout << "+---------------+----------------------+-----+--------+\n";
    }

    void sortStudents() {
        studentList.sort();
        output();
    }

    void maxScore() {
        if (studentList.empty()) {
            cout << "Danh sach sinh vien rong!\n";
            return;
        }
        double max = studentList.front().getScore();
        for (const auto& s : studentList)
            if (max < s.getScore())
                max = s.getScore();
        cout << "Sinh vien co diem cao nhat:\n";
        for (const auto& s : studentList)
            if (max == s.getScore())
                cout << s << endl;
    }

    void minScore() {
        if (studentList.empty()) {
            cout << "Danh sach sinh vien rong!\n";
            return;
        }
        double min = studentList.front().getScore();
        for (const auto& s : studentList)
            if (min > s.getScore())
                min = s.getScore();
        cout << "Sinh vien co diem thap nhat:\n";
        for (const auto& s : studentList)
            if (min == s.getScore())
                cout << s << endl;
    }

    bool studentExists(const string& name) {
        for (const auto& s : studentList)
            if (s.getName() == name)
                return true;
        return false;
    }

    void searchByName(const string& name) {
        if (studentExists(name)) {
            cout << "Thong tin sinh vien:\n";
            for (const auto& s : studentList)
                if (s.getName() == name)
                    cout << s << endl;
        } else {
            cout << "Khong tim thay sinh vien co ten: " << name << endl;
        }
    }

    void addStudent() {
        Student s;
        cin >> s;
        studentList.push_back(s);
    }

    void deleteStudent(const string& name) {
        if (studentExists(name)) {
            for (auto it = studentList.begin(); it != studentList.end();) {
                if (it->getName() == name)
                    it = studentList.erase(it);
                else
                    ++it;
            }
            cout << "Da xoa sinh vien co ten: " << name << endl;
        } else {
            cout << "Khong tim thay sinh vien co ten: " << name << endl;
        }
    }
};

class App {
private:
    StudentList mylist;

public:
    App() {}
    ~App() {}

    void showMenu() {
        cout << "MENU\n"
             << "1. Nhap danh sach sinh vien\n"
             << "2. Hien thi danh sach sinh vien\n"
             << "3. Tim sinh vien theo ten\n"
             << "4. Xoa sinh vien theo ten\n"
             << "5. Them sinh vien\n"
             << "6. Sap xep sinh vien theo diem\n"
             << "7. Tim sinh vien co diem cao nhat\n"
             << "8. Tim sinh vien co diem thap nhat\n"
             << "0. Thoat chuong trinh\n";
    }

    void menu() {
        int choice;
        showMenu(); 
        do {
            cout << "Nhap lua chon cua ban: ";
            cin >> choice;

            switch (choice) {
            case 0:
                cout << "Dang thoat chuong trinh..." << endl;
                break;
            case 1:
                mylist.input();
                break;
            case 2:
                mylist.output();
                break;
            case 3: {
                string name;
                cout << "Nhap ten sinh vien can tim: ";
                cin.ignore();
                getline(cin, name);
                mylist.searchByName(name);
                break;
            }
            case 4: {
                string name;
                cout << "Nhap ten sinh vien can xoa: ";
                cin.ignore();
                getline(cin, name);
                mylist.deleteStudent(name);
                break;
            }
            case 5:
                mylist.addStudent();
                break;
            case 6:
                mylist.sortStudents();
                break;
            case 7:
                mylist.maxScore();
                break;
            case 8:
                mylist.minScore();
                break;
            default:
                cout << "Lua chon khong hop le, vui long chon lai!" << endl;
                break;
            }
            if (choice != 0) showMenu();
            } 
        while (choice != 0);
    }
};

int main() {
    App app;
    app.menu();
    return 0;
}