#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

/*
ATM - Mini Project
-> check balance
-> cash withdraw
-> user details
-> update mobile number
*/

class ATM {
private:
    // -> private member variables

    long int account_no;
    string name;
    int PIN;
    double balance;
    string mobile_no;

public:
    // -> public member functions

    // setData function to set values to the private variables
    void setData(long int account_no, string name, int PIN, double balance, string mobile_no) {
        this->account_no = account_no;
        this->name = name;
        this->PIN = PIN;
        this->balance = balance;
        this->mobile_no = mobile_no;
    }

    // getAccountNo function
    long int getAccountNo() {
        return this->account_no;
    }

    // getName function
    string getName() {
        return this->name;
    }

    // getBalance function
    double getBalance() {
        return this->balance;
    }

    // get Pin function
    int getPin() {
        return this->PIN;
    }

    // get mobile no function
    string getMobileNo() {
        return this->mobile_no;
    }

    // update mobile number function
    void setNewMobileNo(string prev_no, string new_no) {
        if(this->mobile_no == prev_no) {
            this->mobile_no = new_no;
            cout << "Mobile number updated to " << this->mobile_no << endl;
        }

        else {
            cout << "Incorrect old mobile number entered" << endl;
        }
    }

    // cash withdrawl function
    void cashWithdraw(int amount) {
        if(amount > 0 && amount < this->balance) {
            this->balance -= amount;
            cout << "Please collect your cash" << endl;
            cout << "Available balance: " << this->balance << endl;
        }
        else {
            if(amount < 0) {
                cout << "Invalid amount Entered" << endl;
            }
            else {
                cout << "Insufficient funds" << endl;
            }
        }
    }


};

int main() {

    // create a user
    ATM user1;
    user1.setData(1234567,"Ayush Raina", 1111, 45000.8, "7889763345");

    // variables for input
    long int enter_account_no;
    int enter_PIN;

    // now we will start do while loop 
    do {

        // Required details to enter the atm;
        cout << "Enter Your Account No to proceed" << endl;
        cin >> enter_account_no;

        cout << "Enter your PIN" << endl;
        cin >> enter_PIN;

        // now move further only if entered details are correct
        if((enter_account_no == user1.getAccountNo()) && (enter_PIN == user1.getPin())) {

            // again start do while
            do {

                // declare variables for further use
                int amount = 0;
                string oldMobileNo, newMobileNo;
                int choice;

                // user interface
                cout << "**************** Welcome to the Tata ATM *****************" << endl;

                cout << "Select Options: " << endl;
                cout << "1. Check Balance" << endl;
                cout << "2. Cash Withdraw" << endl;
                cout << "3. Show User Details" << endl;
                cout << "4. Update Mobile Number" << endl;
                cout << "5. Exit" << endl;

                cin >> choice;

                switch(choice) {
                    case 1:
                        cout << "Your Balance is: " << user1.getBalance() << endl;
                        sleep(5);
                        break;
                    case 2:
                        cout << "Enter the amount to withdraw: " << endl;
                        cin >> amount;
                        user1.cashWithdraw(amount);
                        sleep(5);
                        break;
                    case 3:
                        cout << "User Details are: " << endl;
                        cout << "Account Numeber -> " << user1.getAccountNo() << endl;
                        cout << "Name -> " << user1.getName() << endl;
                        cout << "Balance -> " << user1.getBalance() << endl;
                        cout << "Mobile No -> " << user1.getMobileNo() << endl;
                        sleep(5);
                        break;
                    case 4:
                        cout << "Enter old mobile number: " << endl;
                        cin >> oldMobileNo;

                        cout << "Enter new mobile number: " << endl;
                        cin >> newMobileNo;

                        user1.setNewMobileNo(oldMobileNo, newMobileNo);
                        sleep(5);
                        break;
                    case 5:
                        exit(0);
                }
            }while(1);
        }
    }while(1);
}