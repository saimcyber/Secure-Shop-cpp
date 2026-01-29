#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include"basicfunctionalities.h"
using namespace std;


char checkcredentials(char[], char[]);
bool usernameExists(const char* username);
void forgotpassword(char[]);

void customermenu();
void productbrowsingandsearch();
void searchproduct(char[]);
void addtocart();
bool isProductInCart(char []);
void increaseProductQuantity(char []);
void displayCartSummary();
void displayallproducts();

void cartmanagement();
void displaycart();
void removeitems();
void clearcart();

void purchaseandcheckout();
void paymentdone(char []);
void Promocode(char []);


void wishlist();
void addproducttowishlist(char[]);
void removeproductwishlist(char[]);
void displayallwishlist(char[]);
void clearwishlist(char []);

void orderhistoryandfeedback();
void vieworderhistory(char []);
void deleteorderhistory(char []);
void feedback(char []);

void supportrequests();

void viewannouncement();



//---------------------------------------------------------------------REAL FUN STARTS--------------------------------------------------

void customermenu(){
        setColor(4);
        cout << "\t \t   *************************************************\n";
        cout << "\t \t   *               CUSTOMER MENU                    *\n";
        cout << "\t \t   *************************************************\n";
        resetColor();
        setColor(1);
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   1-->  PRODUCT BROWSING AND SEARCH                      |" << endl;
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   2-->  CART MANAGEMENT                                  |" << endl;
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   3-->  PURCHASE AND CHECKOUT                            |" << endl;
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   4-->  WISHLIST                                         |" << endl;
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   5-->  ORDER HISTORY AND FEEDBCK                        |" << endl;
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   6-->  SUPPORT REQUESTS                                 |" << endl;
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   7-->  VIEW ANOUNCEMENTS                                |" << endl;
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   8-->  EXIT                                             |" << endl;
        cout << "\t \t----------------------------------------------------------" << endl;
        resetColor();
    int choice;
    do{
        cin>>choice;
        if (cin.fail()) {
            cout << "Invalid input! Please enter a number between 1 and 9.\n";
            cin.clear();
            cin.ignore(200, '\n');
            choice = 0;
        } else if (choice < 1 || choice > 9) {
            cout << "Invalid choice! Please select a valid option (1 to 9).\n";
        }
    }while(choice>9 || choice<1);

    switch(choice){
        case 1:
            productbrowsingandsearch();
            cout<<"PRESS ANY KEY TO GO BACK TO CUSTOMER MENU";
            cin.ignore();
            cin.get();
            customermenu();
        break;
        case 2:
            cartmanagement();
            cout<<"PRESS ANY KEY TO GO BACK TO CUSTOMER MENU";
            cin.ignore();
            cin.get();
            customermenu();
        break;
        case 3:
            purchaseandcheckout();
            cout<<"PRESS ANY KEY TO GO BACK TO CUSTOMER MENU";
            cin.ignore();
            cin.get();
            customermenu();
            
        break;
        case 4:
            wishlist();
            cout<<"PRESS ANY KEY TO GO BACK TO CUSTOMER MENU";
            cin.ignore();
            cin.get();
            customermenu();
            
        break;
        case 5:
            orderhistoryandfeedback();
            cout<<"PRESS ANY KEY TO GO BACK TO CUSTOMER MENU";
            cin.ignore();
            cin.get();
            customermenu();
            
        break;
        case 6:
            supportrequests();
            cout<<"PRESS ANY KEY TO GO BACK TO CUSTOMER MENU";
            cin.ignore();
            cin.get();
            customermenu();
            
        break;
        case 7:
            viewannouncement();
            cout<<"PRESS ANY KEY TO GO BACK TO CUSTOMER MENU";
            cin.ignore();
            cin.get();
            customermenu();
            
        break;
        case 8:
            cout << "\t\t\033[48;5;196m************ GOOBYE CUSTOMER! ************\033[0m\n";
            cout << "\t\t\033[48;5;30m************ We Wish to See You Again! *********\033[0m\n\n";
            cin.ignore();
            exit;
        break;
    }
}

void viewannouncement() {
    cout << "---------------------------------------\n";
    cout << "          VIEW ANNOUNCEMENTS\n";
    cout << "---------------------------------------\n";
    ifstream file("Announcement.txt");
    char line[200];
    bool found = false;

    while (file.getline(line, 200)) {
        found = true;
        cout << line << endl;
    }
    if (!found) {
        cout << "No announcements found.\n";
    }
    file.close();
}

void supportrequests(){
        cout << "\n\n------------------------------------------" << endl;
        cout << "|           SUPPORT REQUESTS             |" << endl;
        cout << "|----------------------------------------|" << endl;
        cout << "| 1. VIEW YOUR REQUESTS                  |" << endl;
        cout << "| 2. REQUEST HELP                        |" << endl;
        cout << "| 3. BACK TO CUSTOMER MENU               |" << endl;
        cout << "------------------------------------------" << endl;
    int choice;
    do {
        cout << "ENTER YOUR CHOICE (1 TO 3): ";
        cin >> choice;
        if (cin.fail()) {
            cout << "Invalid input! Please enter a number between 1 and 3.\n";
            cin.clear();
            cin.ignore(200, '\n');
            choice = 0;
        } else if (choice < 1 || choice > 4) {
            cout << "Invalid choice! Please select a valid option (1 to 3).\n";
        }
    }while(choice < 1 || choice > 3);
    char username[50];
    for(int i = 0; i < 50; i++){
    username[i] = '\0';
    }
    do{
    cout<<"PLEASE ENTER YOUR USERNAME BEFORE REQUESTING SUPPORT : ";
    cin>>username;
    }while(!usernameExists(username));

    if (choice == 1){
    cout << "----------------------------------\n";
    cout << "    VIEW REQUESTS\n";
    cout << "----------------------------------\n";

    ifstream supportFile("support.txt");

    char* buffer = allocateBufferForLongestLine("support.txt");
    if (buffer == nullptr) {
        return;
    }
    char fileUsername[50];
    char issueLine[200];
    bool requestFound = false;

    while (supportFile.getline(buffer, 200)) {
        // Humme ptaa haii kaa support request maii real suername kaa peeche yee wala format haii tuu uss koo hum predefine kar dete hain "Username:"
        if (buffer[0] == 'U' && buffer[1] == 's' && buffer[2] == 'e' && buffer[3] == 'r' &&
            buffer[4] == 'n' && buffer[5] == 'a' && buffer[6] == 'm' && buffer[7] == 'e' &&
            buffer[8] == ':' && buffer[9] == ' ') {
            
            // AB REAL USERNAME NIKAL JAYEE GAA
            int i = 10, j = 0;
            while (buffer[i] != '\0') {
                fileUsername[j++] = buffer[i++];
            }
            fileUsername[j] = '\0';

            if (stringcomparison(username, fileUsername)) {
                requestFound = true;

                cout << buffer << endl; // Display the username
                if (supportFile.getline(issueLine, 200)) {
                    cout << issueLine << endl; // Display the issue
                }
                cout << "-------------------------------------" << endl;
            }
        }
    }

    supportFile.close();

    if (!requestFound) {
        cout << "NO SUPPORT REQUEST FOUND FOR THE GIVEN USERNAME.\n";
    }
    delete[] buffer;
    cout << "----------------------------------\n";
}
else if(choice==2){
    char issue[200];
    cout << "Enter the issue you are facing (max 200 characters): ";
    cin.ignore();
    cin.getline(issue, 200);

    ofstream supportFile("support.txt", ios::app);

    supportFile << "Username: " << username << endl;
    supportFile << "Issue: " << issue << endl;
    supportFile << "Response: " << endl; //YAHAN PAR BAAAD MAI ADMIN YAA EMPLOYEE LIKH SAKTA HAII.
    supportFile << "-------------------------------------" << endl;

    supportFile.close();

    cout << "Your support request has been recorded successfully. Our team will get back to you shortly.\n";
    cout << "-------------------------------------\n";
}
}

