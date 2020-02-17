// MZMTIN002

#include "stu_database.h"

using namespace std;
static vector<MZMTIN002::StudentRecord> records;

void MZMTIN002::prompt() {
    for (;;) {
        string ans;
        getline(cin, ans);
        fflush(stdin);
        if (ans == "q") {
            break;
        } else if (ans == "1") {
            puts("Please enter the student's name:");
            string name;
            getline (cin, name);

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
        } else if (ans == "2") {
            MZMTIN002::read_database();
        } else if (ans == "3") {
            MZMTIN002::save_database();
        } else if (ans == "4") {
            puts("Please enter the student's student number:");
            string stu_num;
            getline(cin, stu_num);
            MZMTIN002::display_data(stu_num);
        } else if (ans == "5") {
            puts("Please enter the student's student number:");
            string stu_num;
            getline(cin, stu_num);
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
    ofstream out("records.txt", ios::app);
    if (out.is_open()) {
        for (const auto& record : records) {
            out << record.name << " " << record.surname << " " << record.stu_num << " " << record.class_rec << endl;
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

void MZMTIN002::display_data(const string& stu_num) {
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

void MZMTIN002::grade_student(const string& stu_num) {
    puts("Inside grade student func");
    for (auto & record: records) {
        if (record.stu_num == stu_num) {
            stringstream ss(record.class_rec);
            string token;
            int total = 0;
            int count = 0;
            while (ss >> token) {
                total += stoi(token);
                count++;
            }
            cout << "grade for " << record.name << " is " << nearbyint((double) total/count) << endl;
            break;
        }
    }
}
