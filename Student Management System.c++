#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Student {
public:
    int id;
    string name;
    double gpa;

    Student(int i, string n, double g)
        : id(i), name(n), gpa(g) {}
};

class StudentSystem {
private:
    vector<Student> students;

public:
    void addStudent() {
        int id;
        string name;
        double gpa;

        cout << "ID: "; cin >> id;
        cout << "Name: "; cin >> name;
        cout << "GPA: "; cin >> gpa;

        students.push_back(Student(id, name, gpa));
        cout << "Student added.\n";
    }

    void showAll() {
        for (auto &s : students) {
            cout << s.id << " | " << s.name
                 << " | GPA: " << s.gpa << endl;
        }
    }

    void search() {
        int id;
        cout << "Enter ID: ";
        cin >> id;

        for (auto &s : students) {
            if (s.id == id) {
                cout << "Found: " << s.name
                     << " GPA: " << s.gpa << endl;
                return;
            }
        }
        cout << "Not found.\n";
    }

    void save() {
        ofstream out("students.txt");
        for (auto &s : students)
            out << s.id << " "
                << s.name << " "
                << s.gpa << endl;
    }

    void load() {
        ifstream in("students.txt");
        int id;
        string name;
        double gpa;

        while (in >> id >> name >> gpa)
            students.push_back(Student(id, name, gpa));
    }
};

int main() {
    StudentSystem sys;
    sys.load();

    int choice;
    do {
        cout << "\n1.Add\n2.Show\n3.Search\n0.Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) sys.addStudent();
        else if (choice == 2) sys.showAll();
        else if (choice == 3) sys.search();

    } while (choice != 0);

    sys.save();
}
