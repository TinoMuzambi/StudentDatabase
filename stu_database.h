// MZMTIN002

#ifndef ASSIGNMENT_1_STU_DATABASE_H
#define ASSIGNMENT_1_STU_DATABASE_H
#include "cstdio"
#include "cstdlib"
#include "string"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;
namespace MZMTIN002 {
    void add_student(string name, string surname, const string& stu_num, string class_rec);
    void read_database();
    void save_database();
    void display_data(const string& stu_num);
    void grade_student(const string& stu_num);
    struct StudentRecord {
        string name;
        string surname;
        string stu_num;
        string class_rec;
    };
}

#endif //ASSIGNMENT_1_STU_DATABASE_H
