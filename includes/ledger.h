#include <iostream>
#include <vector>
#include <cstddef>
#include <stdexcept>
#include <exception>
#include "transaction.h"
#ifndef LEDGER_HPP
#define LEDGER_HPP
class Ledger {
    private:
    std::vector<Transaction> btcTransaction;
    std::vector<Transaction> ethTransaction;

    public:
       Ledger();
       void addToLedger(int t_id,
                    time_t time,
                    float amt,
                    float s_fee,
                    std::string t_type,
                    std::string c_type,
                    std::string buyer,
                    std::string seller);
        double BTCSentTotal(std::string seller);
        double ETHSentTotal(std::string seller);
        double BTCReceiveTotal(std::string buyer);
        double ETHReceiveTotal(std::string buyer);

        
 };
#endif