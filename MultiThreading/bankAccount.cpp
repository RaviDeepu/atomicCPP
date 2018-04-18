#include<boost/thread.hpp>
#include<iostream>

using namespace std;

class Account
{
    public:
        int m_balance;
        boost::mutex m_mutex;

        Account():m_balance(0)
        {
            
        }

        void Deposit(int amount)
        {
            //this->checkBalance();
            boost::unique_lock<boost::mutex> lock(m_mutex);
            m_balance+= amount;
            this->checkBalance();
        }

        void Withdraw(int amount)
        {
            //this->checkBalance();

            boost::unique_lock<boost::mutex> lock(m_mutex);
            if(m_balance - amount >= 0)
            {
                m_balance = m_balance - amount;
            }
            else
            {
                cout<<"No Money to Withdraw\n";
            }
            this->checkBalance();
        }
        
        void checkBalance()
        {
            cout<<"Balance : "<<m_balance<<endl;
        }
};

int main()
{
    Account *myAccount = new Account;
    
    int ch;
    while(1)
    {
        cout<<"1. Deposit - 2. Withdraw\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                {
                    int amount;
                    cout<<"Enter Amount to be deposited\n";
                    cin>>amount;
                    myAccount->Deposit(amount);
                }
                break;
            case 2:
                {
                    int amount;
                    cout<<"Enter AMount to be Withdrawn\n";
                    cin>>amount;
                    myAccount->Withdraw(amount);
                }
                break;
            default:
                exit(0);
            
        }
    }
}
