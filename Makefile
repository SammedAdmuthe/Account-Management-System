CXX = g++
CXXFLAGS = -Wall -g -w

# Executable name
EXEC = BankApp

# Source files
SRCS = main.cpp Account.cpp DoublyLinkedList.cpp StockAccount.cpp BankAccount.cpp AccountManager.cpp

# Object files (generated from source files)
OBJS = $(SRCS:.cpp=.o)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

main.o: main.cpp StockAccount.h BankAccount.h SymbolSortStrategy.h SharesValueSortStrategy.h
	$(CXX) $(CXXFLAGS) -c -o main.o main.cpp

Account.o: Account.cpp Account.h
	$(CXX) $(CXXFLAGS) -c -o Account.o Account.cpp

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h StockAccount.h ListNode.h SortingStrategy.h
	$(CXX) $(CXXFLAGS) -c -o DoublyLinkedList.o DoublyLinkedList.cpp

StockAccount.o: StockAccount.cpp StockAccount.h AccountManager.h Account.h DoublyLinkedList.h
	$(CXX) $(CXXFLAGS) -c -o StockAccount.o StockAccount.cpp

BankAccount.o: BankAccount.cpp BankAccount.h Account.h AccountManager.h
	$(CXX) $(CXXFLAGS) -c -o BankAccount.o BankAccount.cpp 

AccountManager.o: AccountManager.cpp AccountManager.h
	$(CXX) $(CXXFLAGS) -c -o AccountManager.o AccountManager.cpp 

clean:
	rm -f $(OBJS) $(EXEC)
