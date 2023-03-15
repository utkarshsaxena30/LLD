#include<iostream>
#include<memory>

using namespace std;

class DriveStrategy {
public: 
    virtual void drive() = 0;
    virtual ~DriveStrategy() = default;
};

class NormalDrive: public DriveStrategy {
public: 
    void drive() override {
        cout << "Normal Drive Performed" << endl;
    }
};

class SportsDrive: public DriveStrategy {
public: 
    void drive() override {
        cout << "Sports Drive Performed" << endl;
    }
};

class Vehicle {
    unique_ptr<DriveStrategy> driveStrategy_;
    
public: 
    Vehicle(unique_ptr<DriveStrategy> driveStrategy) {
        driveStrategy_ = move(driveStrategy);
    }

    void drive() {
        driveStrategy_->drive();
    }
};

class NormalVehicle: public Vehicle {
public: 
    NormalVehicle(): Vehicle(make_unique<NormalDrive>()) {}
};

class SportsVehicle: public Vehicle {
public: 
    SportsVehicle(): Vehicle(make_unique<SportsDrive>()) {}
};

int main() {
    NormalVehicle normalCar;
    normalCar.drive();
    
    SportsVehicle sportsCar;
    sportsCar.drive();
};