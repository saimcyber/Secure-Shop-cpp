#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include"employee.h"
using namespace std;

void adminmenu();

void usermanagement();
void addnewuser();
bool isValidPhoneNumber(const char*);
bool isValidPassword(const char*);


void editexistinguser();
void changeusername(char[]);
void changepassword(char[]);
void changename(char[]);
void changedob(char[]);
void changephoneno(char[]);
void changerole(char[]);

void removeuser();

void displayusers();

void productmanagement();
void editproduct();

void discountandpromotion();
void displaypromocode();
void newpromocode();
void deletepromocode();

void twoFAmanage();

void displayactivitylogs();

void salesandrevenueanalysis();

void announcementsmanagement();
void addannouncements();
void deleteannouncements();


void adminmenu(){
        setColor(4);
        cout << "\t \t   *************************************************\n";
        cout << "\t \t   *               Admin Menu                      *\n";
        cout << "\t \t   *************************************************\n";
        resetColor();
        setColor(1);
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   1-->  USER MANAGEMENT                                  |" << endl;
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   2-->  ADVANCED PRODUCT MANAGEMENT                      |" << endl;
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   3-->  DISCOUNT AND PROMOTIONS                          |" << endl;
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   4--> 2FA SECURITY MANAGEMENT                           |" << endl;
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   5--> VIEW ACTIVITY LOGS                                |" << endl;
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   6--> SALES AND REVENUE ANALYSIS                        |" << endl;
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   7--> ANNOUNCEMENT MANAGEMENT                           |" << endl;
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   8--> EXIT                                              |" << endl;
        cout << "\t \t----------------------------------------------------------" << endl;
        resetColor();

    int choice;
    do{
        cin>>choice;

        if (cin.fail()) {
            cout << "Invalid input! Please enter a number between 1 and 8.\n";
            cin.clear();
            cin.ignore(200, '\n');
            choice = 0;
        } else if (choice < 1 || choice > 8) {
            cout << "Invalid choice! Please select a valid option (1 to 8).\n";
        }

    }while(choice>8 || choice<1);

    switch(choice){
        case 1:
            usermanagement();
            cout<<"PRESS ANY KEY TO GO BACK TO ADMIN PANEL";
            cin.ignore();
            cin.get();
            adminmenu();
            break;
        
        case 2:
            productmanagement();
            cout<<"PRESS ANY KEY TO GO BACK TO ADMIN PANEL";
            cin.ignore();
            cin.get();
            adminmenu();
            break;

        case 3:
            discountandpromotion();
            cout<<"\nPRESS ANY KEY TO GO BACK TO ADMIN PANEL";
            cin.ignore();
            cin.get();
            adminmenu();
            break;
        
        case 4:
            twoFAmanage();
            cout<<"\nPRESS ANY KEY TO GO BACK TO ADMIN PANEL";
            cin.ignore();
            cin.get();
            adminmenu();
            break;
        
        case 5:
            displayactivitylogs();
            cout<<"\nPRESS ANY KEY TO GO BACK TO ADMIN PANEL";
            cin.ignore();
            cin.get();
            adminmenu();
            break;

        case 6:
            salesandrevenueanalysis();
            cout<<"\nPRESS ANY KEY TO GO BACK TO ADMIN PANEL";
            cin.ignore();
            cin.get();
            adminmenu();
            break;

        case 7:
            announcementsmanagement();
            cout<<"\nPRESS ANY KEY TO GO BACK TO ADMIN PANEL";
            cin.ignore();
            cin.get();
            adminmenu();
            break;

        case 8:
            cout << "\t\t\033[48;5;196m************ GOOBYE ADMIN! ************\033[0m\n";
            cout << "\t\t\033[48;5;30m************ We Wish to See You Again! *********\033[0m\n\n";
            cin.ignore();
            break;
            return;
            exit;
    }
}

void announcementsmanagement(){
        cout << "------------------------------------------" << endl;
        cout << "|        ANNOUNCEMENT MANAGEMENT         |" << endl;
        cout << "|----------------------------------------|" << endl;
        cout << "| 1. ADD ANNOUNCEMENT                    |" << endl;
        cout << "| 2. DELETE ANNOUNCEMENT                 |" << endl;
        cout << "| 3. VIEW ANNOUNCMENTS                   |" << endl;
        cout << "| 4. BACK TO MAIN MENU                   |" << endl;
        cout << "------------------------------------------" << endl;
    int choice;
    do {
        cout << "ENTER YOUR CHOICE (1 TO 4): ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input! Please enter a number between 1 and 4.\n";
            cin.clear();
            cin.ignore(200, '\n');
            choice = 0;
        } else if (choice < 1 || choice > 4) {
            cout << "Invalid choice! Please select a valid option (1 to 4).\n";
        }

    } while (choice < 1 || choice > 4);

    switch(choice){
        case 1:
        addannouncements();
        cout<<"PRESS ANY KEY TO GO BACK TO ANNOUNCEMENT MANAGEMENT \n";
        cout<<"-------------------------------------\n";
        cin.ignore();
        cin.get();
        announcementmanagement();
        break;

        case 2:
        deleteannouncements();
        cout<<"PRESS ANY KEY TO GO BACK TO ANNOUNCEMENT MANAGEMENT \n";
        cout<<"-------------------------------------\n";
        cin.ignore();
        cin.get();
        announcementmanagement();
        break;

        case 3:
        viewannouncement();
        cout<<"PRESS ANY KEY TO GO BACK TO ANNOUNCEMENT MANAGEMENT \n";
        cout<<"-------------------------------------\n";
        cin.ignore();
        cin.get();
        announcementmanagement();
        break;

        case 4:
        adminmenu();
        break;
    }
}

void addannouncements() {
    cout << "---------------------------------------\n";
    cout << "          ADD ANNOUNCEMENT\n";
    cout << "---------------------------------------\n";

    char announcement[100];
    cout << "ENTER ANNOUNCEMENT: ";
    cin.ignore();
    cin.getline(announcement, 100);

    ofstream file("Announcement.txt", ios::app);

    //ANNOUNCEMENT KAA NUMBER 1 SAA START HOO GAA.
    int announcementNumber = 1;
    ifstream checkFile("Announcement.txt");
    char line[200];
    while (checkFile.getline(line, 200)) {
        announcementNumber++;
    }

    file << announcementNumber << " | " << announcement << "\n";
    file.close();

    cout << "ANNOUNCEMENT ADDED SUCCESSFULLY!\n";
    logactivity("ADMIN ADDED AN ANNOUNCEMENT");
}


