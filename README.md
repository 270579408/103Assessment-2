# 103Assessment-2
Aotearoa Treasures Staff/Inventory Management System
This is a console application of Aotearoa Treasure’s allowing them to have a system that will let them access stock inventory, staff and it also ensures that the users goes through a system authentication. It also handles customer transactions in the three branches in New Zealand. 

Features
User Management
Registration with usernames/passwords: new users are allowed to authenticate their account with username/password allowing users to access their accounts for later transactions and keep their details in.

This also has Role Based Access Control(RBAC) Two user roles regular Users and Admins
Promotion to Admin: Active admins are able to make ordinary users into admins
To have a safe entry: Minimum length of password check and attempts the password limit have been added.

Branch Management
The system manages three predefined branches:
Auckland
Wellington
Christchurch

Inventory Management for the role Admin:

Stock Tracking: This allows the admin to track the stock and prices of all the branches
Low Stock Alerts: when an item counts less than 5 units automatic warnings are issued.

Product Configuration:
This allows admins to add new products to branches, update existing product quantities and prices, remove products from inventory and view the stock levels across all branches
Staff Management for the role Admin:
Staff Records: This will allow admins to create and keep records of staffs with names, roles and schedule.
Staff Configurations:
This allows the admin to create new staff members to branches, update existing staff details (role/schedule),remove staff members and view staff schedules by branch.

Customer Features for the role User:
Branch Browsing: This allows the users to view the current available branches and their product catalogs.
Product Shopping: This allows the user to be able to purchase items with real time inventory updates
Transaction Processing: This will allow the users to see the calculated costs and ask if they are to confirm purchases.

Data Structures
User Struct: This will be storing the username, password, and role information
StockItem Struct: This will be handling  the name of the product, quantity, price and the low-stock detection
Staff Struct: This will contain the employee name, role, and schedule details
Branch Class: This will encapsulate any  branch specific stock and staff collections

File Persistence:
The system uses three text files for data persistence ,users.txt this contains the user account information, stock.txt this contains the product inventory across all branches and staff.txt this contains the employee records for all branches.

Functions
StockItem Class
isLowStock(): Detects items with quantity < 5
reduceQuantity(): This will be decreasing the stock during purchases
display(): This will display the product information with optional low-stock warnings
Branch Class
addStockItem(): This will adds or updates product inventory
findStockItem(): Locates products by name (case-insensitive)
removeStockItem(): Removes products from inventory
addStaff(): Adds new employees (prevents duplicates)
findStaff(): Locates staff members by name
removeStaff(): Removes employees from records

Main Menu
Register: Create new user account
Login: Access system with the existing login credentials
Exit: This will close application

Admin Menu
User Promotion: This will promote regular users to admin status
Staff Management: Access staff administration submenu
Stock Management: Access inventory administration submenu
Logout: Return to main menu

User Menu
List Branches: Display all available store locations
Browse Products: View inventory at specific branches
Buy Products: Purchase items with inventory updates
Logout: Return to main menu
Security Features
Password minimum length requirement (4 characters)
Login attempt limiting (maximum 3 attempts)
Input validation for text fields (alphabetic characters only)
Confirmation prompts for destructive operations
Default Data
The system initializes with sample data including:
Products: Hand Cream, Kiwi Toys, Fridge Magnets, Wool Scarves
Staff Members: Managers, Cashiers, Sales Assistants, Craftspeople
Admin Account: Username: "admin", Password: "admin123"
File Dependencies
Standard C++ libraries iostream, fstream, string, vector, sstream, unordered_map, limits, algorithm, iomanip, cmath
Custom header file: "Header1.h"

To be able to compile:
C++ is required to compile.

Usage Notes
The branch names are case sensitive and the names of the products and staff support alphabetic characters and spaces only
The system automatically saves changes to files after modifications and the low stock alerts are released when stock is below 5 units
