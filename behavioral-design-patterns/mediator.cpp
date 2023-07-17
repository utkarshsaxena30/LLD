/* 
You are working on a chat application that allows users to participate in group conversations. The application supports 
multiple users who can send messages to each other within a group. However, each message needs to be processed and forwarded 
to all the users in the group.

Implement the Mediator design pattern to create a mediator object that acts as a central communication hub between the users 
in the group. The mediator should receive messages from individual users and distribute them to all other users in the group.

Your task is to design the classes and implement the logic to handle the communication between users using the Mediator 
pattern
*/

#include<iostream>
#include<memory>
#include<vector>

class Mediator {
    public: 
        virtual void notify(std::shared_ptr<User> sender) const = 0;
};

class User {
    std::string _name, _number;
    std::shared_ptr<Mediator> _mediator;

    public: 
        User(std::string name, std::string number) {
            _name = name, _number = number;
        }

        std::string getName() {
            return _name;
        }

        std::string getNumber() {
            return _number;
        }

        void sendMessage() {
            std::cout << "Message sent by: " << _name << std::endl;
            _mediator->notify(std::shared_ptr<User>(this));
        }
};

class ChatGroup: public Mediator {
    std::vector<User> _users;

    public: 
        void addUser() {
            // add user
        }

        void removeUser() {
            // remove user
        }

        void notify(std::shared_ptr<User> sender) const override {
            // notify others
        }
};