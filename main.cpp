#include <cstdlib>
#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>

using namespace std;

char HOST[] = "localhost";
char USER[] = "root";
char PASS[] = "";
char DB[] = "dana_osis";

MYSQL *obj;
MYSQL *conection;
MYSQL_RES *result;
MYSQL_DATA data;
MYSQL_ROW row;

int main(int argc, char *argv[])
{
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
