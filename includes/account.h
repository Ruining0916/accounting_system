#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <vector>
#include <exception>
#include <fstream>
#include <sstream>
#include <sqlite3.h>
#include "transaction.h"
class Account {
    private:
    struct UserInfo {
        std::string name;
        std::string gender;
        std::string phonenumber;
        std::string email;
    }; UserInfo userInfoInstance;

    std::string account_name;
    int account_id;
    float btc_balance;
    float eth_balance;
    
    // std::vector<Transaction> transactions;
public:
    //account constructer
    static std::vector<Account> data;
    Account();
    Account(std::string acc_name, int acc_id, float btc, float eth);
    int getAccountID();
    std::string getAccountName();
    float getBtcBalance();
    float getEthBalance();
    void setAccountID(int acc_id);
    void setAccountName(std::string acc_name);
    void setBtcBalance(float btc);
    void setEthbalance(float eth);
    void transfer(Transaction& transaction);
    static void writeToCsv(const std::string& filename, std::vector<Account>& data);
    std::vector<std::vector<std::string>> readCsvFile(const std::string& filename);
    void writeVectorsToDatabase(std::vector<std::vector<std::string>> vectors);
    //static std::vector<Account>& getInstances(); 
    
};
#endif