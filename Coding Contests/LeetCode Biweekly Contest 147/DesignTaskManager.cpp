#include<bits/stdc++.h>
using namespace std;

class TaskManager {
private:
    unordered_map<int, pair<int, int>> taskMap;
    set<tuple<int, int, int>> taskSet;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto& task: tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];
            add(userId, taskId, priority);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {userId, priority};
        taskSet.emplace(priority, taskId, userId);
    }
    
    void edit(int taskId, int newPriority) {
        int userId = taskMap[taskId].first;
        int oldPriority = taskMap[taskId].second;
        taskSet.erase({oldPriority, taskId, userId});
        taskMap[taskId].second = newPriority;
        taskSet.emplace(newPriority, taskId, userId);
    }
    
    void rmv(int taskId) {
        int userId = taskMap[taskId].first;
        int priority = taskMap[taskId].second;
        taskSet.erase({priority, taskId, userId});
        taskMap.erase(taskId);
    }
    
    int execTop() {
        if (taskSet.empty()) return -1;

    auto it = taskSet.rbegin();
    int priority = std::get<0>(*it);
    int taskId = std::get<1>(*it);
    int userId = std::get<2>(*it);
    rmv(taskId);
    return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */