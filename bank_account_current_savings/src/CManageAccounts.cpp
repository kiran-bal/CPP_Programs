#include "CManageAccounts.h"

CManageAccounts::CManageAccounts()
{
    //unimplemented
}

void CManageAccounts::AccountsManager()
{

    while(1)
    {
        repeatMainMenu:
        this->MainMenu();
        repeatinvalidmainmenu:
        cin >> nMainChoice;
        switch( nMainChoice )
        {
        case 1:
            repeatAdminMenu:
            system( "CLS" );
            this->Title();
            do
            {
            this->AdminMenu();
            returnMenu:
            cin >> nChoiceAdminMenu;
            system( "CLS" );
            switch( nChoiceAdminMenu )
            {
            case 1:
                this->Title();
               do
                {
                    system("CLS");
                    this->Title();
                    this->AccountTypeMenu();
                    repeat:
                    cin >> nChoiceType;
                    switch(nChoiceType)
                    {
                        case 1:
                        system( "CLS" );
                        this->Title();
                        cout << "\n\n\n";
                        cout << "\t\t------------------------- Savings Account Registration -------------------";
                        Account1[nIterateVariable]= new CSavingsAccount;
                        Account1[nIterateVariable]->AddDetails();
                        Account1[nIterateVariable]->AssignType("Savings");
                        cout << "\n\n";
                        cout << string(40,' ') << "Enter initial Balance: ";
                        cin>>fNewBalance;
                        Account1[nIterateVariable]->AssignBalance(fNewBalance);
                        cout << "\n\n\n";
                        cout << string(40,' ') << "Data Stored Successfully.\n\n" << string(40,' ') << "Press any key to continue...\n\n\n";

                        //Account1[nIterateVariable]->DisplayDetails();
                        nIterateVariable++;
                        getch();
                        goto repeatAdminMenu;
                        break;

                    case 2:

                        system( "CLS" );
                        this->Title();
                        cout << "\n\n\n";
                        cout << "\t\t------------------------- Current Account Registration -------------------";
                        Account1[nIterateVariable]= new CCurrentAccount;
                        Account1[nIterateVariable]->AddDetails();
                        Account1[nIterateVariable]->AssignType("Current");
                        cout << "\n\n";
                        cout << string(40,' ') << "Enter initial Balance: ";
                        cin >>fNewBalance;
                        Account1[nIterateVariable]->AssignBalance(fNewBalance);
                        cout << "\n\n\n";
                        cout << string(40,' ') << "Data Stored Successfully.\n\n" << string(40,' ') << "Press any key to continue...\n\n\n";
                        getch();
                       // Account1[nIterateVariable]->DisplayDetails();
                        nIterateVariable++;
                        goto repeatAdminMenu;
                        break;

                    case 3:goto repeatAdminMenu;
                            break;

                    default:
                        cout << string(40,' ') << "\nPlease enter valid option from Menu: ";
                        goto repeat;

                    }

                    }while(nChoiceType < 3);

                    break;
            case 2:
                this->Title();
                cout << "\n\n\n\n\n\n\n";
                cout <<  string(40,' ') << "Enter new interest rate:";
                float fNewInterest;
                cin >> fNewInterest;
                //check here make it static
                savingsaccount1[1].SetInterest(fNewInterest);
                cout << "\n\n\n\n" << string(40,' ') << "Interest rate changed successfully";
                cout << "\n\n\n" <<string(40, ' ') << "Press any key to continue...";
                getch();
                goto repeatAdminMenu;
                break;

            case 3:
                int nNewFee;
                this->Title();
                cout << "\n\n\n\n\n\n\n";
                cout <<  string(40,' ') << "enter new fine amount:";
                cin >> nNewFee;
                //check here
                currentaccount1[1].UpdateFee( nNewFee );
                cout << "\n\n\n\n" << string(40,' ') << "Fine amount updated successfully";
                cout << "\n\n\n" <<string(40, ' ') << "Press any key to continue...";
                getch();
                goto repeatAdminMenu;
                break;

            case 4:
                system("CLS");
                this->Title();

                cout << "\n\n\n\n\n" << string(40,' ') << "Account deatails" <<"\n\n\n";
                cout << "\n\n" << string(10,' ') << "Name" << "\t\t" << "Age" << "\t\t" << "Account Number" << "\t\t\t" << "Account Type" << "\t\t" << "Balance";
                for( int i = 0;i < nIterateVariable;i++)
                {
                    Account1[i]->DisplayDetails();
                }
                cout << "\n\n\n\n" << string(30, ' ') << "Press any key to contiue...";
                getch();
                goto repeatAdminMenu;
                break;

            case 5:goto repeatMainMenu;
            break;

            default:
                cout <<"Pleaase enter  valid choice from the menu: ";
                goto returnMenu;
            }

         break;

        case 2:
            int nAcNOCheckFlag = 0;
            system( "CLS");
            this->Title();
            cout << "\n\n\n\n\n";
            cout << string(40, ' ') << "Enter your Account Number:";
            repeatuser:
            cin >> szAcNumber;
            for (int i =0 ;i < nIterateVariable;i++)
            {
                if(Account1[i]->GetAccountNumber()==szAcNumber)
                {
                    nSelectedAccount = i;
                    nAcNOCheckFlag = 1;
                }
                else
                {
                    //not neccessary
                }
            }
            //check if found or not

            if(nAcNOCheckFlag == 0 )
            {
                cout << "\n\n\n" << string(40,' ') << "Account Not found please try again";
                getch();
                goto repeatuser;
            }
            else
            {
            system( "CLS" );
            this->Title();
            //add formatting
            cout << "\n\n\n\n" << string(40,' ') << "1.Deposit\n\n" << string(40,' ') << "2.Withdraw\n\n" << string(40, ' ') << "3.iew Balance\n\n" << string(40, ' ') << "4.Back to menu";
            cout << "\n\n\n" << string(40,' ') << "Enter your preferred choice from Menu (1,2,3 or 4) : ";
            transactionmenu:
            cin >> nUserChoice;
            switch(nUserChoice)
            {
            case 1:
                float fNewAmount;
                system( "CLS" );
                this->Title();
                cout << "\n\n\n";
                cout << string(40,' ') << "Deposit Cash\n";
                cout << string(40,' ') << "-------------\n\n\n";

                cout << string(40, ' ') << "\nDeposit amount: ";
                cin >>fNewAmount;
                Account1[nSelectedAccount]->DepositCash( fNewAmount );
                break;
            case 2:
                cout << "\n\n\n\n\n" << string(40, ' ') << "Enter the withdraw amount: ";
                cin >>fNewAmount;
                Account1[nSelectedAccount]->WithdrawCash( fNewAmount );
                break;

            case 3:

                cout << "\n\n\n\n\n" << string(40, ' ') << "Current Balance : " << Account1[nSelectedAccount]->GetBalance();
                break;

            default:
                cout << string(40, ' ') << "Please enter valid option from menu: ";
                goto transactionmenu;

            }
            }
        }while(nChoiceAdminMenu >5);
        break;

    case 9:
        cout << "\nExiting the program";
                exit(0);
                break;

    default:
        cout<<"please Enter Valid option from menu:";
        goto repeatinvalidmainmenu;
    }
}
}