void deleteannouncements() {
    cout << "---------------------------------------\n";
    cout << "          DELETE ANNOUNCEMENT\n";
    cout << "---------------------------------------\n";

    int announcementNumber;
    do {
        cout << "ENTER THE ANNOUNCEMENT NUMBER TO DELETE: ";
        cin >> announcementNumber;
        if (cin.fail()){
            cout << "Invalid input!";
            cin.clear();
            cin.ignore(200, '\n');
            announcementNumber = 0;
        } else if (announcementNumber < 1 || announcementNumber > 9999) {
            cout << "Invalid choice!.\n";
        }
    } while (announcementNumber < 1 || announcementNumber > 9999);

    ifstream file("Announcement.txt");
    ofstream tempFile("TempAnnouncement.txt");

    char line[200];
    bool deleted = false;// SIRF YE CHECK KARNA KA LIYE KAA DELETE HOA BHI HAI YAA NAHI

    while (file.getline(line, 200)){
        int number = 0, i = 0;
        while (line[i] != ' ' && line[i] != '\0'){
            number = number * 10 + (line[i] - '0'); //MANUAL STRING TO INTEGER CONVERSION
            i++;
        }
        if (number == announcementNumber) {
            deleted = true;
            continue;//JIS KO DELETE KARNA HAI USS KOO SKIP KAR DOO
        }
        tempFile << line << "\n";//BAKKKI SAB KOO WRITE KAR DOO TEMP MAII
    }

    file.close();
    tempFile.close();

    if(deleted) {
        remove("Announcement.txt");
        rename("TempAnnouncement.txt", "Announcement.txt");
        cout << "ANNOUNCEMENT DELETED SUCCESSFULLY!\n";
        logactivity("ANNOUNCEMENT DELETED BY ADMIN");
    } else {
        cout << "ERROR: Announcement number not found.\n";
    }
}



void salesandrevenueanalysis() {
    cout << "---------------------------------------\n";
    cout << "      SALES AND REVENUE ANALYSIS\n";
    cout << "---------------------------------------\n";
    completecontributions();
}



void displayactivitylogs() {
        cout << "\n\n\n------------------------------------------" << endl;
        cout << "|              ACTIVITY LOGS             |" << endl;
        cout << "|----------------------------------------|" << endl;
        cout << "| 1. DISPLAY ALL ACTIVITY LOGS           |" << endl;
        cout << "| 2. DELETE ALL ACTIVITY LOGS            |" << endl;
        cout << "------------------------------------------" << endl;
    int choicee;
    do{
        cout << "ENTER YOUR CHOICE: ";
        cin >> choicee;
        if (cin.fail()) {
            cout << "Invalid input!";
            cin.clear();
            cin.ignore(200, '\n');
            choicee = 0;
        } else if (choicee < 1 || choicee > 2) {
            cout << "Invalid choice!.\n";
        }
    }while(choicee>2 || choicee<1);

    if(choicee==1){
    logactivity("ALL ACTIVITY LOGS DISPLAYED TO THE ADMIN");
    ifstream file("ActivityLogs.txt");

    char line[200];
    while (file.getline(line, 200)) {//SAB KUCH HII PRINT KARWAA DOO
        cout << line << endl;
    }

    file.close();
    }

    else if(choicee==2){
        ofstream file("ActivityLogs.txt", ios::trunc);//DELETE KARNA KAA LIYEE TRUNCATE MODE SAA KHULNA HII KAAFI HAII 
    logactivity("ALL ACTIVITY LOGS DELETED BY THE ADMIN");
    cout <<"Activity logs have been cleared successfully.\n";
    file.close();
    }
}


void twoFAmanage() {
    cout << "\n\n------------------------------------------" << endl;
    cout << "|         2-FACTOR AUTHENTICATION        |" << endl;
    cout << "|----------------------------------------|" << endl;
    cout << "| 1. ENABLE 2-FACTOR AUTHENTICATION      |" << endl;
    cout << "| 2. DISABLE 2-FACTOR AUTHENTICATION     |" << endl;
    cout << "------------------------------------------" << endl;

    int choice;
    do {
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;
        if (cin.fail()) {
            cout << "Invalid input! ENTER A NUMBER 1 OR 2.\n";
            cin.clear();
            cin.ignore(200, '\n');
            choice = 0;
        } else if (choice < 1 || choice > 2) {
            cout << "Invalid choice! ENTER A NUMBER 1 OR 2.\n";
        }
    } while (choice < 1 || choice > 2);

    ifstream file("twofactorauth.txt");
    char* buffer = allocateBufferForLongestLine("twofactorauth.txt");
    if (buffer == nullptr) {
        return;
    }

    if (!file.is_open()) {
        cout << "ERROR: Unable to open twofactorauth.txt file.\n";
        return;
    }

    file.getline(buffer, 1000);
    string remainingContent;
    while (file.getline(buffer, 1000)) {
        remainingContent += buffer;
        remainingContent += "\n";
    }
    file.close();

    ofstream outFile("twofactorauth.txt", ios::trunc);
    if (choice == 1) {
        outFile << "1\n";
        logactivity("2FA ENABLED BY ADMIN");
        cout << "2-FACTOR AUTHENTICATION ENABLED.\n";
    } else {
        outFile << "0\n";
        logactivity("2FA DISABLED BY ADMIN");
        cout << "2-FACTOR AUTHENTICATION DISABLED.\n";
    }

    delete[] buffer;
    outFile << remainingContent;
    outFile.close();
}



