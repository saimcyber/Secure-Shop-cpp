#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include"customer.h"
using namespace std;

void employeemenu();

void managesupportrequests();
void displayallsupportrequests();
void solvesupportrequests();
void removesupportrequest();

void inventorymanagement();
void addanyproduct();
void editanyproduct();
void deleteanyproduct();

void availabilityandstock();
void restockalerts();
void displayallrestockalerts();

void salesandrevenuecontributions();
void addcontributions();
void checkcontributions();
void completecontributions();

void feedbackresponse();
void allfeedbacks();
void givefeedback();

void announcementmanagement();
void addannouncement();
void deleteannouncement();


void employeemenu(){

        setColor(4);
        cout << "\t \t   *************************************************\n";
        cout << "\t \t   *               EMPOLYEE MENU                    *\n";
        cout << "\t \t   *************************************************\n";
        resetColor();
        setColor(1);
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   1-->  MANAGE SUPPORT REQUESTS                          |" << endl;
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   2-->  INVENTORY MANAGEMENT                             |" << endl;
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   3-->  PRODUCT AVAILABILITY AND STOCK ALERTS            |" << endl;
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   4-->  SALES AND REVENUE CONTRIBUTIONS                  |" << endl;
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   5-->  RESPONSE FEEDBACK OF CUSTOMERS                   |" << endl;
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   6-->  ANNOUNCEMENT MANAGEMENT                          |" << endl;
        cout << "\t \t----------------------------------------------------------" << endl;
        cout << "\t \t|   7--> EXIT                                              |" << endl;
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

    switch (choice) {
        case 1:
            managesupportrequests();
            break;
        case 2:
            inventorymanagement();
            break;
        case 3:
            availabilityandstock();
            break;
        case 4:
            salesandrevenuecontributions();
            break;
        case 5:
            feedbackresponse();
            break;

        case 6:
            announcementmanagement();
            break;

        case 7:
            cout << "\t\t\033[48;5;196m************ GOOBYE EMPLOYEE! ************\033[0m\n";
            cout << "\t\t\033[48;5;30m************ We Wish to See You Again! *********\033[0m\n\n";
            break;
    }
}


void announcementmanagement(){
        cout << "\n\n------------------------------------------" << endl;
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
    }while(choice < 1 || choice > 4);

    switch(choice){
        case 1:
        addannouncement();
        cout<<"PRESS ANY KEY TO GO BACK TO ANNOUNCEMENT MANAGEMENT \n";
        cout<<"-------------------------------------\n";
        cin.ignore();
        cin.get();
        announcementmanagement();
        break;

        case 2:
        deleteannouncement();
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
        employeemenu();
        break;
    }
}

