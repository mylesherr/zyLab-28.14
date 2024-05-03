/* Type your code here */

#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
public:
    ItemToPurchase();
    ItemToPurchase(string name, string description, int price = 0, int quantity = 0);

    void SetName(string description);
    string GetName() const;

    void SetDescription(string name);
    string GetDescription() const;

    void SetPrice(int price);
    int GetPrice() const;

    void SetQuantity(int quantity);
    int GetQuantity() const;

    void PrintItemCost() const;
    void PrintItemDescription() const;

private:
    string itemName;
    string itemDescription;
    int itemPrice;
    int itemQuantity;
};

#endif       