void discountandpromotion(){
        cout << "\n\n------------------------------------------" << endl;
        cout << "|         DISCOUNT AND PROMOTIONS        |" << endl;
        cout << "|----------------------------------------|" << endl;
        cout << "| 1. SHOW EXISTING PROMOCODES            |" << endl;
        cout << "| 2. ADD NEW PROMOCODES                  |" << endl;
        cout << "| 3. DELETE EXISTING PROMOCODES          |" << endl;
        cout << "| 4. BACK TO ADMIN MENU                  |" << endl;
        cout << "------------------------------------------" << endl;
    int choice;
    do{
        cin>>choice;
        if (cin.fail()){
            cout << "Invalid input! ENTER A NUMBER 1 TO 4, \n";
            cin.clear();
            cin.ignore(200, '\n');
            choice = 0;
        } else if (choice < 1 || choice > 4){
            cout<<"Invalid choice! ENTER A NUMBER 1 TO 4.\n";
        }
    }while(choice>4 || choice<1);

    switch(choice){
        case 1:
            displaypromocode();
            cout<<"PRESS ANY KEY TO GO BACK TO DISCOUNT MANAGEMENT \n";
            cout<<"-------------------------------------\n";
            cin.ignore();
            cin.get();
            discountandpromotion();
            break;
        
        case 2:
            newpromocode();
            cout<<"PRESS ANY KEY TO GO BACK TO DISCOUNT MANAGEMENT \n";
            cout<<"-------------------------------------\n";
            cin.ignore();
            cin.get();
            discountandpromotion();
            break;

        case 3:
            deletepromocode();
            cout<<"PRESS ANY KEY TO GO BACK TO DISCOUNT MANAGEMENT \n";
            cout<<"-------------------------------------\n";
            cin.ignore();
            cin.get();
            discountandpromotion();
            break; 

        case 4:
            adminmenu();
            break;
    }
}

void deletepromocode() {
    char promocode[20];
    cout << "----------------------------------------------\n";
    cout << "          DELETE PROMOCODE          \n";
    cout << "----------------------------------------------\n";
    cout << "ENTER THE PROMOCODE: ";
    cin.ignore();
    cin.getline(promocode, 20);

    ifstream file("promocode.txt");
    ofstream tempFile("TempPromocode.txt");

    char buffer[500];
    bool found = false;

    while (file.getline(buffer, 500)){
        char currentPromocode[20];
        int i = 0, j = 0;

        while (buffer[i] != ' ' && buffer[i] != '\0'){
            currentPromocode[j++] = buffer[i++]; //PROMOCODE AA KAR STORE HOO JAYEE GAA
        }
        currentPromocode[j] = '\0';

        if (stringcomparison(currentPromocode, promocode) != 0) //MATCH NAA HOAA TUU STORE KARWA DOO DUBARA
         {
            tempFile << buffer << endl;
        } else {
            found = true;
        }
    }

    file.close();
    tempFile.close();

    if (found) {
        remove("promocode.txt");
        rename("TempPromocode.txt", "promocode.txt");
        cout << "PROMOCODE DELETED SUCCESSFULLY.\n";
        logactivity("PROMOCODE DELETED BY ADMIN");
    } else {
        cout << "PROMOCODE NOT FOUND.\n";
        remove("TempPromocode.txt");
    }
}

void displaypromocode() {
    ifstream file("promocode.txt");

    char* buffer = allocateBufferForLongestLine("promocode.txt");
    if (buffer == nullptr) {
        return;
    }
    cout << "-----------------------------------------------\n";
    cout << "               DISPLAY PROMOCODES               \n";
    cout << "-----------------------------------------------\n";

    while (file.getline(buffer, 500)) {
        char promocode[20], type[50], quantity[20], discount[20];
        int i = 0, j = 0;

        while (buffer[i] != '|' && buffer[i] != '\0') { //FIRST PIPE TK PROMOCODE YAHAN SA NIKAL AYE GAA
            promocode[j++] = buffer[i++];
        }
        promocode[j] = '\0'; //YE FILE WALA PROMOCODE KAA END PAR NULL LAGAA DEE GAA
        i++;
        j = 0;

        while (buffer[i] != '|' && buffer[i] != '\0') { //YAHAN SAA TYPE NIKAL AYEE GII 
            type[j++] = buffer[i++];
        }
        type[j] = '\0';
        i++; //YEE | SAA AGAA JUMP KARWAA DEE GAA
        j = 0;

        while (buffer[i] != '|' && buffer[i] != '\0') { //YAHAN SAA QUANTITY NIKAL AYEE GII
            quantity[j++] = buffer[i++];
        }
        quantity[j] = '\0'; 
        i++;
        j = 0;

        while (buffer[i] != '\0' && buffer[i] != '\n') { //YAHAN SAA DISOCOUNT NIKAL LEIN GAA
            discount[j++] = buffer[i++];
        }
        discount[j] = '\0';

        //YAHAN PAR SAB KUCH ADMIN KOO DISPLAY KARWAAA DEIN GAA
        cout << "\nPromocode: " << promocode << endl;
        cout << "Type: " << type << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Discount: " << discount << endl;
        cout << "-----------------------------------------------\n";

    }
    logactivity("ALL PRMOCODES DISPLAYED TO ADMIN");
    delete[] buffer;
    file.close();
}