void addannouncement() {
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


void deleteannouncement() {
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


void feedbackresponse(){
        cout << "\n\n------------------------------------------" << endl;
        cout << "|           FEEDBACK RESPONSES           |" << endl;
        cout << "|----------------------------------------|" << endl;
        cout << "| 1. VIEW ALL FEEDBACKS                  |" << endl;
        cout << "| 2. GIVE FEEEDBCK RESPONSE              |" << endl;
        cout << "| 3. BACK TO EMPLOYEE MENU               |" << endl;
        cout << "------------------------------------------" << endl;
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
        allfeedbacks();
        cout<<"PRESS ANY KEY TO GO BACK TO AVAILABILITY AND STOCK MANAGEMENT\n";
        cout<<"-------------------------------------------------------------\n";
        cin.ignore();
        cin.get();
        feedbackresponse();
        break;

        case 2:
        givefeedback();
        cout<<"PRESS ANY KEY TO GO BACK TO AVAILABILITY AND STOCK MANAGEMENT\n";
        cout<<"-------------------------------------------------------------\n";
        cin.ignore();
        cin.get();
        feedbackresponse();
        break;

        case 3:
        employeemenu();
        break;
}
}

void givefeedback() {
    cout << "-------------------------------------\n";
    cout << "   GIVE FEEDBACK RESPONSE\n";
    cout << "-------------------------------------\n";

    cout << "ENTER THE USERNAME OF THE CUSTOMER: ";
    char username[50];
    cin.ignore();
    cin.getline(username, 50);

    int productid;
    do {
        cout << "ENTER THE PRODUCT ID OF THE FEEDBACK: ";
        cin >> productid;
        if (cin.fail()){
            cout << "Invalid input! PRODUCT IDs START FROM 100\n";
            cin.clear();
            cin.ignore(200, '\n');
            productid = 0;
        } else if (productid < 100 || productid > 9999) {
            cout<<"Invalid input! PRODUCT IDs START FROM 100\n";
        }
    }while(productid < 100 || productid > 9999);

    ifstream feedbackFile("feedback.txt");

    char* buffer = allocateBufferForLongestLine("feedback.txt");
    if (buffer == nullptr) {
        return;
    }
    bool feedbackFound = false; //BY DEFAULT, THE FEEDBACK IS NOT FOUND
    char fileUsername[50], feedbackText[150];
    int fileProductId;

    while (feedbackFile.getline(buffer, 200)){
        int i = 0, j = 0;

        //Username
        while (buffer[i] != '\0' && buffer[i] != ':') {
            i++;
        }
        i++;
        while (buffer[i] != '\0' && buffer[i] != '\n') {
            fileUsername[j++] = buffer[i++];
        }
        fileUsername[j] = '\0';
        trim(fileUsername);

        // Skip Product ID
        while (buffer[i] != '\0' && buffer[i] != ':') i++;
        i++;
        fileProductId = 0;
        while (buffer[i] != '\0' && buffer[i] != '\n') {
            fileProductId = fileProductId * 10 + (buffer[i] - '0');
            i++;
        }

        // Jump to Feedback line
        while (buffer[i] != '\0' && buffer[i] != ':') i++;
        i++;
        j = 0;
        while (buffer[i] != '\0' && buffer[i] != '\n') {
            feedbackText[j++] = buffer[i++];
        }
        feedbackText[j] = '\0';
        trim(feedbackText);

        if (stringcomparison(username, fileUsername) && fileProductId == productid) {
            feedbackFound = true;
            break;
        }
    }

    feedbackFile.close();

    if (!feedbackFound) {
        cout << "No matching feedback found for this user and product.\n";
        return;
    }

    //FEEDBACK MILNE KAA BAAD AB HUM RESPONSE DEIN GAA
    
    cin.ignore();
    cout << "Feedback found. Enter your response: ";
    char response[200];
    cin.getline(response, 200);

    ofstream feedbackFileOut("feedback.txt", ios::app);

    feedbackFileOut << "Username: " << username << endl;
    feedbackFileOut << "Product ID: " << productid << endl;
    feedbackFileOut << "Feedback: " << feedbackText << endl;
    feedbackFileOut << "Response: " << response << endl;
    feedbackFileOut << "-------------------------------------" << endl;

    feedbackFileOut.close();
    delete[] buffer;
    logactivity("FEEDBACK GIVEN BY EMPLOYEE");
    cout << "Response added successfully!\n";
}

void allfeedbacks() {
    cout << "-------------------------------------\n";
    cout << "   ALL FEEDBACKS\n";
    cout << "-------------------------------------\n";

    ifstream feedbackFile("feedback.txt");

    char* buffer = allocateBufferForLongestLine("feedback.txt");
    if (buffer == nullptr) {
        return;
    }

    while (feedbackFile.getline(buffer, 200)) {
        cout << buffer << endl;
    }
    delete[] buffer;
    feedbackFile.close();
}

void salesandrevenuecontributions(){
        cout << "\n\n------------------------------------------" << endl;
        cout << "|     SALES AND REVENUE CONTRIBUTIONS    |" << endl;
        cout << "|----------------------------------------|" << endl;
        cout << "| 1. ADD CONTRIBUTIONS                   |" << endl;
        cout << "| 2. CHECK CONTRIBUTION                  |" << endl;
        cout << "| 3. COMPLETE CONTRIBUTION HISTORY       |" << endl;
        cout << "| 4. RETURN TO EMPLOYEE MENU             |" << endl;
        cout << "------------------------------------------" << endl;
    int choice2;

    do{
        cout << "ENTER YOUR CHOICE (1 TO 4): ";
        cin >> choice2;
        if (cin.fail()) {
            cout << "Invalid input! Please enter a number between 1 and 4.\n";
            cin.clear();
            cin.ignore(200, '\n');
            choice2 = 0;
        }else if(choice2 < 1 || choice2 > 4) {
            cout << "Invalid choice! Please select a valid option (1 to 4).\n";
        }
    }while(choice2 < 1 || choice2 > 4);

    switch(choice2){
        case 1:
        addcontributions();
        cout<<"PRESS ANY KEY TO GO BACK TO AVAILABILITY AND STOCK MANAGEMENT\n";
        cout<<"-------------------------------------------------------------\n";
        cin.ignore();
        cin.get();
        salesandrevenuecontributions();
        break;

        case 2:
        checkcontributions();
        cout<<"PRESS ANY KEY TO GO BACK TO AVAILABILITY AND STOCK MANAGEMENT\n";
        cout<<"-------------------------------------------------------------\n";
        cin.ignore();
        cin.get();
        salesandrevenuecontributions();
        break;

        case 3:
        completecontributions();
        cout<<"PRESS ANY KEY TO GO BACK TO AVAILABILITY AND STOCK MANAGEMENT\n";
        cout<<"-------------------------------------------------------------\n";
        cin.ignore();
        cin.get();
        salesandrevenuecontributions();
        break;

        case 4:
        employeemenu();
        break;
    }
}

void completecontributions(){
    cout << "-------------------------------------\n";
    cout << "     DISPLAY ALL CONTRIBUTIONS\n";
    cout << "-------------------------------------\n";

    ifstream salesReport("SalesReport.txt");

    char* buffer = allocateBufferForLongestLine("SalesReport.txt");
    if (buffer == nullptr) {
        return;
    }

    while (salesReport.getline(buffer, 200)) {
        cout << buffer << endl;
    }
    delete[] buffer;
    salesReport.close();
}

void checkcontributions(){
    cout << "-------------------------------------\n";
    cout << "       CHECK CONTRIBUTION\n";
    cout << "-------------------------------------\n";
    
    char nameofemployee[50];
    cout << "ENTER THE NAME OF EMPLOYEE: ";
    cin.ignore();
    cin.getline(nameofemployee, 50);

    ifstream salesReport("SalesReport.txt");

    char* buffer = allocateBufferForLongestLine("SalesReport.txt");
    if (buffer == nullptr) {
        return;
    }
    bool employeeFound = false;

    while (salesReport.getline(buffer, 200)) {
        char employeeName[50];
        int i = 0;

        //employee kaa name kaa peeche yee wala format haii tuu maine uss koo predfine kar diyaa haii taa kaa asaani saa dhoond lee employee name wali line koo
        if (buffer[0] == 'E' && buffer[1] == 'm' && buffer[2] == 'p' && buffer[3] == 'l' && buffer[4] == 'o' &&
            buffer[5] == 'y' && buffer[6] == 'e' && buffer[7] == 'e' && buffer[8] == ':' && buffer[9] == ' ') {

            i = 10; //ISS SAA AGAA JUMP KAR JAYEE -  "Employee: "
            int j = 0;
            while (buffer[i] != '\0' && buffer[i] != '\n' && j < 49) {
                employeeName[j] = buffer[i];
                i++;
                j++;
            }
            employeeName[j] = '\0'; // Null terminate the name string

            if (stringcomparison(nameofemployee, employeeName)) {
                employeeFound = true;
                cout << "-------------------------------------\n";
                cout << "Sales Record for " << nameofemployee << ":\n";

                cout << buffer << endl;

                // Print the Contribution and Date and Time lines
                salesReport.getline(buffer, 200); // Contribution
                cout << buffer << endl;
                salesReport.getline(buffer, 200); // Date and Time
                cout << buffer << endl;

                //--------------------- line
                salesReport.getline(buffer, 200);
                cout << buffer << endl;
            }
        }
    }

    if (!employeeFound) {
        cout << "No records found for " << nameofemployee << ".\n";
    }
    delete[] buffer;
    salesReport.close();
}

void addcontributions() {
    cout << "-------------------------------------\n";
    cout << "   ADD CONTRIBUTION\n";
    cout << "-------------------------------------\n";
    cout << "ENTER CONTRIBUTION DETAILS:\n";
    char nameofemployee[50], priceoforder[10];
    
    cout << "ENTER THE NAME OF EMPLOYEE: ";
    cin.ignore();
    cin.getline(nameofemployee, 50);
    
    cout << "ENTER THE PRICE OF ORDER: ";
    cin.getline(priceoforder, 10);

    //current date and time - formula from (https://www.geeksforgeeks.org/date-and-time-parsing-in-cpp/)
    time_t now = time(0);
    char* dt = ctime(&now);

    ofstream salesReport("SalesReport.txt", ios::app);

    salesReport << "Employee: " << nameofemployee << endl;
    salesReport << "Contribution: " << priceoforder << " USD" << endl;
    salesReport << "Date and Time: " << dt;
    salesReport << "-------------------------------------\n";

    salesReport.close();

    logactivity("CONTRIBUTIONS ADDED BY EMPLOYEE");
    cout << "Contribution added successfully!\n";
}

//-------------------------------------------------------------------------------------------------------

void availabilityandstock(){
        cout << "\n\n------------------------------------------" << endl;
        cout << "|   AVAILABILITY AND STOCK MANAGEMENT    |" << endl;
        cout << "|----------------------------------------|" << endl;
        cout << "| 1. CHECK ANY RESTOCK ALERTS            |" << endl;
        cout << "| 2. VIEW RESTOCKING ALERTS HISTORY      |" << endl;
        cout << "| 3. BACK TO EMPLOYEE MENU               |" << endl;
        cout << "------------------------------------------" << endl;
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
            cout << "Invalid choice! Please select a valid option (1 to 4).\n";
        }
    }while(choice2 < 1 || choice2 > 3);

    switch(choice2){
        case 1:
            restockalerts();
            cout<<"PRESS ANY KEY TO GO BACK TO AVAILABILITY AND STOCK MANAGEMENT\n";
            cout<<"-------------------------------------------------------------\n";
            cin.ignore();
            cin.get();
            availabilityandstock();
            break;

        case 2:
            displayallrestockalerts();
            cout<<"PRESS ANY KEY TO GO BACK TO AVAILABILITY AND STOCK MANAGEMENT\n";
            cout<<"-------------------------------------------------------------\n";
            cin.ignore();
            cin.get();
            availabilityandstock();
            break;
        
        case 3:
            employeemenu();
            break;
    }
}

