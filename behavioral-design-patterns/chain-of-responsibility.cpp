/*
You are tasked with developing a system that processes different types of customer support tickets. The system should handle 
tickets based on their urgency level, and each level should be processed by a specific team of support agents. The urgency 
levels are as follows: Low, Medium, High, and Critical.

Implement the Chain of Responsibility design pattern to create a chain of support agents. Each agent in the chain should 
have the ability to process a ticket of a specific urgency level. If an agent receives a ticket that they can handle, 
they process it and mark it as resolved. If an agent receives a ticket that they cannot handle, they pass it on to the next 
agent in the chain.

Your task is to design the classes and implement the logic to handle the support ticket processing using the Chain of 
Responsibility pattern. 
*/

#include<iostream>
#include<memory>

enum DIFFICULTY {
    LOW,
    MEDIUM,
    HIGH,
    CRITICAL
};

class Ticket { 
    public:
        DIFFICULTY _difficulty;
        Ticket(DIFFICULTY difficulty): _difficulty(difficulty) {}
};

class TicketHandler {
        std::shared_ptr<TicketHandler> _next;

    public: 
        std::shared_ptr<TicketHandler> setNext(std::shared_ptr<TicketHandler> next) {
            _next = next;
            return next;
        }

        void handleNext(Ticket ticket) const {
            if(!_next) return;
            _next->handle(ticket);
        }

        virtual void handle(Ticket ticket) const = 0;
};

class LowTicketHandler: public TicketHandler {
    public:
        void handle(Ticket ticket) const override {
            if(ticket._difficulty == LOW) {
                std::cout << "Ticket handled by Low Ticket Handling Agent" << std::endl;
                return;
            }
            handleNext(ticket);
        }
};

class MediumTicketHandler: public TicketHandler {
    public:
        void handle(Ticket ticket) const override {
            if(ticket._difficulty == MEDIUM) {
                std::cout << "Ticket handled by Medium Ticket Handling Agent" << std::endl;
                return;
            }
            handleNext(ticket);
        }
};

class HighTicketHandler: public TicketHandler {
    public:
        void handle(Ticket ticket) const override {
            if(ticket._difficulty == HIGH) {
                std::cout << "Ticket handled by High Ticket Handling Agent" << std::endl;
                return;
            }
            handleNext(ticket);
        }
};

class CriticalTicketHandler: public TicketHandler {
    public:
        void handle(Ticket ticket) const override {
            if(ticket._difficulty == CRITICAL) {
                std::cout << "Ticket handled by Critical Ticket Handling Agent" << std::endl;
                return;
            }
            handleNext(ticket);
        }
};

int main() {
    std::shared_ptr<LowTicketHandler> lowAgent(new LowTicketHandler());
    std::shared_ptr<MediumTicketHandler> mediumAgent(new MediumTicketHandler());
    std::shared_ptr<HighTicketHandler> highAgent(new HighTicketHandler());
    std::shared_ptr<CriticalTicketHandler> criticalAgent(new CriticalTicketHandler());

    lowAgent->setNext(mediumAgent)->setNext(highAgent)->setNext(criticalAgent);

    Ticket ticket(CRITICAL);
    lowAgent->handle(ticket);
}