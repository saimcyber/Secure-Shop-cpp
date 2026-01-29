# Secure Shop 🔒

A console-based E-commerce management system developed in C++ with a strong focus on security fundamentals. This project demonstrates secure programming practices including Role-Based Access Control (RBAC), custom encryption, and Two-Factor Authentication (2FA).

## 🚀 Features

### Security Architecture
* **Custom Encryption:** Implements a shift-based cipher to encrypt sensitive credentials (usernames/passwords) in the file database.
* **Two-Factor Authentication (2FA):** Admin login requires an OTP generated via a simulation token system.
* **Activity Logging:** comprehensive audit trails (`ActivityLogs.txt`) track all sensitive actions (logins, product deletion, role changes) for non-repudiation.
* **Input Sanitation:** Custom validation logic to prevent buffer overflows and type-mismatch errors during data entry.

### Functionality
* **Admin Panel:** User management, 2FA toggling, viewing audit logs, and sales analysis.
* **Employee Panel:** Inventory management, restocking alerts, and handling support tickets.
* **Customer Panel:** Browsing products, cart management, wishlist, and purchasing.

## 🛠️ Tech Stack
* **Language:** C++
* **Storage:** File Handling (Text-based database)
* **Interface:** Console/CLI with color-coded menus

## 📂 Project Structure
* `main.cpp`: Entry point and authentication logic.
* `admin.h` / `employee.h` / `customer.h`: Role-specific logic modules.
* `basicfunctionalities.h`: Utility functions for string manipulation and security checks.

## 🔧 How to Run
1.  Clone the repository: `git clone https://github.com/YOUR-USERNAME/Secure-Shop-CPP.git`
2.  Compile the source code using a C++ compiler (e.g., g++):
    ```bash
    g++ main.cpp -o secureshop
    ```
3.  Run the executable:
    ```bash
    ./secureshop
    ```