void displayallrestockalerts(){
    cout << "-------------------------------------\n";
    cout << "       RESTOCKING ALERTS HISTORY\n";
    cout << "-------------------------------------\n";

    ifstream restockFile("restockalerts.txt");

    char* buffer = allocateBufferForLongestLine("restockalerts.txt");
    if (buffer == nullptr) {
        return;
    }
    bool alertFound = false;

    while (restockFile.getline(buffer, 200)) {
        alertFound = true; // At least one alert exists
        cout << buffer << endl;
    }
    restockFile.close();

    if (!alertFound) {
        cout << "No restocking alerts found.\n";
    }

    logactivity("RESTOCKING ALERS HISTORY DISPLAYED TO EMPLOYEE");
    cout << "-------------------------------------\n";
    delete[] buffer;
}


void restockalerts(){
    cout << "-------------------------------------\n";
    cout << "        RESTOCKING ALERTS\n";
    cout << "-------------------------------------\n";
    
    int threshold;
    do{
        cout << "INPUT THE MINIMUM THRESHOLD FOR RESTOCK ALERTS: ";
        cin >> threshold;
        if (cin.fail()){
            cout << "Invalid input!Please enter a number greater then 0\n";
            cin.clear();
            cin.ignore(200, '\n');
            threshold = -1;
        }else if(threshold < 0 || threshold > 9999999) {
            cout << "Invalid input!Please enter a number greater then 0\n";
        }
    }while(threshold < 0 || threshold > 9999999);

    ifstream productsFile("products.txt");

    char buffer[200], productID[50], productName[50], productCategory[50], productQuantity[50], productPrice[50];
    bool productFound = false;

    ofstream restockLog("restockalerts.txt", ios::app);

    restockLog << "Threshold: " << threshold << endl;

    cout << "Products with quantity less than " << threshold << ":\n";
    cout << "-------------------------------------\n";

    // Read file line by line
    while (productsFile.getline(buffer, 200)) {
        int i = 0, j = 0;

        //ProductID
        while (buffer[i] != '|' && buffer[i] != '\0') {
            productID[j++] = buffer[i++];
        }
        productID[j] = '\0';
        i++;

        //Name
        j = 0;
        while (buffer[i] != '|' && buffer[i] != '\0') {
            productName[j++] = buffer[i++];
        }
        productName[j] = '\0';
        i++;

        //Category
        j = 0;
        while (buffer[i] != '|' && buffer[i] != '\0') {
            productCategory[j++] = buffer[i++];
        }
        productCategory[j] = '\0';
        i++;

        //Quantity
        j = 0;
        while (buffer[i] != '|' && buffer[i] != '\0') {
            productQuantity[j++] = buffer[i++];
        }
        productQuantity[j] = '\0';
        i++;

        //Price
        j = 0;
        while (buffer[i] != '\0') {
            productPrice[j++] = buffer[i++];
        }
        productPrice[j] = '\0';

        //Quantity koo trim kar lein gaa kyun kaa hum naa isi saa compare karnaa haiii
        trim(productQuantity);
        int productQty = atoi(productQuantity);

        // If the product quantity is less than the threshold, display it
        if (productQty < threshold) {
            productFound = true;
            cout << "Product ID: " << productID << " | "
                 << "Name: " << productName << " | "
                 << "Category: " << productCategory << " | "
                 << "Quantity: " << productQuantity << " | "
                 << "Price: " << productPrice << endl;

            // Log the product details into the restockalerts.txt file
            restockLog << "Product ID: " << productID << " | "
                       << "Name: " << productName << " | "
                       << "Category: " << productCategory << " | "
                       << "Quantity: " << productQuantity << " | "
                       << "Price: " << productPrice << endl;
        }
    }
    logactivity("RESTOCKING ALERS VIEWED BY EMPLOYEE");
    productsFile.close();
    restockLog.close();

    if (!productFound) {
        cout << "No products found below the threshold.\n";
    }
    cout << "-------------------------------------\n";
}

