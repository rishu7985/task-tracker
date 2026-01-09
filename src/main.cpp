#include <iostream>
#include <vector>
#include "task.h"
#include "storage.h"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 2) {
        cout << "Usage: task-cli <command> [arguments]\n";
        return 0;
    }

    string command = argv[1];

    vector<Task>tasks = loadTasks();

    if(command == "add"){
        if(argc<3){
            cout<<"Error:task description missing\n";
            return 0;
        }

        string description = argv[2];

        int newId = 1;
        for (auto &t : tasks) {
            newId = max(newId, t.getId() + 1);
        }

        Task newTask(newId,description);
        tasks.push_back(newTask);

        saveTasks(tasks);

        cout << "Task added successfully (ID: " << newId << ")\n";
    }
    else {
        cout << "Unknown command\n";
    }

    return 0;
}

