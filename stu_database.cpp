// MZMTIN002

#include "stu_database.h"

static std::vector<MZMTIN002::StudentRecord> records;

void MZMTIN002::prompt() {
    for (;;) {
        char buf[2];
        char * ans_in = fgets(buf, 2, stdin);
        fflush(stdin);
        if (strncmp(ans_in, "q", 2) == 0) {
            break;
        } else if (strncmp(ans_in, "1", 2) == 0) {
            puts("Please enter the student's name:\n");
            char buf2[15];
            char * name = fgets(buf2, 15, stdin);
            fflush(stdin);
            puts("Please enter the student's surname:\n");
            char buf3[20];
            char * surname = fgets(buf3, 20, stdin);
            fflush(stdin);
            puts("Please enter the student's student number:\n");
            char buf4[10];
            char * stu_num = fgets(buf4, 10, stdin);
            fflush(stdin);
            puts("Please enter the student's class record:\n");
            char buf5[30];
            char * class_record = fgets(buf5, 30, stdin);
            fflush(stdin);
            MZMTIN002::add_student(name, surname, stu_num, class_record);
        } else if (strncmp(ans_in, "2", 2) == 0) {
            MZMTIN002::read_database();
        } else if (strncmp(ans_in, "3", 2) == 0) {
            MZMTIN002::save_database();
        } else if (strncmp(ans_in, "4", 2) == 0) {
            puts("Please enter the student's student number:\n");
            char buf4[10];
            char * stu_num = fgets(buf4, 10, stdin);
            fflush(stdin);
            MZMTIN002::display_data(stu_num);
        } else if (strncmp(ans_in, "5", 2) == 0) {
            puts("Please enter the student's student number:\n");
            char buf4[10];
            char * stu_num = fgets(buf4, 10, stdin);
            fflush(stdin);
            MZMTIN002::grade_student(stu_num);
        } else {
            puts("Invalid option!");
        }

        puts("Database Interface");
        puts("Available options:");
        puts("1. add student");
        puts("2. read database");
        puts("3. save database");
        puts("4. display given student data");
        puts("5. grade student");
        puts("q. quit");
        puts("Enter a number (or q to quit) and press return...\n");
    }
}

void MZMTIN002::read_database() {
    puts("Inside read db func.");
}

void MZMTIN002::save_database() {
    puts("Inside save db func.");
}

void MZMTIN002::add_student(std::string name, std::string surname, std::string stu_num, std::string class_rec) {
    puts("Inside add stu func");
}

void MZMTIN002::display_data(std::string stu_num) {
    puts("Inside display data func");
}

void MZMTIN002::grade_student(std::string stu_num) {
    puts("Inside grade student func");
}