void orderhistoryandfeedback(){
    cout<<"-------------------------------------\n";
    cout<<"   WELCOME TO ORDER HISTORY AND FEEDBACK!\n";
    cout<<"-------------------------------------\n";
    char username[50];
    for(int i = 0; i < 50; i++){
    username[i] = '\0';
    }
    do{
        cout<<"PLEASE ENTER YOUR USERNAME BEFORE ENTERING : ";
        cin>>username;
    }while(!usernameExists(username));

        cout << "------------------------------------------" << endl;
        cout << "| 1. VIEW YOUR ORDER HISTORY             |" << endl;
        cout << "| 2. DELETE YOUR ORDER HISTORY           |" << endl;
        cout << "| 3. GIVE FEEDBACK                       |" << endl;
        cout << "| 4. BACK TO CUSTOMER MENU               |" << endl;
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
    }while(choice < 1 || choice > 4);


        switch(choice){
            case 1:
                vieworderhistory(username);
                cout<<"PRESS ANY KEY TO GO BACK TO ORDER HISTORY \n";
                cout<<"-------------------------------------\n";
                cin.ignore();
                cin.get();
                orderhistoryandfeedback();
            break;

            case 2:
                deleteorderhistory(username);
                cout<<"PRESS ANY KEY TO GO BACK TO ORDER HISTORY \n";
                cout<<"-------------------------------------\n";
                cin.ignore();
                cin.get();
                orderhistoryandfeedback();
            break;

            case 3:
                feedback(username);
                cout<<"PRESS ANY KEY TO GO BACK TO ORDER HISTORY \n";
                cout<<"-------------------------------------\n";
                cin.ignore();
                cin.get();
                orderhistoryandfeedback();
            break;

            case 4:
                customermenu();
            break;
        }
}


void feedback(char username[]) {
    cout << "-------------------------------------\n";
    cout << "         GIVE FEEDBACK\n";
    cout << "-------------------------------------\n";

    char productID[10], userFeedback[200];

    cout << "Enter the Product ID for which you want to give feedback: ";
    cin >> productID;
    bool valid;

    do{
    valid = true;
    cout << "ENTER THE PRODUCT ID YOU WANT TO DELETE: ";
    cin >> productID;
    for (int i = 0; productID[i] != '\0'; i++) {
        if (productID[i] < '0' || productID[i] > '9') {
            valid = false;
            break;
        }
    }
    if (!valid) {
        cout << "Invalid input! PRODUCT ID MUST CONTAIN DIGITS ONLY.\n";
    }}while(!valid);

    cout << "Enter your feedback (max 200 characters): ";
    cin.ignore();
    cin.getline(userFeedback, 200);

    ofstream feedbackFile("feedback.txt", ios::app);

    feedbackFile << "Username: " << username << endl;
    feedbackFile << "Product ID: " << productID << endl;
    feedbackFile << "Feedback: " << userFeedback << endl;
    feedbackFile << "-------------------------------------" << endl;

    feedbackFile.close();

    cout << "Thank you for your feedback! It has been recorded successfully.\n";
    cout << "-------------------------------------\n";
}


void deleteorderhistory(char username[]) {
    cout << "-------------------------------------\n";
    cout << "   DELETE ORDER HISTORY\n";
    cout << "-------------------------------------\n";

    ifstream orderHistory("orderhistory.txt");
    ofstream tempFile("temp_orderhistory.txt");


    char* buffer = allocateBufferForLongestLine("orderhistory.txt");
    if (buffer == nullptr) {
        return;
    }
    char currentUsername[50];
    bool isUserOrder = false;

    while (orderHistory.getline(buffer, 200)) {
        //Humme ptaa haii kaa yee start "Username: " saa hotaa haiii. Isi liye hum uss koo predefine kar dete hain.
        if (buffer[0] == 'U' && buffer[1] == 's' && buffer[2] == 'e' && buffer[3] == 'r' &&
            buffer[4] == 'n' && buffer[5] == 'a' && buffer[6] == 'm' && buffer[7] == 'e' &&
            buffer[8] == ':' && buffer[9] == ' ') {
            
            //AB ASAL USERNAME START HOO JAYE GAA.
            int i = 10, j = 0;
            while (buffer[i] != '\0') {
                currentUsername[j++] = buffer[i++];
            }
            currentUsername[j] = '\0';
            trim(currentUsername);

            if (stringcomparison(currentUsername, username)) {
                isUserOrder = true; //AGR MIL GYAA TUU PHIR IS KAA DAYYYTTTTA CHOOR DOO
                continue;
            } else {
                isUserOrder = false;
            }
        }

        if (!isUserOrder) {
            tempFile << buffer << endl;
        }
    }

    orderHistory.close();
    tempFile.close();
    delete[] buffer; 

    remove("orderhistory.txt");
    rename("temp_orderhistory.txt", "orderhistory.txt");

    cout << "ALL RECORDS FOR USER '" << username << "' HAVE BEEN DELETED SUCCESSFULLY.\n";
    cout << "-------------------------------------\n";
}

void vieworderhistory(char username[50]) {
    cout << "-------------------------------------\n";
    cout << "   WELCOME TO VIEW ORDER HISTORY!\n";
    cout << "-------------------------------------\n";
    cout << "ORDER HISTORY FOR " << username << " IS AS FOLLOWS:\n";
    cout << "-------------------------------------\n";

    ifstream orderHistory("orderhistory.txt");

    char* buffer = allocateBufferForLongestLine("orderhistory.txt");
    if (buffer == nullptr) {
        return;
    }
    char currentUsername[50];
    bool isUserOrder = false;

    while (orderHistory.getline(buffer, 200)) {
        //Humme ptaa haii kaa yee start "Username: " saa hotaa haiii. Isi liye hum uss koo predefine kar dete hain.
        if (buffer[0] == 'U' && buffer[1] == 's' && buffer[2] == 'e' && buffer[3] == 'r' &&
            buffer[4] == 'n' && buffer[5] == 'a' && buffer[6] == 'm' && buffer[7] == 'e' &&
            buffer[8] == ':' && buffer[9] == ' ') {
            
            //username
            int i = 10, j = 0;
            while (buffer[i] != '\0') {
                currentUsername[j++] = buffer[i++];
            }
            currentUsername[j] = '\0';
            trim(currentUsername);

            if (stringcomparison(currentUsername, username)) {
                isUserOrder = true;
            } else if (isUserOrder) {
                break;
            } else {
                isUserOrder = false;
            }
        } else if (isUserOrder) {
            //End saaa "Order End" kooo bhii skip kar dein gaaa.
            if (buffer[0] != 'O' || buffer[1] != 'r' || buffer[2] != 'd' || buffer[3] != 'e' ||
                buffer[4] != 'r' || buffer[5] != ' ' || buffer[6] != 'E' || buffer[7] != 'n' || buffer[8] != 'd') {
                cout << buffer << endl;
            }
        }
    }

    if (!isUserOrder) {
        cout << "NO ORDER HISTORY FOUND FOR USER: " << username << endl;
    }

    cout << "-------------------------------------\n";
    delete[] buffer;
    orderHistory.close();
}


