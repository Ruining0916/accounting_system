#include "transaction.h"
#include <stdexcept>
Transaction::Transaction(){}
Transaction::Transaction(int t_id,
                        time_t time,
                        double amt,
                        double s_fee,
                        std::string t_type,
                        std::string c_type,
                        std::string buyer,
                        std::string seller
) {
    transaction_id = t_id;
    timestamp = time;
    amount = amt;
    service_fee_rate = s_fee;
    transaction_type = t_type;
    currency_type = c_type;
    buyer_wallet_address = buyer;
    seller_wallet_address = seller;
}


std::string Transaction::getTransactionType() {
    return transaction_type;
}

std::string Transaction::getCurrencyType() {
    return currency_type;
}
std::string Transaction::getBuyerWalletAddress() {
    return buyer_wallet_address;
}
std::string Transaction::getSellerWalletAddress() {
    return seller_wallet_address;
}
float Transaction::getAmount() {
    return amount;
}

