// MZMTIN002

#ifndef ASSIGNMENT_1_STU_DATABASE_H
#define ASSIGNMENT_1_STU_DATABASE_H
#include "cstdio"
#include "string"
#include <cstring>
#include <vector>

namespace MZMTIN002 {
    char * prompt();
    void add_student(std::string name, std::string surname, std::string stu_num, std::string class_rec);
    void read_database();
    void save_database();
    void display_data(std::string stu_num);
    void grade_student(std::string stu_num);
    struct StudentRecord {
        std::string name;
        std::string surname;
        std::string stu_num;
        std::string class_rec;
    };
    std::vector<StudentRecord> records;
};


#endif //ASSIGNMENT_1_STU_DATABASE_H
