#include "admin.h"
void loginsystem();
void registrationsystem();
void updateTwoFACode();
bool verifyOTP();


int main(){
    char x;
    cout << "\n\n\t\t\033[48;5;196m************ WELCOME TO SECURE SHOP! ************\033[0m\n";
    cout << "\t\t\033[48;5;30m************* FEEL SECURE, SHOP SECURE! *********\033[0m\n\n";
    
    do{
    cout<<"\n  Press R for registration and L for login \n";
    cin>>x;
    }while(x!='R' && x!='r' && x!='L' && x!='l');
    //INPUT VALIDATION OF USER CHOICEx

    switch(x){
    case 'L':
    case 'l':
    loginsystem();
    break;

    case 'R':
    case 'r':
    registrationsystem();
    break;
    }//Default ki zaroorat nahi hai kyun kaa uper input validation hoo chukki haii.
    return 0;
}

void loginsystem(){
    char username[50], password[50];
    int fattempts=1;
    
    cout<<"ENTER YOUR USERNAME: ";
    cin.ignore();
    cin.getline(username,50);

    cout<<"ENTER YOUR PASSWORD: ";
    cin.getline(password,50);
    char rolecheck = checkcredentials(username, password);
    loginsuccess:
    // char rolecheck='A';

    if (rolecheck == 'N'){
        cout<<"Invalid USERNAME OR PASSWORD. TRY AGAIN! " << endl;
        logactivity("LOGIN FAILED");
        cout<<"YOU FORGOT YOUR PASSWORD? DON'T WORRY WE GOT YOU!"<<endl;
        char choice;
        cout<<"PRESS 'Y' TO FORGET PASSWORD AND 'N' TO TRY LOGIN AGAIN \n";
        cin>>choice;
        if(choice=='Y'||choice=='y'){
            forgotpassword(username);
        }
        else if(choice=='N'||choice=='n'){
            loginsystem();
        }
    } 
    else {
        if (rolecheck == 'C'){
            logactivity("CUSTOMER LOGGED IN");
            customermenu();
        } else if (rolecheck == 'E') {
            logactivity("EMPLOYEE LOGGED IN");
            employeemenu();
        }else if (rolecheck == 'A') {
            updateTwoFACode();
            if (verifyOTP()){
                adminmenu();
                logactivity("ADMIN LOGGED IN");
            }else {
                cout << "ACCESS DENIED.\n";
                fattempts++;
                logactivity("ADMIN OTP FAILED");
                        if(fattempts>3){
                        cout<<"LOCKED OUT! TOO MANT FAIL ATTEMPTS"<<endl;
                        loginsystem();
                        }
                goto loginsuccess;
            }
        }
    }
}

bool verifyOTP() {
    ifstream statusFile("twofactorauth.txt");

    int status;
    statusFile >> status;
    statusFile.close();

    if (status == 0) {
        return true;
    }

    ifstream otpFile("OTP.txt");

    int storedOTP;
    otpFile >> storedOTP;
    otpFile.close();

    int userOTP;
    std::cout << "Enter the OTP: ";
    std::cin >> userOTP;  // Take OTP input from user

    if (storedOTP == userOTP) {
        return true;
    } else {
        return false;
    }
}

void updateTwoFACode() {
    srand(time(0));
    int OTP = rand() % 900000 + 100000;

    ofstream otpFile("OTP.txt", ios::out);
    otpFile<< OTP <<endl;
    otpFile.close();
}





void registrationsystem() {
    char firstname[50], lastname[50], dateofbirth[50], username[50], password[50], confirmpass[50], phoneno[20];
    char securityQ1[50], securityQ2[50], securityQ3[50];
    char role = 'C'; // Default role as Customer

    cout << "ENTER YOUR FIRST NAME: ";
    cin.ignore();
    cin.getline(firstname, 50);

    cout << "ENTER YOUR LAST NAME: ";
    cin.getline(lastname, 50);

    cout << "ENTER YOUR DATE OF BIRTH IN DD/MM/YYYY FORMAT: ";
    cin.getline(dateofbirth, 50);

    // Validate phone number
    do {
        cout << "ENTER YOUR PHONE NUMBER ALONG WITH COUNTRY CODE (+923091512006): ";
        cin.getline(phoneno, 20);
        if (!isValidPhoneNumber(phoneno)) {
            cout << "INVALID PHONE NUMBER! PLEASE ENTER A VALID ONE.\n";
        } else {
            break;
        }
    } while (true);

    // Validate username
    do {
        cout << "ENTER YOUR USERNAME: ";
        cin.getline(username, 50);
        if (usernameExists(username)) {
            cout << "USERNAME ALREADY EXISTS. PLEASE CHOOSE A DIFFERENT ONE.\n";
        } else {
            break;
        }
    } while (true);

    // Validate password
againpass:
    cout << "ENTER YOUR PASSWORD: ";
    cin.getline(password, 50);

    if (!isValidPassword(password)) {
        cout << "WEAK PASSWORD! IT MUST BE AT LEAST 8 CHARACTERS LONG AND INCLUDE UPPERCASE, LOWERCASE, NUMBERS, AND SPECIAL CHARACTERS.\n";
        goto againpass;
    }

    cout << "CONFIRM YOUR PASSWORD: ";
    cin.getline(confirmpass, 50);

    if (!stringcomparison(password, confirmpass)) {
        cout << "PASSWORDS DO NOT MATCH. PLEASE TRY AGAIN.\n";
        goto againpass;
    }

    // Encrypt username and password
    caesarCipherEncrypt(username, 3);
    caesarCipherEncrypt(password, 3);

    cout << "REGISTRATION SUCCESSFUL" << endl;
    cout << "NOW YOU NEED TO ANSWER THREE SECURITY QUESTIONS FOR YOUR OWN SAFETY IN CASE YOU FORGET YOUR PASSWORD :)" << endl;

    cout << "WHAT IS YOUR FAVORITE COLOR? ";
    cin.getline(securityQ1, 50);

    cout << "WHAT IS THE NAME OF YOUR HOMETOWN? ";
    cin.getline(securityQ2, 50);

    cout << "WHAT IS YOUR FAVORITE FOOD? ";
    cin.getline(securityQ3, 50);

    ofstream file("Credentials.txt", ios::app);
    if (file.is_open()) {
        file << username << "," 
             << password << "," 
             << role << "," 
             << securityQ1 << "," 
             << securityQ2 << "," 
             << securityQ3 << "," 
             << firstname << "," 
             << lastname << "," 
             << dateofbirth << "," 
             << phoneno << "\n";
        file.close();
    } else {
        cout << "ERROR: WE ARE DOING SOME MAINTENANCE OF SERVER AT THE MOMENT > PLEASE TRY AGAIN LATER.\n";
        return;
    }

    cout << "EVERYTHING IS DONE. PRESS ANY KEY TO RETURN TO MAIN MENU :) \n";

    logactivity("NEW CUSTOMER ACCOUNT CREATED");
    cin.get();
    loginsystem();
}