void newpromocode() {
        cout << "\n\n------------------------------------------" << endl;
        cout << "|        NEW PROMOCODE GENERATION        |" << endl;
        cout << "|----------------------------------------|" << endl;
        cout << "| 1. QUANTITY BASED PROMOCODES           |" << endl;
        cout << "| 2. AMOUNT BASED PROMOCODES             |" << endl;
        cout << "| 3. BACK TO ADMIN MENU                  |" << endl;
        cout << "------------------------------------------" << endl;
    
    int choice;
    do{
        cin>>choice;
        if (cin.fail()){
            cout << "Invalid input! ENTER A NUMBER 1 TO 3, \n";
            cin.clear();
            cin.ignore(200, '\n');
            choice = 0;
        } else if (choice < 1 || choice > 3){
            cout<<"Invalid choice! ENTER A NUMBER 1 TO 3.\n";
        }
    }while(choice>3 || choice<1);

    //PROMOCODE KAA SAB KUCH PTAA HAII HUMME ISI LIYEE HUM USI HISAAB SAA VARIABLES AUR ARRAYS BNAAYEIN GAA
    char promocode[20];
    int quantity = 0;
    float discount = 0.0;
    float amount = 0.0;
    char promocodeType[20];

    ofstream file("promocode.txt", ios::app);

    switch (choice) {
        case 1:
            // Quantity-based promocode
            cout << "----------------------------------------------\n";
            cout << "          QUANTITY BASED PROMOCODE          \n";
            cout << "----------------------------------------------\n";
            do{
                cout << "ENTER THE QUANTITY FOR WHICH PROMOCODE WILL BE APPLIED: ";
                cin >> quantity;
                if (cin.fail()){
                    cout << "Invalid input!\n";
                    cin.clear();
                    cin.ignore(200, '\n');
                    quantity = 0;
                } else if (quantity < 1 || quantity > 9999999){
                    cout<<"Invalid choice!\n";
            }}while(quantity>9999999 || quantity<1);

            do{
                cout << "ENTER THE DISCOUNT PERCENTAGE: ";
                cin >> discount;
                if (cin.fail()){
                    cout << "Invalid input!\n";
                    cin.clear();
                    cin.ignore(200, '\n');
                    discount = -1;
                } else if (discount < 0 || discount > 100){
                    cout<<"Invalid choice!\n";
            }}while(discount>100 || discount<0);
            discount /= 100;

            cout << "ENTER THE PROMOCODE: ";
            cin.ignore();
            cin.getline(promocode, 20);
            
            copychararray(promocodeType, "Quantity-Based");

            file << promocodeType << " | " << promocode << " | " << quantity << " | " << discount*100<< "%" << "\n";
            logactivity("QUANTITY BASED PROMOCODE ADDED");
            cout << "PROMOCODE ADDED SUCCESSFULLY.\n";
            break;

        case 2:
            // Amount-based promocode
            cout << "----------------------------------------------\n";
            cout << "          AMOUNT BASED PROMOCODE            \n";
            cout << "----------------------------------------------\n";
            do{
                cout << "ENTER THE AMOUNT FOR WHICH PROMOCODE WILL BE APPLIED: ";
                cin >> amount;
                if (cin.fail()){
                    cout << "Invalid input!\n";
                    cin.clear();
                    cin.ignore(200, '\n');
                    amount = 0;
                } else if (amount < 1 || amount > 9999999){
                    cout<<"Invalid choice!\n";
            }}while(amount>9999999 || amount<1);


            do{
                cout << "ENTER THE DISCOUNT PERCENTAGE: ";
                cin >> discount;
                if (cin.fail()){
                    cout << "Invalid input!\n";
                    cin.clear();
                    cin.ignore(200, '\n');
                    discount = -1;
                } else if (discount < 0 || discount > 100){
                    cout<<"Invalid choice!\n";
            }}while(discount>100 || discount<0);
            discount /= 100;

            cout << "ENTER THE PROMOCODE: ";
            cin.ignore();
            cin.getline(promocode, 20);
            
            copychararray(promocodeType, "Amount-Based");

            file << promocodeType << " | " << promocode << " | " << amount << " | " << discount * 100 << "%" << "\n";
            logactivity("AMOUNT BASED PROMOCODE ADDED");
            cout << "PROMOCODE ADDED SUCCESSFULLY.\n";
            break;

        case 3:
            cout << "Returning to admin menu...\n";
            break;
    }
    file.close();
}






//-----------------------2ND FUNCTION FINISHED-----------------------------------
void productmanagement(){
        cout << "\n\n   ------------------------------------------" << endl;
        cout << "|           PRODUCT MANAGEMENT           |" << endl;
        cout << "|----------------------------------------|" << endl;
        cout << "| 1. DISPLAY COMPLETE CATALOGUE          |" << endl;
        cout << "| 2. ADD ANY PRODUCT                     |" << endl;
        cout << "| 3. EDIT ANY PRODUCT                    |" << endl;
        cout << "| 4. DELETE ANY PRODUCT                  |" << endl;
        cout << "| 5. BACK TO ADMIN MENU                  |" << endl;
        cout << "------------------------------------------" << endl;
    
    int choice2;
    do{
        cin>>choice2;
        if (cin.fail()){
            cout << "Invalid input! ENTER A NUMBER 1 TO 5, \n";
            cin.clear();
            cin.ignore(200, '\n');
            choice2 = 0;
        } else if (choice2 < 1 || choice2 > 5){
            cout<<"Invalid choice! ENTER A NUMBER 1 TO 5.\n";
        }
    }while(choice2>5 || choice2<1);
    
    switch(choice2){
        case 1:
            displayallproducts();
            cout<<"PRESS ANY KEY TO GO BACK TO INVENTORY MANAGEMENT \n";
            cout<<"-------------------------------------\n";
            cin.ignore();
            cin.get();
            productmanagement();
            break;
        case 2:
            addanyproduct();
            cout<<"PRESS ANY KEY TO GO BACK TO INVENTORY MANAGEMENT \n";
            cout<<"-------------------------------------\n";
            cin.ignore();
            cin.get();
            productmanagement();
            break;

        case 3:
            editproduct();
            cout<<"PRESS ANY KEY TO GO BACK TO INVENTORY MANAGEMENT \n";
            cout<<"-------------------------------------\n";
            cin.ignore();
            cin.get();
            productmanagement();
            break;
        
        case 4:
            deleteanyproduct();
            cout<<"PRESS ANY KEY TO GO BACK TO INVENTORY MANAGEMENT \n";
            cout<<"-------------------------------------\n";
            cin.ignore();
            cin.get();
            productmanagement();
            break;

        case 5:
            adminmenu();
            break;
    }
}