void inventorymanagement(){
        cout << "\n\n------------------------------------------" << endl;
        cout << "|          INVENTORY MANAGEMENT          |" << endl;
        cout << "|----------------------------------------|" << endl;
        cout << "| 1. DISPLAY COMPLETE CATALOGUE          |" << endl;
        cout << "| 2. ADD ANY PRODUCT                     |" << endl;
        cout << "| 3. EDIT ANY PRODUCT                    |" << endl;
        cout << "| 4. DELETE ANY PRODUCT                  |" << endl;
        cout << "| 5. BACK TO EMPLOYEE MENU               |" << endl;
        cout << "------------------------------------------" << endl;
    int choice2;
    
    do{
        cout << "ENTER YOUR CHOICE (1 TO 5): ";
        cin >> choice2;
        if (cin.fail()) {
            cout << "Invalid input! Please enter a number between 1 and 5.\n";
            cin.clear();
            cin.ignore(200, '\n');
            choice2 = 0;
        }else if(choice2 < 1 || choice2 > 5) {
            cout << "Invalid choice! Please select a valid option (1 to 5).\n";
        }
    }while(choice2 < 1 || choice2 > 5);
    
    switch(choice2){
        case 1:
            displayallproducts();
            cout<<"PRESS ANY KEY TO GO BACK TO INVENTORY MANAGEMENT \n";
            cout<<"-------------------------------------\n";
            cin.ignore();
            cin.get();
            inventorymanagement();
            break;
        case 2:
            addanyproduct();
            cout<<"PRESS ANY KEY TO GO BACK TO INVENTORY MANAGEMENT \n";
            cout<<"-------------------------------------\n";
            cin.ignore();
            cin.get();
            inventorymanagement();
            break;

        case 3:
            editanyproduct();
            cout<<"PRESS ANY KEY TO GO BACK TO INVENTORY MANAGEMENT \n";
            cout<<"-------------------------------------\n";
            cin.ignore();
            cin.get();
            inventorymanagement();
            break;
        
        case 4:
            deleteanyproduct();
            cout<<"PRESS ANY KEY TO GO BACK TO INVENTORY MANAGEMENT \n";
            cout<<"-------------------------------------\n";
            cin.ignore();
            cin.get();
            inventorymanagement();
            break;

        case 5:
            employeemenu();
            break;
    }
}

