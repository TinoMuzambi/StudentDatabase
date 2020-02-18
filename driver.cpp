// MZMTIN002

#include "driver.h"
using namespace std;
using namespace MZMTIN002;

int main() {
    puts("Database Interface");
    puts("Available options:");
    puts("1. add student");
    puts("2. read database");
    puts("3. save database");
    puts("4. display given student data");
    puts("5. grade student");
    puts("q. quit");
    puts("Enter a number (or q to quit) and press return...");
    for (;;) {
        string ans;
        getline(cin, ans);
        if (ans == "q") {
            break;
        } else if (ans == "1") {
            puts("\nPlease enter the student's name:");
            string name;
            getline (cin, name);

            puts("\nPlease enter the student's surname:");
            string surname;
            getline(cin, surname);

            puts("\nPlease enter the student's student number:");
            string stu_num;
            getline(cin, stu_num);

            puts("\nPlease enter the student's class record:");
            string class_rec;
            getline(cin, class_rec);

            add_student(name, surname, stu_num, class_rec);
        } else if (ans == "2") {
            read_database();
        } else if (ans == "3") {
            save_database();
        } else if (ans == "4") {
            puts("\nPlease enter the student's student number:");
            string stu_num;
            getline(cin, stu_num);
            display_data(stu_num);
        } else if (ans == "5") {
            puts("\nPlease enter the student's student number:");
            string stu_num;
            getline(cin, stu_num);
            grade_student(stu_num);
        } else {
            puts("Invalid option.");
        }

        puts("\nDatabase Interface");
        puts("Available options:");
        puts("1. add student");
        puts("2. read database");
        puts("3. save database");
        puts("4. display given student data");
        puts("5. grade student");
        puts("q. quit");
        puts("Enter a number (or q to quit) and press return...");
    }
}