void CManageAccounts::Title()
{
    cout << "*************************************************** Bank Transactions ***********************************************";
}

void CManageAccounts::MainMenu()
{
        this->Title();
        cout << "\n\n\n\n\n\n"<<string(40,' ') << "1.Administrator\n\n";
        cout << string(40,' ') << "2.Customer\n\n" << string(40,' ') << "9.Exit\n\n";
        cout << "\n\n" << string(40,' ') << "Enter your preferred choice(1 or 2) : ";
}

void CManageAccounts::AdminMenu()
{
        cout << "\n\n\n\n\n\n" << string(40,' ') << "1.New Registration\n\n" << string(40,' ') << "2.Change interest rate\n\n";
        cout << string(40,' ') << "3.change fee\n\n" << string(40,' ') << "4.View Details\n\n" << string(40,' ') << "5. Log out\n\n\n";
        cout << string(40,' ') << "Enter your preferred choice from Menu (1,2,3 or 4): ";
}

void CManageAccounts::AccountTypeMenu()
{

        cout << "\n\n\n\n\n" << string(40,' ') << "Account Type ";
        cout << "\n" << string(40,' ') << "-------------";
        cout << "\n\n\n";
        cout << string(40, ' ') << "1.Savings\n\n" << string(40,' ') << "2.Current\n\n" << string(40,' ') << "3.Back to AdminMenu\n\n";
        cout << string(40,' ') << "Enter your preferred choice from the menu (1 or 2): ";
}
