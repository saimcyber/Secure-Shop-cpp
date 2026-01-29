#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<windows.h>
using namespace std;

int sizeofstring(char []);
bool stringcomparison(char [], char []);
void trim(char[]);
bool itisspace(char);
bool isnumber(const char input[]);
void copychararray(char [],const char []);
void logactivity(const char*);
char* readFileDynamic(const char*);
int getLongestLineLength(const char*);
char* allocateBufferForLongestLine(const char*);


void copychararray(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Null-terminate the destination array
}

bool isnumber(const char input[]) {
    int i = 0;
    while (input[i] != '\0') {
        if (!isdigit(input[i])) {
            return false;
        }
        i++;
    }
    return i > 0;
}

void trim(char str[50]) {
    int start = 0, end = 0;

    //YE CHECK KARE GAA JB TK STARTING MAII SPACES NAA KITNAA CHARACTER LIYAA HAIN
    while (str[start] != '\0' && itisspace(str[start])) {
        start++;
    }

    end = start;
    while (str[end] != '\0') {
        end++;
    }
    end--;

    //AB YEE END SAA CHECK KARNAA SHURU KARE GAA KAA END SAA KITNI SPACES HAIN
    while (end >= start && itisspace(str[end])) {
        end--;
    }

    int j = 0;
    for (int i = start; i <= end; i++) {
        str[j++] = str[i];
    }
    str[j] = '\0';
}
bool itisspace(char x) {
    if (x == ' ') {
        return true;
    }
    return false;
}
int sizeofstring(char tobechecked[50]){
    int count=0;
    for(int i=0;tobechecked[i]!='\0';i++){
    count++;
    }
    return count;
}

bool stringcomparison(char string1[100], char string2[100]){
    int length1 = sizeofstring(string1);
    int length2 = sizeofstring(string2);
    if(length1!=length2){
        return false;
    }
    
    for(int i=0; i<length1;i++){
            if(string1[i]!=string2[i]){
                return false;
        }
    }
    return true;
}

void logactivity(const char* action) {
    ofstream file("ActivityLogs.txt", ios::app);

    time_t now = time(0);
    tm* localTime = localtime(&now);

    char date[11];
    sprintf(date, "%02d/%02d/%04d", localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900);

    char time[9];
    sprintf(time, "%02d:%02d:%02d", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);

    file << action << " | " << date << " | " << time << endl;

    file.close(); // Close the file
}

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole != INVALID_HANDLE_VALUE) {
        SetConsoleTextAttribute(hConsole, color);
    }
}

void resetColor() {
    setColor(7); // 7 is the default console color (white text on black background)
}

void caesarCipherEncrypt(char text[], int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (ch >= 'A' && ch <= 'Z') {  // Uppercase letters
            text[i] = ((ch - 'A' + shift) % 26) + 'A';
        } else if (ch >= 'a' && ch <= 'z') {  // Lowercase letters
            text[i] = ((ch - 'a' + shift) % 26) + 'a';
        } else if (ch >= '0' && ch <= '9') {  // Numbers
            text[i] = ((ch - '0' + shift) % 10) + '0';
        }
    }
}

void caesarCipherDecrypt(char text[], int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (ch >= 'A' && ch <= 'Z') {  // Uppercase letters
            text[i] = ((ch - 'A' - shift + 26) % 26) + 'A';
        } else if (ch >= 'a' && ch <= 'z') {  // Lowercase letters
            text[i] = ((ch - 'a' - shift + 26) % 26) + 'a';
        } else if (ch >= '0' && ch <= '9') {  // Numbers
            text[i] = ((ch - '0' - shift + 10) % 10) + '0';
        }
    }
}


int getLongestLineLength(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file.\n";
        return -1;
    }

    char buffer[200];
    int longestLineLength = 0;

    while (file.getline(buffer, 200)) {
        int currentLineLength = strlen(buffer);
        if (currentLineLength > longestLineLength) {
            longestLineLength = currentLineLength;
        }
    }

    file.close();
    return longestLineLength;
}

char* allocateBufferForLongestLine(const char* filename) {
    int longestLineLength = getLongestLineLength(filename);
    if (longestLineLength == -1) {
        return nullptr;
    }

    char* buffer = new char[longestLineLength + 1];  // +1 for null-terminator
    return buffer;
}