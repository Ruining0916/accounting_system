CXX=clang++
INCLUDES=-Iincludes/
CXXEXTRAS=-Wall -Wextra -Werror -pedantic
CXXFLAGS=-std=c++2a -g -fstandalone-debug

exec: bin/exec
tests: bin/tests

bin/exec: ./src/driver.cpp ./src/Accounts/account.cpp ./src/Transactions/transaction.cpp ./src/Ledgers/ledger.cpp ./includes/account.h ./includes/transaction.h ./includes/ledger.h 
	$(CXX) $(CXXFLAGS) $(CXXEXTRAS) $(INCLUDES) ./src/driver.cpp ./src/Accounts/account.cpp ./src/Transactions/transaction.cpp ./src/Ledgers/ledger.cpp -o $@

bin/tests: ./tests/tests.cc obj/catch.o ./src/Accounts/account.cpp ./src/Transactions/transaction.cpp ./src/Ledgers/ledger.cpp ./includes/account.h ./includes/transaction.h ./includes/ledger.h 
	$(CXX) $(CXXFLAGS) $(INCLUDES) ./tests/tests.cc obj/catch.o ../src/Accounts/account.cpp ./src/Transactions/transaction.cpp ./src/Ledgers/ledger.cpp -o $@

obj/catch.o: tests/catch.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $^ -o $@

.DEFAULT_GOAL := exec
.PHONY: clean exec tests

clean:
	rm -fr bin/* obj/*