#include <iostream>
#include <string>

using namespace std;

class Button {
public:
    virtual void paint() = 0;
    virtual ~Button() = default;
};

class LinuxButton : public Button {
public:
    void paint() override {
        cout << "Painting a Linux button." << endl;
    }
};

class WindowsButton : public Button {
public:
    void paint() override {
        cout << "Painting a Windows button." << endl;
    }
};

class Checkbox {
public:
    virtual void paint() = 0;
    virtual ~Checkbox() = default;
};

class LinuxCheckbox : public Checkbox {
public:
    void paint() override {
        cout << "Painting a Linux checkbox." << endl;
    }
};

class WindowsCheckbox : public Checkbox {
public:
    void paint() override {
        cout << "Painting a Windows checkbox." << endl;
    }
};

class GUIFactory {
public:
    virtual Button* createButton() = 0;
    virtual Checkbox* createCheckbox() = 0;
    virtual ~GUIFactory() = default;
};

class LinuxFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new LinuxButton();
    }

    Checkbox* createCheckbox() override {
        return new LinuxCheckbox();
    }
};

class WindowsFactory : public GUIFactory {
public:
    Button* createButton() override {
        return new WindowsButton();
    }

    Checkbox* createCheckbox() override {
        return new WindowsCheckbox();
    }
};

void clientCode(GUIFactory &factory) {
    Button *button = factory.createButton();
    Checkbox *checkbox = factory.createCheckbox();
    button->paint();
    checkbox->paint();
    delete button;
    delete checkbox;
}

int main() {
    GUIFactory* factory = nullptr;
    Button* button = nullptr;
    Checkbox* checkbox = nullptr;

    // create a Linux factory and a Linux button and checkbox
    factory = new LinuxFactory();
    clientCode(*factory);

    // create a Windows factory and a Windows button and checkbox
    factory = new WindowsFactory();
    clientCode(*factory);

    delete factory;

    return 0;
}
