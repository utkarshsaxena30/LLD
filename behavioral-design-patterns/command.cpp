/*
You are developing a remote control application for a smart home system. The application needs to support various devices 
such as lights, thermostats, and door locks. Each device has a set of specific actions that can be performed on it, such as 
turning on/off a light, adjusting the temperature of a thermostat, or locking/unlocking a door.

Implement the Command design pattern to create a set of command objects that encapsulate these actions. Each command object 
should have an execute method that performs the action on the respective device. The remote control application should be 
able to store and execute multiple commands, allowing users to perform a series of actions on different devices.

Your task is to design the classes and implement the logic to handle the command execution using the Command pattern
*/

#include<iostream>
#include<memory>
#include<string>

class Device {
    public: 
        virtual void operationA() const = 0;
        virtual void operationB(std::string param) const = 0;
};

class Light: public Device {
    public: 
        void operationA() const override {
            std::cout << "Operation A performed on lights" << std::endl;
        }
        void operationB(std::string param) const override {
            std::cout << "Operation B performed on lights with param: " << param << std::endl;
        }
};

class Thermostat: public Device {
    public: 
        void operationA() const override {
            std::cout << "Operation A performed on thermostat" << std::endl;
        }
        void operationB(std::string param) const override {
            std::cout << "Operation B performed on thermostat with param: " << param << std::endl;
        }
};

class Command {
    public: 
        virtual void execute() const = 0;
};

class LightCommandA: public Command {
        std::unique_ptr<Light> _light;

    public: 
        LightCommandA(): _light(new Light()) {}

        void execute() const override {
            _light->operationA();
        }
};

class LightCommandB: public Command {
        std::string _param;
        std::unique_ptr<Light> _light;

    public: 
        LightCommandB(std::string param): _light(new Light()) {
            _param = param;
        }

        void execute() const override {
            _light->operationB(_param);
        }
};

class ThermostatCommandA: public Command {
        std::unique_ptr<Thermostat> _thermostat;

    public: 
        ThermostatCommandA(): _thermostat(new Thermostat()) {}

        void execute() const override {
            _thermostat->operationA();
        }
};

class ThermostatCommandB: public Command {
        std::string _param;
        std::unique_ptr<Thermostat> _thermostat;

    public: 
        ThermostatCommandB(std::string param): _thermostat(new Thermostat()) {
            _param = param;
        }

        void execute() const override {
            _thermostat->operationB(_param);
        }
};

int main() {
    std::unique_ptr<LightCommandA> lightCommandA(new LightCommandA());
    std::unique_ptr<LightCommandB> lightCommandB(new LightCommandB("yay"));
    std::unique_ptr<ThermostatCommandA> thermostatCommandA(new ThermostatCommandA());
    std::unique_ptr<ThermostatCommandB> thermostatCommandB(new ThermostatCommandB("hurray"));

    lightCommandA->execute();
    lightCommandB->execute();
    thermostatCommandA->execute();
    thermostatCommandB->execute();
}