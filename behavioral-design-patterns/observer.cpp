#include<iostream>
#include<list>

using namespace std;

class Observer {
public:
    virtual void update() = 0;
};

class Observable {
public: 
    virtual void attach(Observer* Observer) = 0;
    virtual void remove(Observer* Observer) = 0;
    virtual void notify() = 0;
};

class EmailObserver: public Observer {
    string email;
public:
    EmailObserver(string email) {
        this->email = email;
    }

    void update() {
        cout << "Sent notification through E-mail to: " << email << endl;
    }
};

class TextObserver: public Observer {
    string phoneNumber;
public: 
    TextObserver(string phoneNumber) {
        this->phoneNumber = phoneNumber;
    }

    void update() {
        cout << "Sent notification through text to: " << phoneNumber << endl;
    }
};

class IPhoneStockObservable: public Observable {
    int stock;
    list<Observer*> observers;
public: 
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void remove(Observer* observer) {
        observers.remove(observer);
    }

    void notify() {
        for(auto observer: observers) {
            observer->update();
        }
    }

    void updateStock(int newStock) {
        if(stock == 0 && newStock != 0) notify();
        stock = newStock;
    }

    IPhoneStockObservable() {
        stock = 0;
    }
};

int main() {
    IPhoneStockObservable observable;

    EmailObserver emailObserver("saxenautkarsh0@gmail.com");
    TextObserver textObserver("8171505570");

    observable.attach(&emailObserver);
    observable.attach(&textObserver);

    observable.updateStock(100);
}