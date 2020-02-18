// MZMTIN002

#include "stu_database.h"

using namespace std;
static vector<MZMTIN002::StudentRecord> records;

void MZMTIN002::read_database() {
    puts("Opening file...");
    string filename = "records.txt";
    ifstream in(filename.c_str());

    if(!in) {
        puts("Couldn't open file");
        exit(1);
    }

    puts("Reading file...");
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
    puts("Done.");
}

void MZMTIN002::save_database() {
    puts("Opening file...");
    ofstream out("records.txt");
    if (out.is_open()) {
        puts("Writing file...");
        for (const StudentRecord&  record : records) {
            out << record.name.c_str() << " " << record.surname.c_str() << " " << record.stu_num.c_str() << " " << record.class_rec.c_str() << endl;
        }
    } else {
        puts("Unable to open file.");
    }
    out.close();
    puts("Done.");
}

void MZMTIN002::add_student(string name, string surname, const string& stu_num, string class_rec) {
    int count = 0;
    bool dupe = false;
    for (auto & record: records) {
        if (record.stu_num.c_str() == stu_num) {
            dupe = true;
            break;
        }
        count++;
    }
    MZMTIN002::StudentRecord sr = {name, surname, stu_num, class_rec};
    if (dupe) {
        records.at(count) = sr;
    }
    else {
        records.insert(records.begin(), sr);
    }
    cout << sr.stu_num << " added." << endl;
}

void MZMTIN002::display_data(const string& stu_num) {
    puts("Searching...");
    bool found = false;
    for (auto & record: records) {
        if (record.stu_num.c_str() == stu_num) {
            puts("Student found:");
            found = true;
            cout << "Name:           " << record.name.c_str() << endl; // printf string formatting didn't wanna work so this is what we've got.
            cout << "Surname:        " << record.surname.c_str() << endl;
            cout << "Student Number: " << record.stu_num.c_str() << endl;
            cout << "Class Record:   " << record.class_rec.c_str() << endl;

            break;
        }
    }
    if (!found) {
        cout << stu_num << " not found in the database." << endl;
    }
}

void MZMTIN002::grade_student(const string& stu_num) {
    puts("Searching...");
    bool found = false;
    for (auto & record: records) {
        if (record.stu_num.c_str() == stu_num) {
            puts("Student found:");
            found = true;
            stringstream ss(record.class_rec.c_str());
            string token;
            int total = 0;
            int count = 0;
            while (ss >> token) {
                total += stoi(token);
                count++;
            }
            cout << "Grade for " << record.stu_num.c_str() << " is " << nearbyint((double) total/count) << endl;
            break;
        }
    }
    if (!found) {
        cout << stu_num << " not found in the database." << endl;
    }
}
