#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

// Forward declaration
class Branch;

// Global variables
extern string currentUsername;
extern string currentUserRole;
extern unordered_map<string, Branch> branches;

// Structure definitions
struct User {
    string username;
    string password;
    string role; // "User" or "Admin"
};

struct StockItem {
    string name;
    int quantity;
    double price;

    StockItem();
    StockItem(string n, int q, double p);
    
    bool isLowStock();
    bool reduceQuantity(int amount);
    void display(bool showLowStock = false);
};

struct Staff {
    string name;
    string role;
    string schedule;

    Staff();
    Staff(string n, string r, string s);
    
    void display();
};

class Branch {
private:
    string toLowerCase(string str);
    
public:
    vector<StockItem> stock;
    vector<Staff> staff;
    
    Branch();
    
    // Stock management functions
    void addStockItem(StockItem item, bool silent = false);
    StockItem* findStockItem(string name);
    bool removeStockItem(string name);
    void displayStock(bool showLowStock = false);
    
    // Staff management functions
    void addStaff(Staff member, bool silent = false);
    Staff* findStaff(string name);
    bool removeStaff(string name);
    void displayStaff();
};

// Utility functions
bool isVaildText(const string& input);
void clearInput();
void printSeparator(char c = '=', int length = 50);
bool getConfirmation(string message);
void initializeBranches();

// User management functions
vector<User> loadUsers();
void saveUser(const User& user);
void saveAllUsers(const vector<User>& users);
bool userExists(const vector<User>& users, const string& username);
void registerUser();
void loginUser();

// Admin functions
void promoteUserToAdmin();
void viewStockLevels();
void addStockItem();
void updateStockItem();
void deleteStockItem();
void viewStaffSchedules();
void addStaff();
void updateStaff();
void deleteStaff();

// Menu functions
void stockManagementMenu();
void staffManagementMenu();
void adminMenu();
void userMenu();

// User functions
void listBranches();
void browseBranchStock();
void buyFromBranch();

#endif // HEADER_H
