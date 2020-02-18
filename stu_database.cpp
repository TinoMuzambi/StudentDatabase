// MZMTIN002

#include "stu_database.h"

using namespace std;
static vector<MZMTIN002::StudentRecord> records;

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
    int count = 0;
    bool dupe = false;
    for (auto & record: records) {
        if (record.stu_num == stu_num) {
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
}

void MZMTIN002::display_data(const string& stu_num) {
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
