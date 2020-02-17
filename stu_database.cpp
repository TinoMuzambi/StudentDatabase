// MZMTIN002

#include "stu_database.h"

using namespace std;
static vector<MZMTIN002::StudentRecord> records;

void MZMTIN002::prompt() {
    for (;;) {
        char buf[2];
        char * ans_in = fgets(buf, 2, stdin);
        fflush(stdin);
        if (strncmp(ans_in, "q", 2) == 0) {
            break;
        } else if (strncmp(ans_in, "1", 2) == 0) {
            puts("Please enter the student's name:");
            string name;
            getline (cin, name);
            fflush(stdin);
            puts("Please enter the student's surname:");
            string surname;
            getline(cin, surname);
            puts("Please enter the student's student number:");
            string stu_num;
            getline(cin, stu_num);
            puts("Please enter the student's class record:");
            string class_rec;
            getline(cin, class_rec);
            MZMTIN002::add_student(name, surname, stu_num, class_rec);
        } else if (strncmp(ans_in, "2", 2) == 0) {
            MZMTIN002::read_database();
        } else if (strncmp(ans_in, "3", 2) == 0) {
            MZMTIN002::save_database();
        } else if (strncmp(ans_in, "4", 2) == 0) {
            puts("Please enter the student's student number:");
            string stu_num;
            getline(cin, stu_num);
            MZMTIN002::display_data(stu_num);
        } else if (strncmp(ans_in, "5", 2) == 0) {
            puts("Please enter the student's student number:");
            string stu_num;
            getline(cin, stu_num);
            MZMTIN002::grade_student(stu_num);
        } else {
            puts("Invalid option!");
        }

//        for (auto & record : records) {
//            puts(record.name.c_str());
//            puts(record.surname.c_str());
//            puts(record.stu_num.c_str());
//            puts(record.class_rec.c_str());
//        }
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
    string filename = "records.txt";
    ifstream in(filename.c_str());

    if(!in) {
        puts("Couldn't open file");
        exit(1);
    }

    string line;
    while (getline(in, line)) {
        int pos = line.find(' ');
        string name = line.substr(0, pos);
        line = line.substr(pos + 1);
        pos = line.find(' ');
        string surname = line.substr(0, pos );
        line = line.substr(pos + 1);
        pos = line.find(' ');
        string stu_num = line.substr(0, pos);
        line = line.substr(pos + 1);
        string class_rec = line;
        MZMTIN002::add_student(name, surname, stu_num, class_rec);
    }
    in.close();
}

void MZMTIN002::save_database() {
    puts("Inside save db func.");
    ofstream out("records.txt", ios::app);
    if (out.is_open()) {
        for (auto record : records) {
            out << "\r" << record.name << " " << record.surname << " " << record.stu_num << " " << record.class_rec;
        }
    } else {
        puts("Unable to open file.");
    }
    out.close();
}

void MZMTIN002::add_student(string name, string surname, string stu_num, string class_rec) {
    MZMTIN002::StudentRecord sr = {name, surname, stu_num, class_rec};
    records.insert(records.begin(), sr);
}

void MZMTIN002::display_data(string stu_num) {
    puts("Inside display data func");
    for (auto & record: records) {
        if (record.stu_num == stu_num) {
            puts(record.name.c_str());
            puts(record.surname.c_str());
            puts(record.stu_num.c_str());
            puts(record.class_rec.c_str());
            break;
        }
    }
}

void MZMTIN002::grade_student(string stu_num) {
    puts("Inside grade student func");
}
