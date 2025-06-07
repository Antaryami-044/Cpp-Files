#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> tasks;
    vector<bool> status; 
    int choice;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Task\n";
        cout << "2. Show Tasks\n";
        cout << "3. Mark as Done\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        if (choice == 1) {
            string task;
            cout << "Enter a task: ";
            getline(cin, task);
            tasks.push_back(task);
            status.push_back(false);
            cout << "Task added!\n";

        } else if (choice == 2) {
            if (tasks.size() == 0) {
                cout << "No tasks yet.\n";
            } else {
                cout << "\nTo-Do List:\n";
                for (int i = 0; i < tasks.size(); i++) {
                    cout << i + 1 << ". " << tasks[i];
                    if (status[i] == true) {
                        cout << "  (Done) ✅";
                    } else {
                        cout << " ⏳ (Pending)";
                    }
                    cout << endl;
                }
            }

        } else if (choice == 3) {
            if (tasks.size() == 0) {
                cout << "No tasks to mark.\n";
            } else {
                int num;
                cout << "Enter task number to mark as done: ";
                cin >> num;
                if (num > 0 && num <= tasks.size()) {
                    status[num - 1] = true;
                    cout << "Marked as done!\n";
                } else {
                    cout << "Invalid task number.\n";
                }
            }

        } else if (choice == 4) {
            cout << "Thank you! Exiting...\n";
            break;

        } else {
            cout << "You choose incorrect Option. Try again.\n";
        }
    }

    return 0;
}
