/*Build a simple console-based to-do list
manager that allows users to add, view, and
delete tasks.
Task Input: Allow users to input tasks they want to add to the list.
Add Task: Implement a function to add tasks to the list.
View Tasks: Display the list of tasks with their status (completed or pending).
Mark Task as Completed: Allow users to mark tasks as completed.
Remove Task: Provide an option to remove tasks from the list.
*/


#include <iostream>
#include <vector>

using namespace std;

struct Node {
  string task;
  bool completed;  // Add a boolean field for task completion status
  Node* next;
};

class ToDoList {
private:
  Node* head;

public:
  ToDoList() {
    head = nullptr;
  }

  void addTask(const string& task) {
    Node* newNode = new Node();
    newNode->task = task;
    newNode->completed = false;  // Initialize as not completed
    newNode->next = nullptr;

    if (head == nullptr) {
      head = newNode;
    } else {
      Node* current = head;
      while (current->next != nullptr) {
        current = current->next;
      }
      current->next = newNode;
    }
  }

  void markTaskAsCompleted(int index) {
    Node* current = head;
    for (int i = 0; i < index; i++) {
      current = current->next;
    }

    current->completed = true;  // Mark the task as completed
  }

  void deleteTask(int index) {
    if (head == nullptr) {
      return;
    }

    if (index == 0) {
      Node* temp = head;
      head = head->next;
      delete temp;
      return;
    }

    Node* current = head;
    Node* previous = nullptr;
    for (int i = 0; i < index; i++) {
      previous = current;
      current = current->next;
    }

    previous->next = current->next;
    delete current;
  }

  vector<string> getTasks() {
    vector<string> tasks;

    Node* current = head;
    while (current != nullptr) {
      string status = current->completed ? "[Completed]" : "[Pending]";
      tasks.push_back(status + " " + current->task);
      current = current->next;
    }

    return tasks;
  }
};

int main() {
  ToDoList toDoList;
  cout << "----------------------------------------" << endl;
  cout << " Welcome to the to-do list app! " << endl;
  cout << "----------------------------------------" << endl;

  int option;
  string task;

  do {
    cout << "\n What would you like to do? \n" << endl;
    cout << "1. Add a task" << endl;
    cout << "2. Mark a task as completed" << endl;  // New option to mark as completed
    cout << "3. Delete a task" << endl;
    cout << "4. View all tasks" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> option;
    vector<string> tasks= toDoList.getTasks();
    switch (option) {
      case 1:
        cout << "Enter a task to add: ";
        cin.ignore();
        getline(cin, task);
        toDoList.addTask(task);
        break;

      case 2:
        cout << "Choose the task to mark as completed: "<<endl;
        int index;
        
        for (int i = 0; i < tasks.size(); i++) {
          cout << i + 1 << ". " << tasks[i] << endl;
        }
        cin >> index;
        toDoList.markTaskAsCompleted(index - 1);
        break;

      case 3:
        cout << "Choose the task to delete: "<<endl;
        int deleteIndex;
        for (int i = 0; i < tasks.size(); i++) {
          cout << i + 1 << ". " << tasks[i] << endl;
        }
        cin >> deleteIndex;
        toDoList.deleteTask(deleteIndex - 1);
        break;

      case 4:
        cout << "All tasks:" << endl;
        for (int i = 0; i < tasks.size(); i++) {
          cout << i + 1 << ". " << tasks[i] << endl;
        }
        break;
    }
  } while (option != 5);

  return 0;
}