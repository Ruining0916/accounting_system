#include "account.h"
std::vector<Account> Account::data;
Account::Account() {}
Account::Account(std::string acc_name, int acc_id, float btc, float eth) {
    account_name = acc_name;
    account_id = acc_id;
    btc_balance = btc;
    eth_balance = eth;
    data.push_back(*this);
}
int Account::getAccountID(){
    return account_id;
}
std::string Account::getAccountName(){
    return account_name;
}
float Account::getBtcBalance() {
    return btc_balance;
}

float Account::getEthBalance() {
    return eth_balance;
}

void Account::setBtcBalance(float btc) {
    btc_balance = btc;
}

void Account::setEthbalance(float eth) {
    eth_balance = eth;
}

void Account::setAccountID(int acc_id){
    account_id = acc_id;
}
void Account:: setAccountName(std::string acc_name) {
    account_name = acc_name;
}
void Account::transfer(Transaction& transaction) {
    try {
        double total_amount = transaction.amount * (1 + transaction.service_fee_rate);
        if (transaction.transaction_type == "IN") {
            if (transaction.currency_type == "BTC") btc_balance += total_amount;
            else if(transaction.currency_type == "ETH") eth_balance += total_amount;
            else throw "invalid currency type";
        } else if (transaction.transaction_type == "OUT") {
            if (transaction.currency_type == "BTC") btc_balance -= total_amount;
            else if(transaction.currency_type == "ETH") eth_balance -= total_amount;
            else throw "invalid currency type";
        } else {
            throw "invalid transaction type";
        }
    }
    catch (const char* msg) {
        std::cout<< msg <<std::endl;
        std::cout << "An error occurred: please check your currency type and transaction type\navaliable currency type : BTC  ETH \navaliable transaction type : IN  OUT\n" <<std::endl;
    }

    //update database
    // int usr_id = getAccountID();
    // std::string acc_name = getAccountName();
    // float btc_balance = getBtcBalance();
    // float eth_balance = getEthBalance();
    // string query ="INSERT INTO user (usr_id, account_name, BTC_balance, ETH_balance ) VALUES (1, 'John', 'Doe', 'johndoe@example.com');";
    // MYSQL_RES * resultset= get_sql_result(conn);
    
}
void Account::writeToCsv(const std::string& filename, std::vector<Account>& data) {
     std::ofstream file(filename, std::ios::app); // open file in append mode
    if (file.is_open()) {
        // write header row
        file << "account Name,account ID,BTC,ETH\n";

        // iterate over vector and write data
        for (auto& account : data) {
            file << account.getAccountName() << ","
                 << account.getAccountID() << ","
                 << account.getBtcBalance() << ","
                 << account.getEthBalance() << "\n";
        }

        file.close(); // close file when done
    } else {
        std::cerr << "Error: could not open file " << filename << " for writing.\n";
    }
 }

std::vector<std::vector<std::string>> Account::readCsvFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<std::string>> data;

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::string field;
        std::stringstream ss(line);

        while (std::getline(ss, field, ',')) {
            row.push_back(field);
        }

        data.push_back(row);
    }

    return data;
}


// static std::vector<Account>& getInstances() {
//     return data;
// }

void Account::writeVectorsToDatabase(std::vector<std::vector<std::string>> vectors)
{
    // Connect to MySQL database
    MYSQL* conn = mysql_init(nullptr);
    mysql_real_connect(conn,"localhost",// synonymous with 127.0.0.1
                                    "ruining0916",     // connect as user="root".  Uh, bad security here..
                                    "password",         // my root password is blank.  REALLY bad security :)
                                    "ACCOUNT_DATA",    // connect to the 'mysql' _database_ within MySQL itself.
                                    0, 0, 0);
    // Create table in database
    std::string createTableSql = "CREATE TABLE mytable (";
    for (size_t i = 0; i < vectors[0].size(); i++)
    {
        createTableSql += "column" + std::to_string(i) + " VARCHAR(255), ";
    }
    createTableSql = createTableSql.substr(0, createTableSql.length() - 2) + ")";
    mysql_query(conn, createTableSql.c_str());

    // Insert vectors into database
    for (auto& vector : vectors)
    {
        std::string insertSql = "INSERT INTO mytable VALUES (";
        for (auto& field : vector)
        {
            insertSql += "'" + field + "', ";
        }
        insertSql = insertSql.substr(0, insertSql.length() - 2) + ")";
        mysql_query(conn, insertSql.c_str());
    }

    // Close MySQL connection
    mysql_close(conn);
}