void wishlist(){
        cout << "------------------------------------------" << endl;
        cout << "|           WISHLIST MENU                |" << endl;
        cout << "------------------------------------------" << endl;
    char username[50];
    for(int i = 0; i < 50; i++){
        username[i] = '\0';
    }

    do{
    cout<<"PLEASE ENTER YOUR USERNAME BEFORE ENTERING : ";
    cin>>username;
    }while(!usernameExists(username));

        cout << "------------------------------------------" << endl;
        cout << "| 1. ADD PRODUCT TO WISHLIST             |" << endl;
        cout << "| 2. REMOVE PRODUCT FROM WISHLIST        |" << endl;
        cout << "| 3. VIEW WISHLIST                       |" << endl;
        cout << "| 4. CLEAR WISHLIST                      |" << endl;
        cout << "| 5. BACK TO CUSTOMER MENU               |" << endl;
        cout << "------------------------------------------" << endl;
    int choice;
    do{
        cout << "ENTER YOUR CHOICE (1 TO 5): ";
        cin >> choice;
        if (cin.fail()) {
            cout << "Invalid input! Please enter a number between 1 and 5.\n";
            cin.clear();
            cin.ignore(200, '\n');
            choice = 0;
        }else if(choice < 1 || choice > 5) {
            cout << "Invalid choice! Please select a valid option (1 to 5).\n";
        }
    }while(choice < 1 || choice > 5);

        switch(choice){
            case 1:
                addproducttowishlist(username);
                cout<<"PRESS ANY KEY TO GO BACK TO WISHLIST \n";
                cout<<"-------------------------------------\n";
                cin.ignore();
                cin.get();
                wishlist();
            break;

            case 2:
                removeproductwishlist(username);
                cout<<"PRESS ANY KEY TO GO BACK TO WISHLIST \n";
                cout<<"-------------------------------------\n";
                cin.ignore();
                cin.get();
                wishlist();
            break;

            case 3:
                displayallwishlist(username);
                cout<<"PRESS ANY KEY TO GO BACK TO WISHLIST \n";
                cout<<"-------------------------------------\n";
                cin.ignore();
                cin.get();
                wishlist();
            break;

            case 4:
                clearwishlist(username);
                cout<<"PRESS ANY KEY TO GO BACK TO WISHLIST \n";
                cout<<"-------------------------------------\n";
                cin.ignore();
                cin.get();
                wishlist();
            break;
            
            case 5:
                customermenu();
            break;
        }

}



void clearwishlist(char username[50]) {
    cout << "Clearing wishlist for user: " << username << "\n";
    cout << "-------------------------------------\n";

    char wishlistUsername[50];
    bool userExists = false;

    ofstream tempWishlist("temp_wishlist.txt");

    ifstream wishlist("wishlist.txt");
    char* buffer = allocateBufferForLongestLine("wishlist.txt");
    if (buffer == nullptr) {
        return;
    }

    while (wishlist.getline(buffer, 200)) {
        int i = 0, j = 0;

        while (buffer[i] != '\0' && buffer[i] != '\n' && buffer[i] != '|') {
            wishlistUsername[j++] = buffer[i++];
        }
        wishlistUsername[j] = '\0';

        trim(wishlistUsername);

        if (stringcomparison(username, wishlistUsername)) {
            userExists = true;
            continue;
        }
        tempWishlist << buffer << endl;
    }

    wishlist.close();
    tempWishlist.close();
    delete[] buffer;

    if (userExists) {
        remove("wishlist.txt");
        rename("temp_wishlist.txt", "wishlist.txt");
        cout << "WISHLIST CLEARED FOR USER SUCCESSFULLY!\n";
    } else {
        cout << "ERROR: USERNAME NOT FOUND IN WISHLIST.\n";
    }
}


void displayallwishlist(char username[]) {
    cout << "Displaying all products in the wishlist for user: " << username << "\n";
    cout << "-------------------------------------\n";

    char wishlistUsername[50], fileProductID[50], fileName[50], fileCategory[50], fileQuantity[50], filePrice[50];
    bool userExists = false;

    ifstream wishlist("wishlist.txt");
    char* buffer = allocateBufferForLongestLine("wishlist.txt");
    if (buffer == nullptr) {
        return;
    }

    while (wishlist.getline(buffer, 200)) {
        int i = 0, j = 0;

        while (buffer[i] != '\0' && buffer[i] != '\n' && buffer[i] != '|') {
            wishlistUsername[j++] = buffer[i++];
        }
        wishlistUsername[j] = '\0';

        trim(wishlistUsername);

        if (stringcomparison(username, wishlistUsername)) {
            userExists = true;
            cout << "Wishlist for " << wishlistUsername << ":\n";
            cout << "-------------------------------------\n";

            while (wishlist.getline(buffer, 200)) {
                j = 0;
                i = 0;

                //ProductID
                while (buffer[i] != '|' && buffer[i] != '\0') {
                    fileProductID[j++] = buffer[i++];
                }
                fileProductID[j] = '\0';
                i++;

                j = 0;
                while (buffer[i] != '|' && buffer[i] != '\0') {
                    fileName[j++] = buffer[i++];
                }
                fileName[j] = '\0';
                i++;

                j = 0;
                while (buffer[i] != '|' && buffer[i] != '\0') {
                    fileCategory[j++] = buffer[i++];
                }
                fileCategory[j] = '\0';
                i++;

                j = 0;
                while (buffer[i] != '|' && buffer[i] != '\0') {
                    fileQuantity[j++] = buffer[i++];
                }
                fileQuantity[j] = '\0';
                i++;

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

                cout << "Product ID: " << fileProductID << " | " << "Name: " << fileName
                     << " | " << "Category: " << fileCategory << " | "
                     << "Quantity: " << fileQuantity << " | " << "Price: " << filePrice << "\n";
            }
            break;
        }
    }
    wishlist.close();
    delete[] buffer;

    if (!userExists) {
        cout << "ERROR: USERNAME NOT FOUND IN WISHLIST.\n";
    }
}

