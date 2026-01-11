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

    else if(command == "list"){

        if(tasks.empty())
        {
            cout<<"No tasks found.\n";
        }

        if(argc == 2){
            for(auto &t : tasks){
                cout<<"Id : "<<t.getId()<<",Description : "<<t.getDescription()<<",status : "<<t.getStatus()<<"\n";
            }
        }

        else{
            string info = argv[2];
            bool found = false;

            for(auto &t:tasks){
                if(t.getStatus() == info){
                    cout << "[" << t.getId() << "] "
                     << t.getDescription()
                     << " (" << t.getStatus() << ")\n";

                    found = true;
                }
            }

            if(!found){
                cout<<"no such information exist"<<"\n";
            }

        }
        
    }

    else if(command == "mark-done"){
        if(argc<3){
            cout<<"id de bhai\n";
            return 0;
        }

        int id = stoi(argv[2]);
        bool found = false;

        for(auto &t:tasks){
            if(t.getId() == id)
            {
                t.markDone();
                found = true;
                break;
            }
        }
        
        if(!found){
            cout<<"Task not found\n";
            return 0;
        }

        saveTasks(tasks);
        cout<<"mark kr diye bhai ye id"<<id<<"\n";
    }

    else if(command == "mark-progress"){
        if(argc<3){
            cout<<"id to de bhai\n";
            return 0;
        }

        int id = stoi(argv[2]);
        bool found = false;

        for(auto &t : tasks){
            if(t.getId() == id)
            {
                t.markInProgress();
                found = true;
                break;
            }
        }

        if(!found){
            cout<<"Task not found\n";
            return 0;
        }

        saveTasks(tasks);
        cout<<"mark kr diye bhai ye id"<<id<<"\n";

    }

    else if(command == "delete"){
        if(argc<3){
            cout<<"id to de bhai\n";
            return 0;
        }

        int id = stoi(argv[2]);
        bool found = false;

        for(auto t = tasks.begin();t!=tasks.end();t++){
            if(t->getId() == id)
            {   
                tasks.erase(t);
                found = true;
                break;
            }
        }

        if(!found){
            cout<<"Task not found\n";
            return 0;
        }

        saveTasks(tasks);
        cout<<"delete kr diye bhai ye id"<<id<<"\n";
    }

    else if(command == "update"){
        if(argc<4){
            cout<<"pura information daal\n";
            return 0;
        }

        int id = stoi(argv[2]);
        string description = argv[3];
        bool found = true;

        for(auto &t:tasks){
            if(t.getId() == id)
            {   
                t.update(id,description, t.getStatus(),t.getCreate(),"");
                found = true;
                break;
            }
        }

        if(!found){
            cout<<"Task not found\n";
            return 0;
        }

        saveTasks(tasks);
        cout<<"update kr diye bhai ye id"<<id<<"\n";
    }

    else
    {
        cout<<"Unknown command\n";
    }

    return 0;
}

