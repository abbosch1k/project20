#include <iostream>
#include <queue>
using namespace std;

class Task {
public:
    string name;
    int priority;

    Task(string n, int p) : name(n), priority(p) {}

    bool operator<(const Task &other) const {
        return priority < other.priority;
    }
};

int main() {
    priority_queue<Task> tasks;
    int choice;

    do {
        cout << "\n1.Add Task\n2.Execute Task\n0.Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int priority;
            cout << "Task name: ";
            cin >> name;
            cout << "Priority (higher number = higher priority): ";
            cin >> priority;
            tasks.push(Task(name, priority));
        }
        else if (choice == 2) {
            if (tasks.empty()) {
                cout << "No tasks.\n";
            } else {
                Task t = tasks.top();
                tasks.pop();
                cout << "Executing: " << t.name << endl;
            }
        }

    } while (choice != 0);
}