void removeproductwishlist(char username[]) {
    char pid[5];
    bool valid;

    do{
    valid = true;
    cout << "ENTER THE PRODUCT ID YOU WANT TO DELETE: ";
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
    cout << "-------------------------------------\n";

    char wishlistUsername[50], fileProductID[50], fileName[50], fileCategory[50], fileQuantity[50], filePrice[50];
    bool found = false, userExists = false;
    char* buffer = allocateBufferForLongestLine("wishlist.txt");
    if (buffer == nullptr) {
        return;
    }

    ofstream tempWishlist("temp_wishlist.txt");

    ifstream wishlist("wishlist.txt");

    while (wishlist.getline(buffer, 200)) {
        int i = 0, j = 0;

        //username
        while (buffer[i] != '\0' && buffer[i] != '\n' && buffer[i] != '|') {
            wishlistUsername[j++] = buffer[i++];
        }
        wishlistUsername[j] = '\0';

        // Trim the username
        trim(wishlistUsername);

        //USERNAME MIL GYAA HAII TUU AB PRODUCTS NIKALTA HAIN
        if (stringcomparison(username, wishlistUsername)) {
            userExists = true;
            tempWishlist << wishlistUsername << "\n";

            //Reading the product details
            while (wishlist.getline(buffer, 200)) {
                j = 0;
                i = 0;
                //ProductID
                while (buffer[i] != '|' && buffer[i] != '\0') {
                    fileProductID[j++] = buffer[i++];
                }
                fileProductID[j] = '\0';
                i++;

                j = 0;
                while (buffer[i] != '|' && buffer[i] != '\0') {
                    fileName[j++] = buffer[i++];
                }
                fileName[j] = '\0';
                i++;

                j = 0;
                while (buffer[i] != '|' && buffer[i] != '\0') {
                    fileCategory[j++] = buffer[i++];
                }
                fileCategory[j] = '\0';
                i++;

                j = 0;
                while (buffer[i] != '|' && buffer[i] != '\0') {
                    fileQuantity[j++] = buffer[i++];
                }
                fileQuantity[j] = '\0';
                i++;

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

                if (stringcomparison(pid, fileProductID)) {
                    found = true;
                    continue; //AGR MATCH KAR JAATI HAII TUU PHIR USS KAAA SAARA DAYTAAA REHNE DOO
                }

                tempWishlist << fileProductID << " | " << fileName << " | " << fileCategory
                             << " | " << fileQuantity << " | " << filePrice << endl;
            }
        } else {
            tempWishlist << buffer << endl;
        }
    }

    wishlist.close();
    tempWishlist.close();

    if (userExists && found) {
        remove("wishlist.txt");
        rename("temp_wishlist.txt", "wishlist.txt");
        cout << "PRODUCT REMOVED FROM WISHLIST SUCCESSFULLY!\n";
    } else if (!userExists) {
        cout << "ERROR: USERNAME NOT FOUND IN WISHLIST.\n";
    } else {
        cout << "ERROR: PRODUCT ID NOT FOUND IN YOUR WISHLIST.\n";
    }
    delete[] buffer;
    char choice;
    cout<<"YOU WANT TO REMOVE MORE PRODUCTS FROM YOUR WISHLIST? (y/n) ";
    cin>>choice;
    if(choice=='y' || choice=='Y'){
        removeproductwishlist(username);
    }
}


void addproducttowishlist(char username[50]) {
    char pid[5];
    bool valid;

    do{
    valid = true;
    cout << "ENTER THE PRODUCT ID YOU WANT TO ADD: ";
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
    cout << "-------------------------------------\n";

    char buffer[200], fileProductID[50], fileName[50], fileCategory[50], fileQuantity[50], filePrice[50];
    char wishlistBuffer[200], wishlistUsername[50];
    bool found = false, userExists = false;

    ifstream products("products.txt");

    while (products.getline(buffer, 200)) {
        int i = 0, j = 0;

        //ProductID
        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileProductID[j++] = buffer[i++];
        }
        fileProductID[j] = '\0';
        i++;

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

        if (stringcomparison(pid, fileProductID)) {
            found = true;

            fstream wishlist("wishlist.txt", ios::in | ios::out | ios::app);

            while (wishlist.getline(wishlistBuffer, 200)) {
                int k = 0;
                //username
                while (wishlistBuffer[k] != '\0' && wishlistBuffer[k] != '\n') {
                    wishlistUsername[k] = wishlistBuffer[k];
                    k++;
                }
                wishlistUsername[k] = '\0';

                trim(wishlistUsername);

                if (stringcomparison(username, wishlistUsername)) {
                    userExists = true;
                    break;
                }
            }

            if (!userExists) {
                // Add new user section if not present
                wishlist.clear();
                wishlist.seekp(0, ios::end);
                wishlist << username << "\n";
            }

            // Add product details under the user's section
            wishlist << fileProductID << " | " << fileName << " | " << fileCategory
                     << " | " << fileQuantity << " | " << filePrice << endl;

            wishlist.close();
            cout << "PRODUCT ADDED TO WISHLIST SUCCESSFULLY!\n";
            break;
        }
    }

    products.close();

    if (!found) {
        cout << "ERROR: PRODUCT ID NOT FOUND IN THE PRODUCTS LIST.\n";
    }
    
    char choice;
    cout<<"YOU WANT TO ADD MORE PRODUCTS TO YOUR WISHLIST? (y/n) ";
    cin>>choice;
    if(choice=='y' || choice=='Y'){
        addproducttowishlist(username);
    }
}


//-----------------------------------------------------------------------------------------------------------------------------


void purchaseandcheckout(){
        cout << "\n\n------------------------------------------" << endl;
        cout << "|          PURCHASE AND CHECKOUT         |" << endl;
        cout << "------------------------------------------" << endl;
    displayCartSummary();
    cout<<"DO YOU WANT TO APPLY ANY PROMOCODES?(Y/N)\n";
    char choice;
    cin>>choice;
    if(choice=='Y' || choice=='y'){
        char promocode[20];
        cin.ignore();
        cout<<"ENTER PROMOCODE: ";
        cin.getline(promocode, 20);
        Promocode(promocode);
    }
        cout << "|----------------------------------------|" << endl;
        cout << "| 1. PROCEED WITH PAYMENT                |" << endl;
        cout << "| 2. CANCEL ORDER                        |" << endl;
        cout << "| 3. BACK TO CUSTOMER MENU               |" << endl;
        cout << "------------------------------------------\n" << endl;
    int choice2;
    do{
        cout << "ENTER YOUR CHOICE (1 TO 3): ";
        cin >> choice2;
        if (cin.fail()) {
            cout << "Invalid input! Please enter a number between 1 and 3.\n";
            cin.clear();
            cin.ignore(200, '\n');
            choice2 = 0;
        }else if(choice2 < 1 || choice2 > 3) {
            cout << "Invalid choice! Please select a valid option (1 to 3).\n";
        }
    }while(choice2 < 1 || choice2 > 3);
    
    switch(choice2){
        case 1:
            char username[50];
            for(int i = 0; i < 50; i++){
            username[i] = '\0';
            }

            do{
            cout<<"PLEASE ENTER YOUR USERNAME TO CONFIRM YOUR ORDER : ";
            cin>>username;
            }while(!usernameExists(username));
            paymentdone(username);
            cout<<"YOU ORDER IS COMPLETED. THANKYOU FOR SHOPPING :)\n";
            cout<<"-------------------------------------\n\n";
            cout<<"PRESS ANY KEY TO GO BACK TO MAIN MENU \n";
            cin.ignore();
            cin.get();
            customermenu();
        break;

        case 2:
            clearcart();
            cout<<"YOU ORDER IS CANCELLED :(\n";
            cout<<"PRESS ANY KEY TO GO BACK TO MAIN MENU \n";
            cin.ignore();
            cin.get();
            customermenu();
            break;

        case 3:
            customermenu();
        break;
    }
}

void Promocode(char promocode[]) {
    ifstream promoFile("promocode.txt");
    char buffer[200], fileCode[50], fileType[50], fileThreshold[50], fileDiscount[50];
    bool promoApplied = false;
    float discount = 0.0, totalPrice = 0.0;
    int totalQuantity = 0;

    ifstream cart("cart.txt");
    char cartBuffer[200], fileQuantity[50], filePrice[50];
    
    while (cart.getline(cartBuffer, 200)) {
        int i = 0, j = 0;
        
        // Extracting quantity and price from cart (separated by '|')
        // Skip itemID
        while (cartBuffer[i] != '|' && cartBuffer[i] != '\0') i++; i++;  // Skip itemID and '|'
        // Skip itemName
        while (cartBuffer[i] != '|' && cartBuffer[i] != '\0') i++; i++;  // Skip itemName and '|'
        // Skip itemDescription
        while (cartBuffer[i] != '|' && cartBuffer[i] != '\0') i++; i++;  // Skip itemDescription and '|'
        
        //quantity
        j = 0;
        while (cartBuffer[i] != '|' && cartBuffer[i] != '\0') {
            fileQuantity[j++] = cartBuffer[i++];
        }
        fileQuantity[j] = '\0';
        i++;
        
        //price
        j = 0;
        while (cartBuffer[i] != '\0') {
            filePrice[j++] = cartBuffer[i++];
        }
        filePrice[j] = '\0';
        
        trim(fileQuantity);
        trim(filePrice);
        
        int quantity = atoi(fileQuantity);
        float price = atof(filePrice);
        
        totalQuantity += quantity;
        totalPrice += quantity * price;
    }
    cart.close();

    // Read the promocodes
    while (promoFile.getline(buffer, 200)) {
        int i = 0, j = 0;

        //promocode information
        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileType[j++] = buffer[i++];
        }
        fileType[j] = '\0';
        i++;

        j = 0;
        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileCode[j++] = buffer[i++];
        }
        fileCode[j] = '\0';
        i++;

        j = 0;
        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileThreshold[j++] = buffer[i++];
        }
        fileThreshold[j] = '\0';
        i++;

        j = 0;
        while (buffer[i] != '\0') {
            fileDiscount[j++] = buffer[i++];
        }
        fileDiscount[j] = '\0';

        trim(fileType);
        trim(fileCode);
        trim(fileThreshold);
        trim(fileDiscount);

        char amountBased[] = "Amount-Based";
        char quantityBased[] = "Quantity-Based";

        // Ensure matching between promocode and file
        if (stringcomparison(promocode, fileCode)) {

            if (stringcomparison(fileType, amountBased)) {
                if (totalPrice >= atof(fileThreshold)) {
                    discount = atof(fileDiscount);
                    discount = totalPrice*(discount/100);
                    totalPrice -= discount;  // Deduct the discount amount
                    promoApplied = true;
                }
            } else if (stringcomparison(fileType, quantityBased)) {
                if (totalQuantity >= atoi(fileThreshold)) {
                    discount = atof(fileDiscount);
                    discount = totalPrice*(discount/100);
                    totalPrice -= discount;  // Deduct the discount amount
                    promoApplied = true;
                }
            }
            break;
        }
    }

    promoFile.close();

    if (promoApplied) {
        cout << "\nPromocode applied successfully!\n";
    } else {
        cout << "\nPromocode not applicable.\n";
    }

    cout << "\033[1;36mTotal Quantity: \033[0m" << totalQuantity << endl;
    cout << "\033[1;36mTotal Amount after Discount: \033[0m" << totalPrice << endl;
}


