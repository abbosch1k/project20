#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    vector<string> tasks;
    ifstream in("todo.txt");
    string task;

    while (getline(in, task))
        tasks.push_back(task);
    in.close();

    int choice;
    do {
        cout << "\n1.Add Task\n2.Show Tasks\n3.Delete Task\n0.Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Task: ";
            getline(cin, task);
            tasks.push_back(task);
        }
        else if (choice == 2) {
            for (int i = 0; i < tasks.size(); i++)
                cout << i << ". " << tasks[i] << endl;
        }
        else if (choice == 3) {
            int index;
            cout << "Index: ";
            cin >> index;
            if (index >= 0 && index < tasks.size())
                tasks.erase(tasks.begin() + index);
        }

    } while (choice != 0);

    ofstream out("todo.txt");
    for (auto &t : tasks)
        out << t << endl;
}
