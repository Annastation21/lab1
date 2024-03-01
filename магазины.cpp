#include <iostream>
#include <string>
#include <vector>

class Product {
public:
    std::string name;
    double price;
    int rating;

    Product(std::string n, double p, int r) : name(n), price(p), rating(r) {}
};

class Category {
public:
    std::string name;
    std::vector<Product> products;

    Category(std::string n) : name(n) {}
    void addProduct(Product p) {
        products.push_back(p);
    }
};

class Basket {
public:
    std::vector<Product> purchasedProducts;
};

class User {
public:
    std::string username;
    std::string password;
    Basket basket;

    User(std::string u, std::string p) : username(u), password(p) {}
};

int main() {
    Category fruits("Fruits");
    fruits.addProduct(Product("Apple", 1.0, 4));
    fruits.addProduct(Product("Banana", 0.5, 3));

    Category electronics("Electronics");
    electronics.addProduct(Product("Laptop", 1000.0, 5));
    electronics.addProduct(Product("Smartphone", 500.0, 4));

    User user1("user1", "pass123");
    User user2("user2", "pass456");

    std::cout << "Catalog of products:" << std::endl;
    for (const auto& category : { fruits, electronics }) {
        std::cout << category.name << ":" << std::endl;
        for (const auto& product : category.products) {
            std::cout << "  Name: " << product.name << ", Price: $" << product.price << ", Rating: " << product.rating << std::endl;
        }
    }

    user1.basket.purchasedProducts.push_back(fruits.products[0]);
    user2.basket.purchasedProducts.push_back(electronics.products[1]);

    std::cout << "\nShopping purchases:" << std::endl;
    std::cout << user1.username << " bought: " << user1.basket.purchasedProducts[0].name << std::endl;
    std::cout << user2.username << " bought: " << user2.basket.purchasedProducts[0].name << std::endl;

    return 0;
}