void paymentdone(char username[50]) {
    ifstream cart("cart.txt");
    ifstream products("products.txt");
    ofstream temp("temp.txt");
    ofstream orderHistory("orderhistory.txt", ios::app);

    char cartBuffer[200], cartProductID[50], cartQuantity[50];
    char productBuffer[200], productProductID[50], productName[50], productCategory[50], productQuantity[50], productPrice[50];
    bool productUpdated;

    //YAHAN SAA ORDER HISTORY BNN JAYEE GII
    orderHistory << "Username: " << username << endl;
    orderHistory << "Order Start:\n";

    while (cart.getline(cartBuffer, 200)) {
        orderHistory << cartBuffer << endl;
    }

    orderHistory << "Order End\n\n";
    cart.clear();
    cart.seekg(0, ios::beg);


    while (products.getline(productBuffer, 200)) {
        productUpdated = false;
        int i = 0, j = 0;

        //ProductID
        while (productBuffer[i] != '|' && productBuffer[i] != '\0') {
            productProductID[j++] = productBuffer[i++];
        }
        productProductID[j] = '\0';
        i++;

        //Name
        j = 0;
        while (productBuffer[i] != '|' && productBuffer[i] != '\0') {
            productName[j++] = productBuffer[i++];
        }
        productName[j] = '\0';
        i++;

        //Category
        j = 0;
        while (productBuffer[i] != '|' && productBuffer[i] != '\0') {
            productCategory[j++] = productBuffer[i++];
        }
        productCategory[j] = '\0';
        i++;

        //Quantity
        j = 0;
        while (productBuffer[i] != '|' && productBuffer[i] != '\0') {
            productQuantity[j++] = productBuffer[i++];
        }
        productQuantity[j] = '\0';
        i++;

        //Price
        j = 0;
        while (productBuffer[i] != '\0') {
            productPrice[j++] = productBuffer[i++];
        }
        productPrice[j] = '\0';

        trim(productProductID);
        trim(productName);
        trim(productCategory);
        trim(productQuantity);
        trim(productPrice);

        // Reset cart file for each product
        cart.clear();
        cart.seekg(0, ios::beg);

        // Check if the current product matches any item in the cart
        while (cart.getline(cartBuffer, 200)) {
            int k = 0, l = 0;

            //Cart ProductID
            while (cartBuffer[k] != '|' && cartBuffer[k] != '\0') {
                cartProductID[l++] = cartBuffer[k++];
            }
            cartProductID[l] = '\0';
            k++;

            //Skip to Quantity
            while (cartBuffer[k] != '|' && cartBuffer[k] != '\0') k++;
            k++;
            while (cartBuffer[k] != '|' && cartBuffer[k] != '\0') k++;
            k++;
            l = 0;

            //Cart Quantity
            while (cartBuffer[k] != '|' && cartBuffer[k] != '\0') {
                cartQuantity[l++] = cartBuffer[k++];
            }
            cartQuantity[l] = '\0';

            trim(cartProductID);
            trim(cartQuantity);

            if (stringcomparison(cartProductID, productProductID)) {
                int updatedQuantity = atoi(productQuantity) - atoi(cartQuantity);
                if (updatedQuantity < 0) updatedQuantity = 0;

                temp << productProductID << " | " << productName << " | " << productCategory << " | "
                     << updatedQuantity << " | " << productPrice << endl;

                productUpdated = true;
                break;
            }
        }

        // If the product was not updated, write it as is
        if (!productUpdated) {
            temp << productProductID << " | " << productName << " | " << productCategory << " | "
                 << productQuantity << " | " << productPrice << endl;
        }
    }

    cart.close();
    products.close();
    temp.close();

    remove("products.txt");
    rename("temp.txt", "products.txt");

    ofstream clearCartFile("cart.txt", ios::trunc);
    clearCartFile.close();

    cout << "Payment completed and order history updated for user: " << username << endl;
}


