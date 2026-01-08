#include<iostream>
#include "storage.h"
#include <fstream>
#include <sstream>

using namespace std;

vector<Task> loadTasks() {
    vector<Task> tasks;
    ifstream file("data/tasks.json");

    string line;
    while (getline(file, line)) {
        if(line.find("\"id\"") != string::npos){
            Task t;

            int id = stoi(line.substr(line.find(":")+1));

            getline(file,line);

            string description = line.substr(line.find(":")+3);
            description.pop_back();
            description.pop_back();

            getline(file,line);
            string status = line.substr(line.find(":")+3);
            status.pop_back();
            status.pop_back();

            getline(file,line);
            string createdAt = line.substr(line.find(":")+3);
            createdAt.pop_back();
            createdAt.pop_back();

            getline(file,line);
            string updatedAt = line.substr(line.find(":")+3);
            updatedAt.pop_back();
            
            t.update(id,description,status,createdAt,updatedAt);

            tasks.push_back(t);
        }
    }
    file.close();
    return tasks;
}

void saveTasks(const vector<Task>& tasks) {
    ofstream file("data/tasks.json");
    file << "[\n";

    for (int i = 0; i < tasks.size(); i++) {
        Task t = tasks[i];
        file << "  {\n";
        file << "    \"id\": " << t.getId() << ",\n";
        file << "    \"description\": \"" << t.getDescription() << "\",\n";
        file << "    \"status\": \"" << t.getStatus()<< "\"\n";
        file << "    \"createdAt\": \"" << t.getCreate() << "\",\n";
        file << "    \"updatedAt\": \"" << t.getUpdate() << "\",\n";
        file << "  }";

        if (i != tasks.size() - 1) file << ",";
        file << "\n";
    }  

    file << "]";
    file.close();
}
