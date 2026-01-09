#ifndef STORAGE_H
#define STORAGE_H

#include<iostream>
#include<vector>
#include"task.h"
using namespace std;

vector<Task>loadTasks();
void saveTasks(const vector<Task>&tasks);

#endif
