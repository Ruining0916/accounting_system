#include <iostream>
#include "account.h"
#include "transaction.h"
#include "ledger.h"
#include <ctime>
int main() {
    std::cout<<"hello world"<<std::endl;
    Account myAccount("Christine", 1, 2.0, 3.0);//Name, userid, btc, eth
    time_t current_time = std::time(NULL);
    Transaction myTrans(
        1,
        current_time,
        90.0,
        0.1,
        "IN",
        "BTC",
        "Amy",
        "Lucy"
    );

    //transfer check
    // MYSQL* conn = get_connector();
    std::cout << "BTC balance:  "<<myAccount.getBtcBalance() << std::endl;
    myAccount.transfer(myTrans);
    std::cout << "BTC balance:  "<<myAccount.getBtcBalance() << std::endl;
    myAccount.writeToCsv("account_data.csv",  myAccount.data);
    auto data = myAccount.readCsvFile("account_data.csv");
    myAccount.writeVectorsToDatabase(data);
    // transaction.transfer(conn,4.0, "BTC", "OUT");
    // std::cout << "BTC balance:  "<<myAccount.getBtcBalance() << std::endl;

    // transaction.transfer(conn,5.0, "ETH", "IN");
    // std::cout << "ETH balance: " <<myAccount.getEthBalance() << std::endl;

    // transaction.transfer(conn5.0, "ETH", "OUT");
    // std::cout << "ETH balance: " <<myAccount.getEthBalance() << std::endl;

    // transaction.transfer(5.0, "ETH", "OwUT");
    // std::cout << "ETH balance: " <<myAccount.getEthBalance() << std::endl;

    // transaction.transfer(5.0, "ETwH", "OwUT");
    // std::cout << "ETH balance: " <<myAccount.getEthBalance() << std::endl;

    // Transaction transaction();
    
    // //Test ledger
    // Ledger* ledger = new Ledger();
    // time_t currentTime = time(NULL);
    // ledger ->addToLedger(0, currentTime, 1.0, 0.1, "IN", "BTC","Alice", "Tom");
    // ledger ->addToLedger(0, currentTime, 2.0, 0.1, "IN", "ETH","Tom", "Alice");
    // ledger ->addToLedger(0, currentTime, 3.0, 0.1, "OUT", "BTC","Hi", "Ho");
    // ledger -> addToLedger(0, currentTime, 4.0, 0.1, "OUT", "ETH","Ho", "HI");


    // // Print out the total BTC and ETH sent and received by each participant
    // std::cout << "Alice sent " << ledger ->BTCSentTotal("Alice") << " BTC and received " << ledger ->BTCReceiveTotal("Alice") << " BTC." << "current time " << ctime(&currentTime) <<std::endl ;
    // std::cout << "Alice sent " << ledger ->ETHSentTotal("Alice") << " ETH and received " << ledger -> ETHReceiveTotal("Alice") << " ETH." << "current time " << ctime(&currentTime) <<std::endl;
    // std::cout << "Hi sent " << ledger -> BTCSentTotal("Hi") << " BTC and received " << ledger ->BTCReceiveTotal("Ho") << " BTC."  << "current time " << ctime(&currentTime) << std::endl;

    return 0;
}
