#include <iostream>
#include <string>
#include <limits>
#include "ShoppingCart.h"

using namespace std;

void PrintMenu() {
   
    cout << "MENU\n"
         << "a - Add item to cart\n"
         << "d - Remove item from cart\n"
         << "c - Change item quantity\n"
         << "i - Output items' descriptions\n"
         << "o - Output shopping cart\n"
         << "q - Quit\n\n";
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
    switch(option) {
        case 'a': {
            string name, description;
            int price, quantity;
            cout << "ADD ITEM TO CART\n";
            cout << "Enter the item name:\n";
            getline(cin, name);
            cout << "Enter the item description:\n";
            getline(cin, description);
            cout << "Enter the item price:\n";
            cin >> price;
            cout << "Enter the item quantity:\n";
            cin >> quantity;
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer after numeric input

            ItemToPurchase newItem(name, description, price, quantity);
            theCart.AddItem(newItem);
            break;
        }
        case 'd': {
            string name;
            cout << "REMOVE ITEM FROM CART\n";
            cout << "Enter name of item to remove:\n";
            getline(cin, name);
            theCart.RemoveItem(name);
            break;
        }
        case 'c': {
            string name;
            int quantity;
            cout << "CHANGE ITEM QUANTITY\n";
            cout << "Enter the item name:\n";
            getline(cin, name);
            cout << "Enter the new quantity:\n";
            cin >> quantity;
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer after numeric input

            ItemToPurchase item;
            item.SetName(name);
            item.SetQuantity(quantity);
            theCart.ModifyItem(item);
            break;
        }
        case 'i': {
            cout << "OUTPUT ITEMS' DESCRIPTIONS\n";
            theCart.PrintDescriptions();
            break;
        }
        case 'o': {
            cout << "OUTPUT SHOPPING CART\n";
            theCart.PrintTotal();
            break;
        }
        case 'q':
            break;
        default:
            cout << "Invalid option. Please choose again.\n";
            break;
    }
}

int main() {
    string customerName, currentDate;
    bool shouldPrintMenu = true;

    cout << "Enter customer's name:\n";
    getline(cin, customerName);
    cout << "Enter today's date:\n";
    getline(cin, currentDate);

    cout << "\nCustomer name: " << customerName << endl;
    cout << "Today's date: " << currentDate << endl;

    ShoppingCart theCart(customerName, currentDate);
    char menuOption = ' ';

    do {
        if (shouldPrintMenu) {
            cout << endl;
            PrintMenu();
        }
        cout << "Choose an option:\n";
        cin >> menuOption;
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

        if (menuOption == 'a' || menuOption == 'd' || menuOption == 'c' || 
            menuOption == 'i' || menuOption == 'o' || menuOption == 'q') {
            ExecuteMenu(menuOption, theCart);
            shouldPrintMenu = true; // Reprint menu next loop
        } else {
            shouldPrintMenu = false; // Do not reprint menu
        }
    } while (menuOption != 'q');

    return 0;
}

