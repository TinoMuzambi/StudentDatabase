// MZMTIN002

#include "stu_database.h"

char* MZMTIN002::prompt() {
    for (;;) {
        char ans[2];
        char * ans_in = fgets(ans, 2, stdin);
        fflush(stdin);
        if (strncmp(ans_in, "q", 2) == 0) {
            break;
        } else if (strncmp(ans_in, "1", 2) == 0) {
            puts("call to add student.");
        } else if (strncmp(ans_in, "2", 2) == 0) {
            puts("call to read database.");
        } else if (strncmp(ans_in, "3", 2) == 0) {
            puts("call to display given data.");
        } else if (strncmp(ans_in, "4", 2) == 0) {
            puts("call to grade student.");
        } else {
            puts("Invalid option!");
        }
        puts("Database Interface");
        puts("Available options:");
        puts("1. add student");
        puts("2. read database");
        puts("3. display given student data");
        puts("4. grade student");
        puts("q. quit");
        puts("Enter a number (or q to quit) and press return...\n");
    }
}

int main() {
    puts("Database Interface");
    puts("Available options:");
    puts("1. add student");
    puts("2. read database");
    puts("3. display given student data");
    puts("4. grade student");
    puts("q. quit");
    puts("Enter a number (or q to quit) and press return...\n");
    prompt();
}