void editproduct(){
    cout << "-------------------------------------\n";
    cout << "        EDITING PRODUCT\n";
    cout << "-------------------------------------\n";

    char pid[5];
    bool valid;

    do{
    valid = true;
    cout << "ENTER THE PRODUCT ID YOU WANT TO EDIT: ";
    cin >> pid;
    for (int i = 0; pid[i] != '\0'; i++) {
        if (pid[i] < '0' || pid[i] > '9') {
            valid = false;
            break;
        }
    }
    if (!valid) {
        cout << "Invalid input! PRODUCT ID MUST CONTAIN DIGITS ONLY.\n";
    }}while(!valid);

    ifstream productsFile("products.txt");

    char buffer[200], fileProductID[50], fileName[50], fileCategory[50], fileQuantity[50], filePrice[50];
    bool productFound = false;
    ofstream tempFile("temp_products.txt");

    while (productsFile.getline(buffer, 200)) {
        int i = 0, j = 0;

        //ProductID
        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileProductID[j++] = buffer[i++];
        }
        fileProductID[j] = '\0';
        i++;

        //Name
        j = 0;
        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileName[j++] = buffer[i++];
        }
        fileName[j] = '\0';
        i++;

        //Category
        j = 0;
        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileCategory[j++] = buffer[i++];
        }
        fileCategory[j] = '\0';
        i++;

        //Quantity
        j = 0;
        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileQuantity[j++] = buffer[i++];
        }
        fileQuantity[j] = '\0';
        i++;

        //Price
        j = 0;
        while (buffer[i] != '\0') {
            filePrice[j++] = buffer[i++];
        }
        filePrice[j] = '\0';

        trim(fileProductID);
        trim(fileName);
        trim(fileCategory);
        trim(fileQuantity);
        trim(filePrice);

        //YAHAN PAR HAR SINGLE LINE(PRODUCT) ANAA KAA BAAD CHECK HOO GII, MATCH HOO GAYI TUU USS KAA SAARA DATA DISPLAY HOO JAYEE GAA
        if (stringcomparison(pid, fileProductID)) {
            productFound = true;

            cout << "Product ID: " << fileProductID << endl;
            cout << "Name: " << fileName << endl;
            cout << "Category: " << fileCategory << endl;
            cout << "Quantity: " << fileQuantity << endl;
            cout << "Price: " << filePrice << endl;

        cout << " ___________________________________________\n";
        cout << "|                                           |\n";
        cout << "| WHAT DO YOU WANT TO EDIT OF THIS PRODUCT? |\n";
        cout << "|                                           |\n";
        cout << "|___________________________________________|\n";
        cout << "|                                           |\n";
        cout << "| 1. NAME OF THE PRODUCT                    |\n";
        cout << "| 2. CATEGORY OF THE PRODUCT                |\n";
        cout << "| 3. PRICE OF THE PRODUCT                   |\n";
        cout << "| 4. QUANTITY OF A PRODUCT                  |\n";
        cout << "| 5. GO BACK TO MAIN MENU                   |\n";
        cout << "|___________________________________________|\n";       

            int choice;
            do{
            cin>>choice;
            if (cin.fail()){
                cout << "Invalid input! ENTER A NUMBER 1 TO 5.\n";
                cin.clear();
                cin.ignore(200, '\n');
                choice = 0;
            }else if (choice < 1 || choice > 5){
                cout<<"Invalid choice! ENTER A NUMBER 1 TO 5.\n";
            }}while(choice>5 || choice<1);

            switch (choice) {
                case 1: {
                    char newName[50];
                    cout << "ENTER NEW NAME: ";
                    cin.ignore();
                    cin.getline(newName, 50);
                    tempFile << fileProductID << " | " << newName << " | " << fileCategory << " | "
                             << fileQuantity << " | " << filePrice << endl;
                    logactivity("PRODUCT NAME EDITED BY ADMIN");
                    break;
                }

                case 2: {
                    char newCategory[50];
                    cout << "ENTER NEW CATEGORY: ";
                    cin.ignore();
                    cin.getline(newCategory, 50);
                    tempFile << fileProductID << " | " << fileName << " | " << newCategory << " | "
                             << fileQuantity << " | " << filePrice << endl;
                    logactivity("PRODUCT CATEGORY EDITED BY ADMIN");
                    break;
                }

                case 3: {
                    char newPrice[50];
                    bool valid;
                    do{
                        valid = true;
                        cout << "ENTER NEW PRICE: ";
                        cin >> newPrice;
                        for (int i = 0; newPrice[i] != '\0'; i++) {
                            if (newPrice[i] < '0' || newPrice[i] > '9') {
                                valid = false;
                                break;
                            }
                        }
                        if (!valid) {
                            cout << "Invalid input! PRICE MUST CONTAIN DIGITS ONLY.\n";
                        }}while(!valid);

                    tempFile << fileProductID << " | " << fileName << " | " << fileCategory << " | "
                             << fileQuantity << " | " << newPrice << endl;
                    logactivity("PRODUCT PRICE EDITED BY ADMIN");
                    break;
                }

                case 4: {
                    char newQuantity[50];
                    bool valid;
                    do{
                        valid = true;
                        cout << "ENTER NEW QUANTITY: ";
                        cin >> newQuantity;
                        for (int i = 0; newQuantity[i] != '\0'; i++) {
                            if (newQuantity[i] < '0' || newQuantity[i] > '9') {
                                valid = false;
                                break;
                            }
                        }
                        if (!valid) {
                            cout << "Invalid input! QUANTITY MUST CONTAIN DIGITS ONLY.\n";
                        }}while(!valid);

                    tempFile << fileProductID << " | " << fileName << " | " << fileCategory << " | "
                             << newQuantity << " | " << filePrice << endl;
                    logactivity("PRODUCT QUANTITY EDITED BY ADMIN");
                    break;
                }

                case 5:
                    break;
            }
        } else {
            tempFile << fileProductID << " | " << fileName << " | " << fileCategory << " | "
                     << fileQuantity << " | " << filePrice << endl;
        }
    }

    productsFile.close();
    tempFile.close();

    if (productFound) {
        remove("products.txt");
        rename("temp_products.txt", "products.txt");
        cout << "Product updated successfully.\n";
    } else {
        cout << "ERROR: Product ID not found.\n";
    }
}





//----------1ST FUNCTION COMPLETED BELOW-----------------------

