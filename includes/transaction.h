#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP
#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <exception>
#include "sql_connector.h"
class Transaction {
private:
    int transaction_id;
    time_t timestamp;
    double amount;
    double service_fee_rate;
    std::string transaction_type;
    std::string currency_type;
    std::string buyer_wallet_address;
    std::string seller_wallet_address;

public:
    Transaction();
    Transaction(int transaction_id,
    time_t timestamp,
    double amount,
    double service_fee_rate,
    std::string transaction_type,
    std::string currency_type,
    std::string buyer_wallet_address,
    std::string seller_wallet_address
   );
    std::string getTransactionType();
    std::string getCurrencyType();
    std::string getBuyerWalletAddress();
    std::string getSellerWalletAddress();
    float getAmount();
    friend class Account;
   


};

#endif