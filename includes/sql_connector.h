#include <stdio.h> 
#include"/usr/local/mysql/include/mysql.h"
#include <string>
#include <cstring>
#include <assert.h>
using namespace std;
MYSQL* get_connector(); 
MYSQL_RES* get_sql_result(MYSQL* conn);
my_ulonglong get_row_num(MYSQL_RES* resultset);
int get_columns_num(MYSQL_RES* resultset);
void printTable( MYSQL_RES* resultset);
void executeQuery(MYSQL* conn, string query);