void usermanagement(){
        cout << "\n\n------------------------------------------" << endl;
        cout << "|           USER MANAGEMENT              |" << endl;
        cout << "|----------------------------------------|" << endl;
        cout << "| 1. ADD NEW USER                        |" << endl;
        cout << "| 2. EDIT EXISTING USER                  |" << endl;
        cout << "| 3. REMOVE USER                         |" << endl;
        cout << "| 4. VIEW ALL USERS                      |" << endl;
        cout << "| 5. BACK TO ADMIN MENU                  |" << endl;
        cout << "------------------------------------------" << endl;
    int choice;
    do{
        cin>>choice;
        if (cin.fail()){
            cout << "Invalid input! ENTER A NUMBER 1 TO 5.\n";
            cin.clear();
            cin.ignore(200, '\n');
            choice = 0;
        }else if (choice < 1 || choice > 5){
                cout<<"Invalid choice! ENTER A NUMBER 1 TO 5.\n";
        }}while(choice>5 || choice<1);

    switch(choice){
        case 1:
            addnewuser();
            cout<<"PRESS ANY KEY TO GO BACK TO USER MANAGEMENT";
            cin.ignore();
            cin.get();
            usermanagement();
            break;

        case 2:
            editexistinguser();
            cout<<"PRESS ANY KEY TO GO BACK TO USER MANAGEMENT";
            cin.ignore();
            cin.get();
            usermanagement();
            break;
        
        case 3:
            removeuser();
            cout<<"PRESS ANY KEY TO GO BACK TO USER MANAGEMENT";
            cin.ignore();
            cin.get();
            usermanagement();
            break;

        case 4:
            displayusers();
            cout<<"PRESS ANY KEY TO GO BACK TO USER MANAGEMENT";
            cin.ignore();
            cin.get();
            usermanagement();
            break;

        case 5:
            adminmenu();
            break;
    }
}


void displayusers() {
    ifstream file("Credentials.txt");

    char* buffer = allocateBufferForLongestLine("Credentials.txt");
    if (buffer == nullptr) {
        return;
    }

    while (file.getline(buffer, 500)) {
        char username[50], password[50], role[2], securityQ1[50], securityQ2[50], securityQ3[50];
        char firstname[50], lastname[50], dob[50], phoneno[50];
        
        int i = 0, j = 0;

        //username
        while (buffer[i] != ',' && buffer[i] != '\0') {
            username[j++] = buffer[i++];
        }
        username[j] = '\0'; i++; j = 0;

        // Decrypt the username
        caesarCipherDecrypt(username, 3);

        //password
        while (buffer[i] != ',' && buffer[i] != '\0') {
            password[j++] = buffer[i++];
        }
        password[j] = '\0'; i++; j = 0;

        caesarCipherDecrypt(password, 3);

        //role
        while (buffer[i] != ',' && buffer[i] != '\0') {
            role[j++] = buffer[i++];
        }
        role[j] = '\0'; i++; j = 0;

        //security question answers
        while (buffer[i] != ',' && buffer[i] != '\0') {
            securityQ1[j++] = buffer[i++];
        }
        securityQ1[j] = '\0'; i++; j = 0;
        
        while (buffer[i] != ',' && buffer[i] != '\0') {
            securityQ2[j++] = buffer[i++];
        }
        securityQ2[j] = '\0'; i++; j = 0;

        while (buffer[i] != ',' && buffer[i] != '\0') {
            securityQ3[j++] = buffer[i++];
        }
        securityQ3[j] = '\0'; i++; j = 0;

        //first name
        while (buffer[i] != ',' && buffer[i] != '\0') {
            firstname[j++] = buffer[i++];
        }
        firstname[j] = '\0'; i++; j = 0;

        //last name
        while (buffer[i] != ',' && buffer[i] != '\0') {
            lastname[j++] = buffer[i++];
        }
        lastname[j] = '\0'; i++; j = 0;

        //date of birth
        while (buffer[i] != ',' && buffer[i] != '\0') {
            dob[j++] = buffer[i++];
        }
        dob[j] = '\0'; i++; j = 0;

        //phone number
        while (buffer[i] != ',' && buffer[i] != '\0') {
            phoneno[j++] = buffer[i++];
        }
        phoneno[j] = '\0'; i++; j = 0;

        //SAARA DATA LINE-BY-LINE READ KAR KAA ADMIN KOO DISPLAY KARWAA DIYAA.
        cout << "-------------------------------\n";
        cout << "USERNAME: " << username << endl;
        cout << "PASSWORD: " << password << endl;
        cout << "ROLE: " << role << endl;
        cout << "Security Question 1: " << securityQ1 << endl;
        cout << "Security Question 2: " << securityQ2 << endl;
        cout << "Security Question 3: " << securityQ3 << endl;
        cout << "FIRST NAME: " << firstname << endl;
        cout << "LAST NAME: " << lastname << endl;
        cout << "DATE OF BIRTH: " << dob << endl;
        cout << "PHONE NUMBER: " << phoneno << endl;
        cout << "-------------------------------\n\n";
    }
    logactivity("COMPLETE DETAILS OF EVERY ACCOUNT CHECKED BY ADMIN");
    delete[] buffer;
    file.close();
}



void removeuser(){
    cout << "-------------------------------\n";
    cout << "          REMOVE USER          \n";
    cout << "-------------------------------\n";
    cout << "ENTER THE USERNAME OF THE USER YOU WANT TO REMOVE : ";
    char username[50];
    cin.ignore();

    do {
        cin.getline(username, 50);
        if (!usernameExists(username)) {
            cout << "USERNAME INVALID! TRY AGAIN.\n";
        }
    } while (!usernameExists(username));

    ifstream file("Credentials.txt");
    ofstream tempFile("Temp.txt");

    char* buffer = allocateBufferForLongestLine("Credentials.txt");
    if (buffer == nullptr) {
        return;
    }
    while (file.getline(buffer, 500)) {
        char currentUsername[50];
        int i = 0, j = 0;

        //username
        while (buffer[i] != ',' && buffer[i] != '\0') {
            currentUsername[j++] = buffer[i++];
        }
        currentUsername[j] = '\0';

        caesarCipherDecrypt(currentUsername, 3);

        //username yahan par hii check kar lein gaa
        if (!stringcomparison(currentUsername, username)) {
            tempFile << buffer << endl;
        }
    }
    file.close();
    tempFile.close();

    remove("Credentials.txt");
    rename("Temp.txt", "Credentials.txt");

    logactivity("EXISTING USER DELETED");
    delete[] buffer;
    cout << "USER REMOVED SUCCESSFULLY.\n";
}


