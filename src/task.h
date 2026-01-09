#ifndef TASK_H
#define TASK_H

#include<iostream>
using namespace std;

class Task
{
    int id;
    string description;
    string status;
    string createdAt;
    string updatedAt;

    string currentTime ();

public:

    Task();
    Task(int id,string description);    

    void update(int id,string description,string status,string createdAt,string updatedAt);

    int getId();

    string getDescription();

    string getStatus();

    string getCreate();

    string getUpdate();

    void markDone();
    void markInProgress();

};

#endif