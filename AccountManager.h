// Author: Sammed Sunil Admuthe

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