void editexistinguser() {
    cout << "-------------------------------\n";
    cout << "          Edit Existing User          \n";
    cout << "-------------------------------\n";
    cout << "ENTER THE USERNAME OF THE USER YOU WANT TO EDIT: ";
    char username[50];
    cin.ignore();
    do {
        cin.getline(username, 50);
        if(!usernameExists(username)){
            cout<<"USERNAME INVALID! TRY AGAIN.\n";
        }
    } while (!usernameExists(username));

        cout << "\n\n------------------------------------------" << endl;
        cout << "| 1. CHANGE USERNAME                     |" << endl;
        cout << "| 2. CHANGE PASSWORD                     |" << endl;
        cout << "| 3. CHANGE ROLE                         |" << endl;
        cout << "| 4. RETURN TO USER MANAGEMENT           |" << endl;
        cout << "------------------------------------------" << endl;

    int choice;
    do{
        cin>>choice;
        if (cin.fail()){
            cout << "Invalid input! ENTER A NUMBER 1 TO 4.\n";
            cin.clear();
            cin.ignore(200, '\n');
            choice = 0;
        }else if (choice < 1 || choice > 4){
                cout<<"Invalid choice! ENTER A NUMBER 1 TO 4.\n";
        }}while(choice>4 || choice<1);

    switch (choice) {
        case 1:
            changeusername(username);
            cout<<"PRESS ANY KEY TO GO BACK TO ACCOUNT MANAGEMENT";
            cin.ignore();
            cin.get();
            editexistinguser();
            break;
        case 2:
            changepassword(username);
            cout<<"PRESS ANY KEY TO GO BACK TO ACCOUNT MANAGEMENT";
            cin.ignore();
            cin.get();
            editexistinguser();
            break;
        case 3:
            changerole(username);
            cout<<"PRESS ANY KEY TO GO BACK TO ACCOUNT MANAGEMENT";
            cin.ignore();
            cin.get();
            editexistinguser();
            break;
        case 4:
            cout << "RETURNING TO USER MANAGEMENT\n";
            usermanagement();
            break;
    }
}

void changerole(char username[]) {
    cout << "ENTER THE NEW ROLE (C for Customer, E for Employee, A for Admin): ";
    char newRole;
    do {
        cin >> newRole;
        newRole = toupper(newRole); //UPPERCASE CONVERSION
        if (newRole != 'C' && newRole != 'E' && newRole != 'A') {
            cout << "INVALID ROLE. PLEASE ENTER 'C', 'E', OR 'A': ";
        }
    } while (newRole != 'C' && newRole != 'E' && newRole != 'A');

    ifstream file("Credentials.txt");
    ofstream tempFile("Temp.txt");

    char* buffer = allocateBufferForLongestLine("Credentials.txt");
    if (buffer == nullptr) {
        return;
    }

    while (file.getline(buffer, 500)) {
        char currentUsername[50];
        int i = 0, j = 0;

        while (buffer[i] != ',' && buffer[i] != '\0') {
            currentUsername[j++] = buffer[i++];
        }
        currentUsername[j] = '\0'; i++; j = 0;

        caesarCipherDecrypt(currentUsername, 3);

        if (stringcomparison(currentUsername, username)) {

            while (buffer[i] != ',' && buffer[i] != '\0') tempFile << buffer[i++];
            tempFile << ",";
            i++;

            while (buffer[i] != ',' && buffer[i] != '\0') tempFile << buffer[i++];
            tempFile << ",";
            i++;

            tempFile << newRole;

            bool firstField = true;
            while (buffer[i] != '\0') {
                if (buffer[i] == ',' && !firstField) {
                    tempFile << buffer[i++];
                    continue;
                }
                if (buffer[i] != ',') {
                    tempFile << buffer[i++];
                    firstField = false;
                }
                if (buffer[i] == ',' && firstField) {
                    tempFile << buffer[i++];
                }
            }
            tempFile << endl;
        } else {
            tempFile << buffer << endl;
        }
    }

    file.close();
    tempFile.close();
    remove("Credentials.txt");
    rename("Temp.txt", "Credentials.txt");

    delete[] buffer;
    logactivity("ROLE CHANGED OF EXISTING USER");
    cout << "ROLE UPDATED SUCCESSFULLY.\n";
}



void changeusername(char oldUsername[]) {
    cout << "ENTER THE NEW USERNAME: ";
    char newUsername[50];
    cin.ignore();
    cin.getline(newUsername, 50);

    if (usernameExists(newUsername)) {
        cout << "ERROR: USERNAME ALREADY EXISTS. PLEASE CHOOSE A DIFFERENT ONE.\n";
        return;
    }

    ifstream file("Credentials.txt");
    ofstream tempFile("Temp.txt");

    char* buffer = allocateBufferForLongestLine("Credentials.txt");
    if (buffer == nullptr) {
        return;
    }
    while (file.getline(buffer, 500)) {
        char currentUsername[50];
        int i = 0, j = 0;

        //username
        while (buffer[i] != ',' && buffer[i] != '\0') {
            currentUsername[j++] = buffer[i++];
        }
        currentUsername[j] = '\0';
        caesarCipherDecrypt(currentUsername, 3);

        //YAHAN PAR COMPARE KAR LEIN GAA.
        if (stringcomparison(currentUsername, oldUsername)) {
            //COMPARE HOO GYAA TUU NEW WALA WRITE KAR DEIN GAA
            caesarCipherEncrypt(newUsername, 3);
            tempFile << newUsername;
            while (buffer[i] != '\0') {
                tempFile << buffer[i++];
            }
            tempFile << endl;
        } else {
            tempFile << buffer << endl;
        }
    }

    file.close();
    tempFile.close();
    remove("Credentials.txt");
    rename("Temp.txt", "Credentials.txt");
    delete[] buffer;

    logactivity("USERNAME UPDATED OF EXISTING USER");
    cout << "USERNAME UPDATED SUCCESSFULLY.\n";
}

