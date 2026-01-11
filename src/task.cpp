#include "task.h"
#include <ctime>

Task::Task() {
    id = 0;
    description = "";
    status = "todo";
    createdAt = currentTime();
    updatedAt = currentTime();
}


Task::Task(int id, string description) {
    this->id = id;
    this->description = description;
    this->status = "todo";
    this->createdAt = currentTime();
    this->updatedAt = currentTime();
}

string Task::currentTime() {
    time_t now = time(0);
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buf);
}

void Task::update(int id,string description,string status,string createdAt,string updatedAt)    {
    this->id = id;
    this->description = description;
    this->status = status;
    this->createdAt = createdAt;
    if (updatedAt == "") {
    this->updatedAt = currentTime();
    } else {
        this->updatedAt = updatedAt;
    }
}

int Task::getId()
{
    return id;
}

string Task::getDescription()
{
    return description;
}

string Task::getStatus()
{
    return status;
}

string Task::getCreate()
{
    return createdAt;
}

string Task::getUpdate()
{
    return updatedAt;;
}

void Task::markDone() {
    status = "done";
    updatedAt = currentTime();
}

void Task::markInProgress() {
    status = "in-progress";
    updatedAt = currentTime();
}