void cartmanagement(){
        cout << "\n\n------------------------------------------" << endl;
        cout << "|             CART MANAGEMENT            |" << endl;
        cout << "|----------------------------------------|" << endl;
        cout << "| 1. VIEW CART                           |" << endl;
        cout << "| 2. ADD ITEMS TO CART                   |" << endl;
        cout << "| 3. REMOVE ITEMS FROM CART              |" << endl;
        cout << "| 4. CLEAR CART                          |" << endl;
        cout << "| 5. BACK TO CUSTOMER MENU               |" << endl;
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
            displaycart();
            cout<<"PRESS ANY KEY TO CONTINUE...\n";
            cin.ignore();
            cin.get();
            cartmanagement();
        break;
        case 2:
            productbrowsingandsearch();
        break;
        case 3:
            displaycart();
            removeitems();
            cartmanagement();
        break;
        case 4:
            clearcart();
            cartmanagement();
        break;
        case 5:
            customermenu();
        break;
    }
}

void clearcart() {
    ofstream cart("cart.txt", ios::trunc);
    if (cart.is_open()) {
        cout <<"All items have been removed from the cart.\n";
    } else {
        cout <<"ERROR: Could not clear the cart file.\n";
    }
    cart.close();
}

void removeitems(){
    cout<<"   REMOVE ITEM FROM CART\n";
    cout<<"-------------------------------------\n";
    char pid[5];
    char buffer[200], fileProductID[50], fileName[50], fileCategory[50], fileQuantity[50], filePrice[50];
    bool found = false;
    bool valid;

    do{
    valid = true;
    cout << "ENTER THE PRODUCT ID YOU WANT TO DELETE: ";
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

    ifstream cart("cart.txt");
    ofstream temp("temp.txt");

    while (cart.getline(buffer, 200)) {
        int i = 0, j = 0;

        //ProductID
        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileProductID[j++] = buffer[i++];
        }
        fileProductID[j] = '\0';
        i++;
        
        trim(fileProductID);

        if (stringcomparison(pid, fileProductID)) {
            found = true;  //AGR PRODUCT ID MATCH KAR GAYI TUU DAYTAA KOOO SKIP KAR DEE GAA
            continue;
        }

        j = 0;
        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileName[j++] = buffer[i++];
        }
        fileName[j] = '\0';
        i++;

        j = 0;
        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileCategory[j++] = buffer[i++];
        }
        fileCategory[j] = '\0';
        i++;

        j = 0;
        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileQuantity[j++] = buffer[i++];
        }
        fileQuantity[j] = '\0';
        i++;

        j = 0;
        while (buffer[i] != '\0') {
            filePrice[j++] = buffer[i++];
        }
        filePrice[j] = '\0';

        trim(fileName);
        trim(fileCategory);
        trim(fileQuantity);
        trim(filePrice);

        temp << fileProductID << " | " << fileName << " | " << fileCategory << " | "
             << fileQuantity << " | " << filePrice << endl;
    }

    if (found) {
        cout << "Product with ID " << pid << " has been removed from the cart." << endl;
    } else {
        cout << "No product with ID " << pid << " found in the cart." << endl;
    }
    cart.close();
    temp.close();

    remove("cart.txt");
    rename("temp.txt", "cart.txt");
}


void displaycart() {
    ifstream cart("cart.txt");
    char buffer[200], fileProductID[50], fileName[50], fileCategory[50], fileQuantity[50], filePrice[50];

    cout << "\n-------------------------------\n";
    cout << "         CART ITEMS\n";
    cout << "-------------------------------\n";

    while (cart.getline(buffer, 200)) {
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

        cout << "Product ID: " << fileProductID << " | "
             << "Name: " << fileName << " | "
             << "Category: " << fileCategory << " | "
             << "Quantity: " << fileQuantity << " | "
             << "Price: $" << filePrice << endl;
    }

    cout << "-------------------------------\n";
    cart.close();
}

void productbrowsingandsearch(){
        cout << "\n\n------------------------------------------" << endl;
        cout << "|      PRODUCT BROWSING AND SEARCH       |" << endl;
        cout << "|----------------------------------------|" << endl;
        cout << "| 1. SEARCH PRODUCT                      |" << endl;
        cout << "| 2. DISPLAY ALL PRODUCTS                |" << endl;
        cout << "| 3. BACK TO CUSTOMER MENU               |" << endl;
        cout << "------------------------------------------" << endl;
    
    int choice;
    do{
        cout << "ENTER YOUR CHOICE (1 TO 3): ";
        cin >> choice;
        if (cin.fail()) {
            cout << "Invalid input! Please enter a number between 1 and 3.\n";
            cin.clear();
            cin.ignore(200, '\n');
            choice = 0;
        }else if(choice < 1 || choice > 3) {
            cout << "Invalid choice! Please select a valid option (1 to 4).\n";
        }
    }while(choice < 1 || choice > 3);

    switch(choice){
        case 1:
            cout<<"\n-------------------------------\n";
            cout<<"   SEARCHING ANY PRODUCT?\n";
            cout<<"-------------------------------\n";
            char tobesearched[50];
            cout<<"ENTER PRODUCT NAME,CATEGORY,QUANTITIY,PRICE OR ANYTHING YOU KNOW ABOUT: \n";
            cin.ignore();
            cin.getline(tobesearched,50);
            cout<<"-------------------------------"<<endl;
            searchproduct(tobesearched);
        break;

        case 2:
            cout<<"\n-------------------------------\n";
            cout<<"   DISPLAYING ALL PRODUCTS\n";
            cout<<"-------------------------------\n";
            displayallproducts();
            cout<<"YOU WANT TO ADD ANY ITEM TO THE CART? PRESS 'Y' for Yes OR ANY OTHER CHARACTER TO GO BACK.\n";
            char choice2;
            cin >> choice2;
            if(choice2=='Y'||choice2=='y'){
                addtocart();
            }
            productbrowsingandsearch();
        break;

        case 3:
            customermenu();
        break;
    }

}

