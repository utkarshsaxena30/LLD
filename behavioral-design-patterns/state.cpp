/*
You are developing a vending machine application. The vending machine can be in different states, such as "NoSelection", 
"HasSelection", and "SoldOut". The machine allows users to select a product, insert coins, and dispense the selected product.
However, the machine should only allow certain actions based on its current state. For example, inserting coins should only 
be allowed when the machine is in the "HasSelection" state, and dispensing the product should only be allowed when the 
machine is in the "SoldOut" state.

Implement the State design pattern to represent the different states of the vending machine and define the actions that 
can be performed in each state. Allow the vending machine to transition between states based on the user's actions.

Your task is to design the classes and implement the logic to handle the state transitions using the State pattern.
*/

#include <iostream>
#include <stack>
#include <string>

class Product {
    std::string name;
    int coins;

public:
    Product(std::string name, int coins) {
        this->name = name;
        this->coins = coins;
    }

    std::string getName() {
        return name;
    }

    int getCoins() {
        return coins;
    }
};

class VendingMachineState {
public: 
    virtual void insertCoins() = 0;
    virtual void selectProduct(Product p) = 0;
    virtual void dispenseProducts() = 0;
};

class VendingMachineContext: public VendingMachineState {
    std::shared_ptr<VendingMachineState> state;
    std::vector<Product> selectedProducts;
    int coins;

    friend class NoSelectionState;
    friend class HasSelectionState;
    friend class SoldOutState;

public:
    VendingMachineContext() {
        state = std::shared_ptr<VendingMachineState>(new NoSelectionState(this));
        selectedProducts = std::vector<Product>();
        coins = 0;
    }

    void changeState(std::string newState) {
        // change state based on input
    }

    void insertCoins() override {
        state->insertCoins();
    }

    void selectProduct(Product p) override {
        state->selectProduct(p);
    }

    void dispenseProducts() override {
        state->dispenseProducts();
    }
};

class NoSelectionState: public VendingMachineState {
    std::shared_ptr<VendingMachineContext> _context;
public:
    NoSelectionState(VendingMachineContext *context): _context(context) {}
    void insertCoins() {
        std::cerr << "Cannot insert coins, please select a product first";
    }
    void selectProduct(Product p) {
        _context->selectedProducts.push_back(p);
        _context->changeState("has_selection");
    }
    void dispenseProducts() {
        std::cerr << "Cannot dispense products, please select a product first";
    }
};

class HasSelectionState: public VendingMachineState {
    std::shared_ptr<VendingMachineContext> _context;
public: 
    HasSelectionState(VendingMachineContext *context): _context(context) {}
    void insertCoins() {
        _context->coins = 1;
        _context->changeState("sold_out");
    }
    void selectProduct(Product p) {
        std::cerr << "Cannot select more products, please pay for existing product first";
    }
    void dispenseProducts() {
        std::cerr << "Cannot dispense products, please insert coins";
    }
};

class SoldOutState: public VendingMachineState {
    std::shared_ptr<VendingMachineContext> _context;
public: 
    SoldOutState(VendingMachineContext *context): _context(context) {}
    void insertCoins() {
        std::cerr << "Please dispense existing products first";
    }
    void selectProduct(Product p) {
        std::cerr << "Please dispense existing products first";
    }
    void dispenseProducts() {
        // dispense products
        _context->changeState("no_selection");
    }
};