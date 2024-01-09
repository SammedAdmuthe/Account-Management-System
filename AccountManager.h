// Author: Sammed Sunil Admuthe
// Singleton class for AccountManager - restricts creation of more than 1 instances of this class to maintain synchronization between the balance in the bank account and the balance in the stock account.   
class AccountManager
{   
    private:
        double balance;
        static AccountManager* instance;
        AccountManager(double initialBalance);
    public:
        static AccountManager* getInstance(double initialBalance=0);
        double getBalance() const;
        void setBalance(double amount);
        bool isNewAccount();
        AccountManager(const AccountManager&) = delete;
        AccountManager& operator=(const AccountManager&) = delete;
        ~AccountManager() {}
};