void displayallproducts(){
ifstream products("products.txt");
    char buffer[200], fileProductID[50], fileName[50], fileCategory[50], fileQuantity[50], filePrice[50];

    while (products.getline(buffer, 200)) {
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

        cout << "Product ID: " << fileProductID << " | "
             << "Name: " << fileName << " | "
             << "Category: " << fileCategory << " | "
             << "Quantity: " << fileQuantity << " | "
             << "Price: $" << filePrice << endl;
    }

    cout << "-------------------------------\n";
    products.close();
}

void searchproduct(char tobesearched[50]) {
    char buffer[200], fileProductID[50], fileName[50], fileCategory[50], fileQuantity[50], filePrice[50];
    bool found = false;

    ifstream products("products.txt");

    while (products.getline(buffer, 200)) {
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

        //IT WILL CHECK THE INPUT WITH EVERYTHING
        if (stringcomparison(tobesearched, fileProductID) ||
            stringcomparison(tobesearched, fileName) ||
            stringcomparison(tobesearched, fileCategory) ||
            stringcomparison(tobesearched, fileQuantity) ||
            stringcomparison(tobesearched, filePrice)) {
            cout << "MATCH FOUND: " << fileProductID << " | "
                 << fileName << " | "
                 << fileCategory << " | "
                 << fileQuantity << " | "
                 << filePrice << endl;
            found = true;
        }
    }
    cout<<"-------------------------------"<<endl;

    if (!found){
        cout << "NO MATCHES FOUND FOR '" << tobesearched << "' IN THE PRODUCTS FILE. TRY SOMETHING DIFFERENT :)" << endl;
    }
    products.close();

    cout<<"YOU WANT TO ADD ANY ITEM TO THE CART? PRESS 'Y' for Yes OR ANY OTHER CHARACTER TO GO BACK.\n";
    char choice2;
    cin >> choice2;
    if(choice2=='Y'||choice2=='y'){
        addtocart();
    }
    productbrowsingandsearch();  
}

void addtocart() {
    char pid[5];
    char buffer[200], fileProductID[50], fileName[50], fileCategory[50], fileQuantity[50], filePrice[50];
    bool found = false;
    bool valid;

    do{
    valid = true;
    cout << "ENTER THE PRODUCT ID YOU WANT TO ADD TO CART: ";
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

    ifstream products("products.txt");

    while (products.getline(buffer, 200)) {
        int i = 0, j = 0;

        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileProductID[j++] = buffer[i++];
        }
        fileProductID[j] = '\0';
        i++;

        j = 0;
        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileName[j++] = buffer[i++];
        }
        fileName[j] = '\0';
        i++;

        j = 0;
        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileCategory[j++] = buffer[i++];
        }
        fileCategory[j] = '\0';
        i++;

        j = 0;
        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileQuantity[j++] = buffer[i++];
        }
        fileQuantity[j] = '\0';
        i++; // Skip the pipe character

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

        if (stringcomparison(pid, fileProductID)) {
            cout << "ADDED TO CART: " << fileProductID << " | "
                 << fileName << " | "
                 << fileCategory << " | "
                 << fileQuantity << " | "
                 << filePrice << endl;

            // Open cart.txt in append mode to add the product to the cart
            ofstream cart("cart.txt", ios::app);
            if (cart.is_open()) {
                if (isProductInCart(fileProductID)) {
                    increaseProductQuantity(fileProductID);
                } else {
                    cart << fileProductID << " | " << fileName << " | " << fileCategory << " | "
                         << "1 | " << filePrice << endl;
                }
            } else {
                cout << "ERROR: Could not open cart.txt." << endl;
            }

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "NO MATCHES FOUND FOR '" << pid << "' IN THE PRODUCTS LIST. TRY SOMETHING DIFFERENT :)" << endl;
    }
    products.close();
    
    char choice;
    cout<<"DO YOU WANT TO ADD ANOTHER ITEM TO THE CART? (Y/N) ";
    cin>>choice;
    if(choice=='Y'||choice=='y'){
        addtocart();
    }
}

bool isProductInCart(char pid[5]) {
    ifstream cart("cart.txt");
    char buffer[200], fileProductID[50];
    
    while (cart.getline(buffer, 200)) {
        int i = 0, j = 0;

        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileProductID[j++] = buffer[i++];
        }
        fileProductID[j] = '\0';

        if (stringcomparison(pid, fileProductID)) {
            return true;
        }
    }

    return false;
}

void increaseProductQuantity(char pid[5]) {
    ifstream cart("cart.txt");
    ofstream temp("temp.txt");
    char buffer[200], fileProductID[50], fileName[50], fileCategory[50], fileQuantity[50], filePrice[50];
    bool found = false;

    while (cart.getline(buffer, 200)) {
        int i = 0, j = 0;

        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileProductID[j++] = buffer[i++];
        }
        fileProductID[j] = '\0';
        i++;

        j = 0;
        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileName[j++] = buffer[i++];
        }
        fileName[j] = '\0';
        i++;

        j = 0;
        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileCategory[j++] = buffer[i++];
        }
        fileCategory[j] = '\0';
        i++;

        j = 0;
        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileQuantity[j++] = buffer[i++];
        }
        fileQuantity[j] = '\0';
        i++;

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

        if (stringcomparison(pid, fileProductID)) {
            int quantity = atoi(fileQuantity);
            quantity++;  // Increase the quantity by 1
            temp << fileProductID << " | " << fileName << " | " << fileCategory << " | "
                 << quantity << " | " << filePrice << endl;
            found = true;
        } else {
            temp << fileProductID << " | " << fileName << " | " << fileCategory << " | "
                 << fileQuantity << " | " << filePrice << endl;
        }
    }

    if (!found) {
        cout << "Error: Product not found to increase quantity." << endl;
    }

    cart.close();
    temp.close();

    remove("cart.txt");
    rename("temp.txt", "cart.txt");
}

void displayCartSummary() {
    ifstream cart("cart.txt");
    char buffer[200], fileProductID[50], fileName[50], fileCategory[50], fileQuantity[50], filePrice[50];
    int totalQuantity = 0;
    float totalPrice = 0.0;

    cout << "\n-------------------------------\n";
    cout << "         CART SUMMARY\n";
    cout << "-------------------------------\n";

    while (cart.getline(buffer, 200)) {
        int i = 0, j = 0;

        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileProductID[j++] = buffer[i++];
        }
        fileProductID[j] = '\0';
        i++;

        j = 0;
        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileName[j++] = buffer[i++];
        }
        fileName[j] = '\0';
        i++;

        j = 0;
        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileCategory[j++] = buffer[i++];
        }
        fileCategory[j] = '\0';
        i++;

        j = 0;
        while (buffer[i] != '|' && buffer[i] != '\0') {
            fileQuantity[j++] = buffer[i++];
        }
        fileQuantity[j] = '\0';
        i++;

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

        int quantity = atoi(fileQuantity);
        float price = atof(filePrice);

        totalQuantity += quantity;
        totalPrice += quantity * price;

        cout << fileProductID << " | " << fileName << " | " << fileCategory << " | "
             << quantity << " | " << price << endl;
    }

    cout << "\033[1;36mTotal Quantity: \033[0m" << totalQuantity << endl;
    cout << "\033[1;36mTotal Amount: \033[0m" << totalPrice << endl;
    cart.close();
}

