#include "ledger.h"
Ledger::Ledger(){}
void Ledger::addToLedger(int t_id,
                    time_t time,
                    float amt,
                    float s_fee,
                    std::string t_type,
                    std::string c_type,
                    std::string buyer,
                    std::string seller) {
    Transaction transaction(t_id, time, amt, s_fee, t_type, c_type, buyer, seller);
    try {
        if (c_type == "BTC") {
            btcTransaction.push_back(transaction);

        } else if(c_type == "ETH") {
            ethTransaction.push_back(transaction);
        } else {
            throw "invalid currency type";
        }
    } catch (const char* msg) {
        std::cout <<msg <<std::endl;
        std::cout<<"avaliable currency type: BTC, ETH" <<std::endl;
    }
    
}

double Ledger::BTCSentTotal(std::string seller) {
    double total = 0;
    for(auto transaction: btcTransaction) {
        if(transaction.getSellerWalletAddress() == seller) {
            total += transaction.getAmount();
        }
    }
    return total;
}

double Ledger::ETHSentTotal(std::string seller) {
    double total = 0;
    for(auto transaction: ethTransaction) {
        if(transaction.getSellerWalletAddress() == seller) {
            total += transaction.getAmount();
        }
    }
    return total;
}

double Ledger::BTCReceiveTotal(std::string buyer) {
    double total = 0;
    for(auto transaction: btcTransaction) {
        if(transaction.getBuyerWalletAddress() == buyer) {
            total += transaction.getAmount();
        }
    }
    return total;
}

double Ledger::ETHReceiveTotal(std::string buyer) {
    double total = 0;
    for(auto transaction: ethTransaction) {
        if(transaction.getBuyerWalletAddress() == buyer) {
            total += transaction.getAmount();
        }
    }
    return total;
}
