#include <iostream>
#include <vector>

using namespace std;

//Product class representing any item in eCommerce.
class Product {
public:
    string name;
    double price;

    Product(string name, double price){
        this->name = name;
        this->price = price;
    }
};

// 1. ShoppingCart: only responsible for cart related business logic.
class ShoppingCart {
private: 
    vector<Product*> products; //Store heap-allocated products

public:
    void addProduct(Product* p){
        products.push_back(p);
    }

    const vector<Product*>& getProducts(){
        return products;
    }

    //Calculates total price in cart.
    double calculateTotal(){
        double total = 0;
        for (auto p : products){
            total += p->price;
        }
        return total;
    }
};

// 2. ShoppingCartPrinter: only responsible for printing invoices
class ShoppingCartPrinter {
private:
    ShoppingCart* cart;  // 'has-a' relation

public:
    ShoppingCartPrinter(ShoppingCart* cart) {
        this->cart = cart;
    }

    void printInvoice() {
        cout << "Shopping Cart Invoice:\n";
        for( auto p: cart->getProducts()){
            cout << p->name << " -$" << p->price << endl;
        }

        cout << "Total: $" << cart->calculateTotal() << endl;
    }
};

// 3. ShoppingCartStorage: only resp for saving cart to DB
class ShoppingCartStorage{
private:
    ShoppingCart* cart;

public:
    ShoppingCartStorage(ShoppingCart* cart){
        this->cart = cart;
    }
    void savetoDatabase(){
        cout << "Saving to Database...\n";
    }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 70000));
    cart->addProduct(new Product("Mouse", 500));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage* db = new ShoppingCartStorage(cart);
    db->savetoDatabase();

    return 0;
}