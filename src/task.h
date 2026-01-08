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

public:

    void update(int id,string description,string status,string createdAt,string updatedAt)
    {
        this->id = id;
        this->description = description;
        this->status = status;
        this->createdAt = createdAt;
        this->updatedAt = updatedAt;
    }

    int getId()
    {
        return id;
    }

    string getDescription()
    {
        return description;
    }

    string getStatus()
    {
        return status;
    }

    string getCreate()
    {
        return createdAt;
    }

    string getUpdate()
    {
        return updatedAt;;
    }
};

#endif