void forgotpassword(char username[50]) {
    char buffer[200], fileUsername[50], filePassword[50], fileRole[2];
    char fileSecurityQ1[50], fileSecurityQ2[50], fileSecurityQ3[50];
    char newpassword[50], confirm_password[50];
    bool usernameFound = false;

    ifstream creds("Credentials.txt");
    ofstream tempFile("Temp.txt");

    if (!creds.is_open() || !tempFile.is_open()) {
        cout << "SERVER IS UNDER MAINTENANCE. PLEASE TRY AGAIN LATER." << endl;
        return;
    }

    cout << "ANSWER THE FOLLOWING SECURITY QUESTIONS TO RESET YOUR PASSWORD:\n";

    char answer1[50], answer2[50], answer3[50];
    cout << "WHAT IS YOUR FAVORITE COLOR? ";
    cin.ignore();
    cin.getline(answer1, 50);

    cout << "WHAT IS THE NAME OF YOUR HOMETOWN? ";
    cin.getline(answer2, 50);

    cout << "WHAT IS YOUR FAVORITE FOOD? ";
    cin.getline(answer3, 50);

    while (creds.getline(buffer, 200)) {
        int i = 0, j = 0;

        // Extract and decrypt username
        while (buffer[i] != ',' && buffer[i] != '\0') {
            fileUsername[j++] = buffer[i++];
        }
        fileUsername[j] = '\0';
        caesarCipherDecrypt(fileUsername, 3);
        i++;

        // Extract and decrypt password
        j = 0;
        while (buffer[i] != ',' && buffer[i] != '\0') {
            filePassword[j++] = buffer[i++];
        }
        filePassword[j] = '\0';
        caesarCipherDecrypt(filePassword, 3);
        i++;

        // Extract role
        j = 0;
        while (buffer[i] != ',' && buffer[i] != '\0') {
            fileRole[j++] = buffer[i++];
        }
        fileRole[j] = '\0';
        i++;

        // Extract security questions (not encrypted)
        j = 0;
        while (buffer[i] != ',' && buffer[i] != '\0') {
            fileSecurityQ1[j++] = buffer[i++];
        }
        fileSecurityQ1[j] = '\0';
        i++;

        j = 0;
        while (buffer[i] != ',' && buffer[i] != '\0') {
            fileSecurityQ2[j++] = buffer[i++];
        }
        fileSecurityQ2[j] = '\0';
        i++;

        j = 0;
        while (buffer[i] != ',' && buffer[i] != '\0') {
            fileSecurityQ3[j++] = buffer[i++];
        }
        fileSecurityQ3[j] = '\0';
        i++;

        // Check if the username matches
        if (stringcomparison(username, fileUsername)) {
            usernameFound = true;

            // Validate security answers
            if (stringcomparison(answer1, fileSecurityQ1) &&
                stringcomparison(answer2, fileSecurityQ2) &&
                stringcomparison(answer3, fileSecurityQ3)) {
                cout << "SECURITY QUESTIONS ANSWERED CORRECTLY.\n";

                // Ask for a new password
                do {
                    cout << "ENTER YOUR NEW PASSWORD: ";
                    cin.getline(newpassword, 50);
                    cout << "CONFIRM YOUR NEW PASSWORD: ";
                    cin.getline(confirm_password, 50);

                    if (!stringcomparison(newpassword, confirm_password)) {
                        cout << "PASSWORDS DO NOT MATCH. TRY AGAIN.\n";
                    }
                } while (!stringcomparison(newpassword, confirm_password));

                // Encrypt and update the password
                caesarCipherEncrypt(newpassword, 3);
                strcpy(filePassword, newpassword);

                cout << "PASSWORD HAS BEEN RESET SUCCESSFULLY!\n";
            } else {
                cout << "SECURITY QUESTIONS ANSWERED INCORRECTLY. PASSWORD RESET FAILED.\n";
            }
        }

        // Write updated or unchanged user data to the temporary file
        tempFile << fileUsername << ","
                 << filePassword << ","
                 << fileRole << ","
                 << fileSecurityQ1 << ","
                 << fileSecurityQ2 << ","
                 << fileSecurityQ3 << "," << buffer + i << "\n";
    }

    creds.close();
    tempFile.close();
    remove("Credentials.txt");
    rename("Temp.txt", "Credentials.txt");

    if (!usernameFound) {
        cout << "USERNAME NOT FOUND. PLEASE TRY AGAIN." << endl;
    }
}


char checkcredentials(char username[50], char password[50]) {
    ifstream creds("Credentials.txt");

    char fileUsername[50], filePassword[50], fileRole[2];
    char buffer[200];

    while (creds.getline(buffer, 200)) {
        int i = 0, j = 0;

        //username
        while (buffer[i] != ',' && buffer[i] != '\0') {
            fileUsername[j++] = buffer[i++];
        }
        fileUsername[j] = '\0';
        i++;                    

        //password
        j = 0;
        while (buffer[i] != ',' && buffer[i] != '\0') {
            filePassword[j++] = buffer[i++];
        }
        filePassword[j] = '\0';
        i++;

        //role
        j = 0;
        while (buffer[i] != ',' && buffer[i] != '\0') {
            fileRole[j++] = buffer[i++];
        }
        fileRole[j] = '\0';

        // Decrypt stored username and password
        caesarCipherDecrypt(fileUsername, 3);
        caesarCipherDecrypt(filePassword, 3);

        if (stringcomparison(fileUsername, username) && stringcomparison(filePassword, password)) {
            creds.close();
            return fileRole[0];
        }
    }

    creds.close();
    return 'N'; // 'N' indicates invalid credentials
}

bool usernameExists(const char* username) {
    ifstream file("Credentials.txt");
    char encryptedUsername[50];
    char decryptedUsername[50];
    char buffer[200];

    while (file.getline(buffer, 200)) {
        int i = 0, j = 0;

        while (buffer[i] != ',' && buffer[i] != '\0') {
            encryptedUsername[j++] = buffer[i++];
        }
        encryptedUsername[j] = '\0';

        // Decrypt the username
        strcpy(decryptedUsername, encryptedUsername);
        caesarCipherDecrypt(decryptedUsername, 3);

        // Compare the decrypted username with the input
        bool isMatch = true;
        for (int k = 0; username[k] != '\0' || decryptedUsername[k] != '\0'; k++) {
            if (username[k] != decryptedUsername[k]) {
                isMatch = false;
                break;
            }
        }

        if (isMatch) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

