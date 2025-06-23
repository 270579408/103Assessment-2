#ifndef HEADER1_H
#define HEADER1_H

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
// declaration
class Branch;

// Global variables

extern string currentUsername;
extern string currentUserRole;
extern unordered_map<string, Branch> branches;

// Structure definitions

struct User {
	string username;
	string password;
	string role;
};
struct StockItem {
	string name;
	int quantity;
	double price;
	StockItem();
	StockItem(string n, int q, double p);
	bool isLowStock() const;
	bool reduceQuantity(int amount);
	void display(bool showLowStock = false) const;
};
struct Staff {
	string name;
	string role;
	string schedule;
	Staff();
	Staff(string n, string r, string s);
	void display() const;
};
class Branch {
private:
	string toLowerCase(string str);
public:
	vector<StockItem> stock;
	vector<Staff> staff;
	Branch();
	void addStockItem(StockItem item, bool silent = false);
	StockItem* findStockItem(string name);
	bool removeStockItem(string name);
	void displayStock(bool showLowStock = false);
	void addStaff(Staff member, bool silent = false);
	Staff* findStaff(string name);
	bool removeStaff(string name);
	void displayStaff();
};
// Function declarations 
void loadstockFromFile();
void saveStockToFile();
void loadStaffFromFile();
void saveStaffToFile();
bool isVaildText(const string& input);
void clearInput();
void printSeparator(char c, int length);
bool getConfirmation(string message);
void initializeBranches();
vector<User> loadUsers();
void saveUser(const User& user);
void saveAllUsers(const vector<User>& users);
bool userExists(const vector<User>& users, const string& username);
void registerUser();
void loginUser();
void promoteUserToAdmin();
void viewStockLevels();
void addStockItem();
void updateStockItem();
void deleteStockItem();
void viewStaffSchedules();
void addStaff();
void updateStaff();
void deleteStaff();
void stockManagementMenu();
void staffManagementMenu();
void adminMenu();
void userMenu();
void listBranches();
void browseBranchStock();
void buyFromBranch();

#endif
