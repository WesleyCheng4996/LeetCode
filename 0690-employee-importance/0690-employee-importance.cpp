/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/


class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int id_to_idx[2001], ret = 0;
        for(int i = 0; i < employees.size(); ++i) {
            id_to_idx[employees[i]->id] = i;
        }
        
        return recur(employees, id, id_to_idx);
    }
    int recur(vector<Employee*> employees, int id, int idtoidx[2001]) {
        if (employees[idtoidx[id]]->subordinates.empty()) {
            return employees[idtoidx[id]]->importance;
        }
        int ret = employees[idtoidx[id]]->importance;
        for(int i = 0, end = employees[idtoidx[id]]->subordinates.size(); i < end; ++i) {
            ret += recur(employees, employees[idtoidx[id]]->subordinates[i], idtoidx);
        }
        return ret;
    }
};