void deleteanyproduct(){
    cout << "-------------------------------------\n";
    cout << "        DELETE PRODUCT\n";
    cout << "-------------------------------------\n";

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

        if (stringcomparison(pid, fileProductID)) {
            productFound = true;
            cout << "Product ID: " << fileProductID << " has been deleted.\n";
        } else {
            //BAKKI SARI WRITE HOO JAYEIN GII WAPIS
            tempFile << fileProductID << " | " << fileName << " | " << fileCategory << " | "
                     << fileQuantity << " | " << filePrice << endl;
        }
    }

    productsFile.close();
    tempFile.close();

    if (productFound) {
        remove("products.txt");
        rename("temp_products.txt", "products.txt");
        logactivity("PRODUCT DELETED BY EMPLOYEE");
        cout << "Product deleted successfully.\n";
    } else {
        cout << "ERROR: Product ID not found.\n";
    }
}


void editanyproduct(){
    cout << "-------------------------------------\n";
    cout << "        EDITING PRODUCT\n";
    cout << "-------------------------------------\n";

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

        //fields
        trim(fileProductID);
        trim(fileName);
        trim(fileCategory);
        trim(fileQuantity);
        trim(filePrice);

        if (stringcomparison(pid, fileProductID)) {
            productFound = true;

            // Display product details for editing
            cout << "Product ID: " << fileProductID << endl;
            cout << "Name: " << fileName << endl;
            cout << "Category: " << fileCategory << endl;
            cout << "Quantity: " << fileQuantity << endl;
            cout << "Price: " << filePrice << endl;

        cout << " \n___________________________________________\n";
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
                    logactivity("PRODUCT NAME UPDATED BY EMPLOYEE");
                    break;
                }
                case 2: {
                    char newCategory[50];
                    cout << "ENTER NEW CATEGORY: ";
                    cin.ignore();
                    cin.getline(newCategory, 50);
                    tempFile << fileProductID << " | " << fileName << " | " << newCategory << " | "
                             << fileQuantity << " | " << filePrice << endl;
                    logactivity("PRODUCT CATEGORY UPDATED BY EMPLOYEE");
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
                        cout << "Invalid input! PRODUCT ID MUST CONTAIN DIGITS ONLY.\n";
                    }}while(!valid);

                    tempFile << fileProductID << " | " << fileName << " | " << fileCategory << " | "
                             << fileQuantity << " | " << newPrice << endl;
                    logactivity("PRODUCT PRICE UPDATED BY EMPLOYEE");
                    break;
                }
                case 4: {
                    char newQuantity[50];
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
                    logactivity("PRODUCT QUANTITY UPDATED BY EMPLOYEE");
                    break;
                }
                case 5:
                    break;
            }
        } else {
            // Write the product details back to the temporary file if it's not the one being edited
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


void addanyproduct() {
    char productQuantity[20], productPrice[20], productCategory[50], productName[50];
    int nextProductID = 101; //Default starting ID
    cout << "-------------------------------------\n";
    cout << "        CONTINUE ADDING PRODUCT\n";
    cout << "-------------------------------------\n";

    ifstream productFile("products.txt");

    char buffer[200];
    while (productFile.getline(buffer, 200)) {
        char lastProductID[10];
        int i = 0, j = 0;

        // Extract Product ID
        while (buffer[i] != ' ' && buffer[i] != '\0') {
            lastProductID[j++] = buffer[i++];
        }
        lastProductID[j] = '\0';

        trim(lastProductID);
        nextProductID = atoi(lastProductID) + 1; //YAHAN PAR PRODUCT ID COUNT KAR LEIN GAAA JOO HUM NAA NEW PRODUCT KO DENI HAII
    }
    productFile.close();

    cout << "ENTER PRODUCT NAME: ";
    cin.ignore();
    cin.getline(productName, 50);
    trim(productName);

    cout << "ENTER PRODUCT CATEGORY: ";
    cin.getline(productCategory, 50);
    trim(productCategory);

    bool valid;
    do{
        valid = true;
        cout << "ENTER PRODUCT PRICE : ";
        cin >> productPrice;
        for (int i = 0; productPrice[i] != '\0'; i++) {
            if (productPrice[i] < '0' || productPrice[i] > '9') {
            valid = false;
            break;
            }
        }
        if (!valid) {
            cout << "Invalid input! PRICE MUST CONTAIN DIGITS ONLY.\n";
    }}while(!valid);


    do {
        valid = true;
        cout << "ENTER PRODUCT QUANTITY: ";
        cin >> productQuantity;

        for (int i = 0; productQuantity[i] != '\0'; i++) {
            if (productQuantity[i] < '0' || productQuantity[i] > '9') {
                valid = false;
                break;
            }
        }

        if (valid) {
            int quantity = 0;
            for (int i = 0; productQuantity[i] != '\0'; i++) {
                quantity = quantity * 10 + (productQuantity[i] - '0'); //(FORMULA FROM https://www.geeksforgeeks.org/cpp-program-for-char-to-int-conversion/)
            }
            if (quantity > 50) {
                valid = false;
                cout << "Invalid input! QUANTITY MUST BE 50 OR LESS.\n";
            }
        } else {
            cout << "Invalid input! QUANTITY MUST CONTAIN DIGITS ONLY.\n";
        }
        } while (!valid);


    ofstream productFileOut("products.txt", ios::app);

    productFileOut << nextProductID << " | " << productName << " | " << productCategory<< " | " << productQuantity << " | " << productPrice << "$ \n";

    productFileOut.close();

    logactivity("EMPLOYEE ADDED A PRODUCT");
    cout << "PRODUCT ADDED SUCCESSFULLY!\n";
    cout << "-------------------------------------\n";
}


void managesupportrequests() {
        cout << "\n\n------------------------------------------" << endl;
        cout << "|        MANAGE SUPPORT REQUESTS         |" << endl;
        cout << "|----------------------------------------|" << endl;
        cout << "| 1. DISPLAY ALL SUPPORT REQUESTS        |" << endl;
        cout << "| 2. SOLVE ANY SUPPORT REQUESTS          |" << endl;
        cout << "| 3. REMOVE SUPPORT REQUESTS             |" << endl;
        cout << "| 4. BACK TO EMPLOYEE MENU               |" << endl;
        cout << "------------------------------------------" << endl;

    int choice2;
    do{
        cin>>choice2;
        if (cin.fail()){
            cout << "Invalid input! ENTER A NUMBER 1 TO 4.\n";
            cin.clear();
            cin.ignore(200, '\n');
            choice2 = 0;
        }else if (choice2 < 1 || choice2 > 4){
            cout<<"Invalid choice! ENTER A NUMBER 1 TO 4.\n";
    }}while(choice2>4 || choice2<1);

    switch (choice2) {
        case 1:
            displayallsupportrequests();
            cout<<"PRESS ANY KEY TO GO BACK TO MANAGE SUPPORT REQUEST \n";
            cout<<"-------------------------------------\n";
            cin.ignore();
            cin.get();
            managesupportrequests();
            break;

        case 2:
            solvesupportrequests();
            cout<<"PRESS ANY KEY TO GO BACK TO MANAGE SUPPORT REQUEST \n";
            cout<<"-------------------------------------\n";
            cin.ignore();
            cin.get();
            managesupportrequests();
            break;

        case 3:
            removesupportrequest();
            cout<<"PRESS ANY KEY TO GO BACK TO MANAGE SUPPORT REQUEST \n";
            cout<<"-------------------------------------\n";
            cin.ignore();
            cin.get();
            managesupportrequests();
            break;

        case 4:
            employeemenu();
            break;
    }
}

void removesupportrequest() {
    cout << "----------------------------------\n";
    cout << "    REMOVE SUPPORT REQUESTS\n";
    cout << "----------------------------------\n";
    cout << "ENTER THE USERNAME OF WHICH YOU WANT TO REMOVE REQUESTS: ";
    char username[50];
    cin >> username;

    ifstream supportFile("support.txt");
    ofstream tempFile("temp.txt");

    char* buffer = allocateBufferForLongestLine("support.txt");
    if (buffer == nullptr) {
        return;
    }
    char fileUsername[50];
    bool isProcessingRequest = false;
    bool requestFound = false;

    while (supportFile.getline(buffer, 200)) {
        // Humme ptaa haii kaa support request maii real suername kaa peeche yee wala format haii tuu uss koo hum predefine kar dete hain "Username:"
        if (buffer[0] == 'U' && buffer[1] == 's' && buffer[2] == 'e' && buffer[3] == 'r' &&
            buffer[4] == 'n' && buffer[5] == 'a' && buffer[6] == 'm' && buffer[7] == 'e' &&
            buffer[8] == ':' && buffer[9] == ' ') {
            
            //AB ASAL USERNAME NIKLE GAA
            int i = 10, j = 0;
            while (buffer[i] != '\0') {
                fileUsername[j++] = buffer[i++];
            }
            fileUsername[j] = '\0';

            if (stringcomparison(username, fileUsername)) {
                requestFound = true;
                isProcessingRequest = true;
                continue;
            } else {
                isProcessingRequest = false;
            }
        }

        //USS USERNAME KII BAKKKI HAR DETAIL BHI REMOVE HOO JAYEE GIII NOT KII WAJA SAA
        if (!isProcessingRequest) {
            tempFile << buffer << "\n";
        }
    }

    supportFile.close();
    tempFile.close();
    remove("support.txt");
    rename("temp.txt", "support.txt");

    if (requestFound) {
        logactivity("EMPLOYEE REMOVED SUPPORT REQUEST");
        cout << "SUPPORT REQUESTS REMOVED SUCCESSFULLY FOR USERNAME: " << username << endl;
    } else {
        cout << "NO SUPPORT REQUESTS FOUND FOR THE GIVEN USERNAME.\n";
    }
    delete[] buffer;
    cout << "----------------------------------\n";
}

void solvesupportrequests() {
    cout << "----------------------------------\n";
    cout << "    SOLVE SUPPORT REQUESTS\n";
    cout << "----------------------------------\n";
    cout << "ENTER THE USERNAME OF WHICH YOU WANT TO SOLVE REQUEST: ";
    char username[50];
    cin >> username;

    ifstream supportFile("support.txt");
    ofstream tempFile("temp.txt");

    char* buffer = allocateBufferForLongestLine("support.txt");
    if (buffer == nullptr) {
        return;
    }
    char fileUsername[50];
    char issueLine[200];
    bool requestFound = false;
    bool isProcessingRequest = false;

    while (supportFile.getline(buffer, 200)) {
        // Humme ptaa haii kaa support request maii real suername kaa peeche yee wala format haii tuu uss koo hum predefine kar dete hain "Username:"
        if (buffer[0] == 'U' && buffer[1] == 's' && buffer[2] == 'e' && buffer[3] == 'r' &&
            buffer[4] == 'n' && buffer[5] == 'a' && buffer[6] == 'm' && buffer[7] == 'e' &&
            buffer[8] == ':' && buffer[9] == ' ') {
            
            //AB REAL USERNAME NIKAL JAYEE GAA
            int i = 10, j = 0;
            while (buffer[i] != '\0') {
                fileUsername[j++] = buffer[i++];
            }
            fileUsername[j] = '\0';

            if (stringcomparison(username, fileUsername)) {
                requestFound = true;
                isProcessingRequest = true;

                cout << "FOUND SUPPORT REQUEST FOR USERNAME: " << username << endl;
                cout << buffer << endl;

                //ISSUE
                if (supportFile.getline(issueLine, 200)) {
                    cout << issueLine << endl;
                }

                cout << "ENTER RESPONSE: ";
                char response[200];
                cin.ignore();
                cin.getline(response, 200);

                // Write the resolved request to the temp file
                tempFile << "Username: " << fileUsername << "\n";
                tempFile << issueLine << "\n";
                tempFile << "Response: " << response << "\n";
                tempFile << "-------------------------------------\n";
                continue;
            } else {
                isProcessingRequest = false;
            }
        }

        //BAKKI SAARI LINES WAPIS LIKH DEE GAA
        if (!isProcessingRequest) {
            tempFile << buffer << "\n";
        }
    }

    supportFile.close();
    tempFile.close();

    remove("support.txt");
    rename("temp.txt", "support.txt");

    if (requestFound) {
        logactivity("EMPLOYEE SOLVED SUPPORT REQUEST");
        cout << "SUPPORT REQUEST SOLVED SUCCESSFULLY.\n";
    } else {
        cout << "NO SUPPORT REQUEST FOUND FOR THE GIVEN USERNAME.\n";
    }
    delete[] buffer;
    cout << "----------------------------------\n";
}

void displayallsupportrequests() {
    cout << "-------------------------------------\n";
    cout << "         SUPPORT REQUESTS\n";
    cout << "-------------------------------------\n";

    ifstream supportFile("support.txt");

    char* buffer = allocateBufferForLongestLine("support.txt");
    if (buffer == nullptr) {
        return;
    }
    bool hasRequests = false;

    while (supportFile.getline(buffer, 200)) {
        hasRequests = true; //YE CHECK KARNA HAII KAA KOI REQUEST HAII BHII YAA NAHI
        cout << buffer << endl;
    }

    supportFile.close();

    if (!hasRequests) {
        cout << "No support requests found.\n";
    }
    delete[] buffer;
    logactivity("ALL SUPPORT REQUESTS DISPLAYED TO EMPLOYEE");
    cout << "-------------------------------------\n";
}