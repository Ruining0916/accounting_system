#include "sql_connector.h"

MYSQL *get_connector(){
           MYSQL * conn = mysql_init(NULL);  // represents connection to database
            mysql_real_connect(conn,
                                    "localhost",// synonymous with 127.0.0.1
                                    "ruining0916",     // connect as user="root".  Uh, bad security here..
                                    "password",         // my root password is blank.  REALLY bad security :)
                                    "ACCOUNT_DATA",    // connect to the 'mysql' _database_ within MySQL itself.
                                    0, 0, 0 ) ;
            // Check if connection succeeded.
            if( !conn ) {
                printf( "Couldn't connect to MySQL database server!\n" ) ;
                printf( "Error: %s\n", mysql_error(conn) ) ;
                return NULL ;
            } else  {
                puts( "Connect success");
                return conn;
            }
}

MYSQL_RES* get_sql_result(MYSQL* conn) {
    return mysql_store_result(conn);
}
my_ulonglong get_row_num(MYSQL_RES* resultset) {
    my_ulonglong numRows = mysql_num_rows(resultset) ;
    return numRows;
}
int get_columns_num(MYSQL_RES* resultset) {
    int numFields = mysql_num_fields( resultset ) ;
   
    return numFields;
}
void printTable( MYSQL_RES* resultset) {
    // my_ulonglong numRows = get_row_num(resultset);
    int numFields = get_columns_num(resultset);
    //print fields
    MYSQL_FIELD * fields = mysql_fetch_fields( resultset ) ;
    for( int i = 0 ; i < numFields ; i++ )
    {
        printf( "%5s", fields[i].name ) ;
    }
    printf("\n");
    //print rows
    MYSQL_ROW row;
    while( (row = mysql_fetch_row( resultset )) )
    {
        // row is 2d array of char
        // underlying type is char **
        for ( int i = 0; i < numFields ; i++ )
        printf( "%5s", row[ i ] ) ;
        
        puts( "" ) ;    // next row
    }
    
}
void executeQuery(MYSQL* conn, string query) {
    const char* str = query.c_str();
    if( mysql_query(conn, str) ) {
        printf("Whoops!  The query failed.  Error:  %s\n", mysql_error( conn) );
    }
}

// int main(int argc, char* argv[]) {

//     MYSQL* conn = get_connector();
//     MYSQL_RES * resultset;
//     string query = "select * from user";
//     executeQuery(conn, query);
//     resultset = get_sql_result(conn);
//     my_ulonglong numRows = get_row_num(resultset);
//     int numFields = get_columns_num(resultset);
//     printf( "There are %llu ROWS (records) of data\n", numRows ) ;
//     printf( "There are %d FIELDS (columns) of data\n", numFields) ;
//     printTable(resultset);

//     mysql_free_result( resultset );  // Now free the result
//     mysql_close( conn ) ;  // And close down.
//     return 0;
// }
