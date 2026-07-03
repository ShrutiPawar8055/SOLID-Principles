// S: Single Responsibility Principle: 
// 1. a class should have only one reason to change.
// 2. a class should do only one thing.
// 3. a class can have many methodsbut all should be doing similar work.

#include <iostream>
#include <vector>

using namespace std;

//product class representing any item of any ecommerce.
class Product {
public:
    string name;
    double price;

    Product(string name, double price){
        this->name = name;
        this->price = price;
    }
};

// violating SRP: ShoppingCart is handling multiple responsibilities.
class ShoppingCart{
private: 
    vector<Product*> products;  // (has a relation)

public:
    void addProduct(Product* p){
        products.push_back(p);
    }
    const vector<Product*>& getProducts(){
        return products;
    }

    //1. Calculate total prize in cart.
    double calculateTotal(){
        double total = 0;
        for(auto p: products){
            total += p->price;
        }
        return total;
    }

    // 2. Vioating SRP - Prints Invoice (should be in a separate class)
    void printInvoice(){
        cout << "Shopping Cart Invoice:\n";
        for (auto p : products){
            cout << p->name << " - $" << p->price <<endl;
        }
        cout << "Total: $" << calculateTotal() << endl;
    }

    // 3. Violating SRP - saves to DB (Should be in a separate class)
    void saveToDatabase(){
        cout << "Saving shopping cart to database..." << endl;
    }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 70000));
    cart->addProduct(new Product("Mouse", 500));

    cart->printInvoice();
    cart->saveToDatabase();

    return 0;
}