void changepassword(char username[]) {
    cout << "ENTER THE NEW PASSWORD: ";
    char newPassword[50];
    cin.ignore();
    cin.getline(newPassword, 50);

    ifstream file("Credentials.txt");
    ofstream tempFile("Temp.txt");

    char* buffer = allocateBufferForLongestLine("Credentials.txt");
    if (buffer == nullptr) {
        return;
    }
    while (file.getline(buffer, 500)) {
        char currentUsername[50];
        int i = 0, j = 0;

        //username
        while (buffer[i] != ',' && buffer[i] != '\0') {
            currentUsername[j++] = buffer[i++];
        }
        currentUsername[j] = '\0';

        caesarCipherDecrypt(currentUsername, 3);
        
    
        //PEHLE USERNAME COMPARE KAREIN GAA, PHIR USS USERNAME KAA AGAA PASSWORD KOO DEKHEIN GAA
        if (stringcomparison(currentUsername, username)) {
            caesarCipherEncrypt(currentUsername, 3);
            caesarCipherEncrypt(newPassword, 3);
            tempFile << currentUsername << "," << newPassword; //TEMP FILE MAII PUARANA KII JAGAH NEW WALA WRITE HOO JAYEE GAA
            while (buffer[i] != ',' && buffer[i] != '\0') i++;
            while (buffer[i] != '\0') tempFile << buffer[i++];
            tempFile << endl;
        } else {
            tempFile << buffer << endl;
        }
    }

    file.close();
    tempFile.close();
    remove("Credentials.txt");
    rename("Temp.txt", "Credentials.txt");
    delete[] buffer;

    logactivity("PASSWORD CHANGED FOR AN EXISTING USER");
    cout << "PASSWORD UPDATED SUCCESSFULLY.\n";
}




void addnewuser() {
    cout << " ___________________________________________\n";
    cout << "|                                           |\n";
    cout << "|             ADD NEW USER                  |\n";
    cout << "|                                           |\n";
    cout << "|___________________________________________|\n";
    cout << "|                                           |\n";
    cout << "| 1. ADD NEW CUSTOMER                       |\n";
    cout << "| 2. ADD NEW EMPLOYEE                       |\n";
    cout << "| 3. ADD NEW ADMIN                          |\n";
    cout << "| 4. BACK TO USER MANAGEMENT                |\n";
    cout << "|___________________________________________|\n";
    int choice;
    do {
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "INVALID INPUT! ENTER A NUMBER 1 TO 4.\n";
            choice = 0;
        } else if (choice < 1 || choice > 4) {
            cout << "INVALID CHOICE! ENTER A NUMBER 1 TO 4.\n";
        }
    } while (choice > 4 || choice < 1);

    char role;
    switch (choice) {
        case 1: role = 'C'; break;
        case 2: role = 'E'; break;
        case 3: role = 'A'; break;
        case 4: usermanagement(); return;
    }

    char firstname[50], lastname[50], dateofbirth[50], username[50], password[50], confirmpass[50], phoneno[20], securityQ1[50], securityQ2[50], securityQ3[50];
    cout << "ENTER YOUR FIRST NAME: ";
    cin.ignore();
    cin.getline(firstname, 50);

    cout << "ENTER YOUR LAST NAME: ";
    cin.getline(lastname, 50);

    cout << "ENTER YOUR DATE OF BIRTH IN DD/MM/YYYY FORMAT: ";
    cin.getline(dateofbirth, 50);

    do {
        cout << "ENTER YOUR PHONE NUMBER ALONG WITH COUNTRY CODE (+923091512006): ";
        cin.getline(phoneno, 20);
        if (!isValidPhoneNumber(phoneno)) {
            cout << "INVALID PHONE NUMBER! PLEASE ENTER A VALID ONE.\n";
        } else {
            break;
        }
    } while (true);

    do {
        cout << "ENTER YOUR USERNAME: ";
        cin.getline(username, 50);
        if (usernameExists(username)) {
            cout << "USERNAME ALREADY EXISTS. PLEASE CHOOSE A DIFFERENT ONE.\n";
        } else {
            break;
        }
    } while (true);

againpass:
    cout << "ENTER YOUR PASSWORD: ";
    cin.getline(password, 50);
    if (!isValidPassword(password)) {
        cout << "WEAK PASSWORD! PLEASE TRY AGAIN.\n";
        goto againpass;
    }

    cout << "CONFIRM YOUR PASSWORD: ";
    cin.getline(confirmpass, 50);
    if (!stringcomparison(password, confirmpass)) {
        cout << "PASSWORDS DO NOT MATCH. PLEASE TRY AGAIN.\n";
        goto againpass;
    }

    cout << "REGISTRATION SUCCESSFUL\n";
    cout << "NOW ANSWER SECURITY QUESTIONS:\n";

    cout << "WHAT IS YOUR FAVORITE COLOR? ";
    cin.getline(securityQ1, 50);

    cout << "WHAT IS THE NAME OF YOUR HOMETOWN? ";
    cin.getline(securityQ2, 50);

    cout << "WHAT IS YOUR FAVORITE FOOD? ";
    cin.getline(securityQ3, 50);

    caesarCipherEncrypt(username, 3);
    caesarCipherEncrypt(password, 3);

    ofstream file("Credentials.txt", ios::app);
    if (file.is_open()) {
        file << username << "," << password << "," << role << ","
             << securityQ1 << "," << securityQ2 << "," << securityQ3 << ","
             << firstname << "," << lastname << "," << dateofbirth << ","
             << phoneno << "\n";
        file.close();
    } else {
        cout << "ERROR: SERVER MAINTENANCE. TRY AGAIN LATER.\n";
        return;
    }

    logactivity(role == 'A' ? "ADMIN ACCOUNT CREATED" :
                role == 'E' ? "EMPLOYEE ACCOUNT CREATED" :
                              "CUSTOMER ACCOUNT CREATED");
    cout << "ACCOUNT CREATED SUCCESSFULLY. RETURNING TO MAIN MENU.\n";
    cin.get();
    usermanagement();
}


bool isValidPhoneNumber(const char* phone) {
    int length = strlen(phone);
    return length >= 10 && length <= 15 && phone[0] == '+' && isdigit(phone[1]);
}

bool isValidPassword(const char* password) {
    int length = strlen(password);
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) hasUpper = true;
        if (islower(password[i])) hasLower = true;
        if (isdigit(password[i])) hasDigit = true;
        if (ispunct(password[i])) hasSpecial = true;
    }

    return length >= 8 && hasUpper && hasLower && hasDigit && hasSpecial;
}



