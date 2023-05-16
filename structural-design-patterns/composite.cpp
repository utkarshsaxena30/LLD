/* 
Imagine you are developing a file system application that supports directories and files. You want to provide 
a way to treat both directories and files uniformly and allow clients to perform operations on them without 
needing to distinguish between the two.

Your task is to implement the Composite pattern to achieve this behavior. Create an abstract base class called 
FileSystemComponent that defines the common interface for both directories and files. This interface should 
include methods for operations such as displayInfo().

Next, create two concrete classes: Directory and File. The Directory class should inherit from FileSystemComponent 
and include a collection to hold its child components, which can be both directories and files. The File class 
should also inherit from FileSystemComponent and represent a file in the file system.

Modify the FileSystemComponent class to include methods for adding and removing child components. These methods 
should be implemented in the Directory class to manage its collection of child components.

Finally, demonstrate the usage of the Composite pattern by creating a directory and adding files and directories 
as its children. Perform operations on the composite structure, such as displaying information about each component 
recursively.
*/

#include<iostream>
#include<string>
#include<list>

class FileSystemComponent {
    public: 
        virtual std::string displayInfo() const = 0;
        virtual void addComponent(FileSystemComponent *component) = 0;
        virtual void removeComponent(FileSystemComponent *component) = 0;
        virtual ~FileSystemComponent() = default;
};

class Directory: public FileSystemComponent {
    protected:
        std::string name_; 
        std::list<FileSystemComponent*> children_;
    public:
        Directory(std::string name) {
            name_ = name;
        }
        std::string displayInfo() const override {
            std::string info = name_ + ": ";
            for(auto child: children_) {
                info += child->displayInfo();
                if(child != children_.back()) info += ", ";
            }
            info += "\n";
            return info;
        }
        void addComponent(FileSystemComponent *component) override {
            children_.push_back(component);
        }
        void removeComponent(FileSystemComponent *component) override {
            children_.remove(component);
            delete component;
        }
};

class File: public FileSystemComponent {
    protected: 
        std::string name_;
    public:
        File(std::string name) {
            name_ = name;
        }
        std::string displayInfo() const override {
            return name_;
        }
        void addComponent(FileSystemComponent *component) override {
            throw std::runtime_error("Cannot add component to leaf");
        }
        void removeComponent(FileSystemComponent *component) override {
            throw std::runtime_error("Cannot add component to leaf");
        }
};

int main() {
    Directory *root = new Directory("ROOT");

    Directory *d1 = new Directory("D1");
    Directory *d11 = new Directory("D11");
    Directory *d12 = new Directory("D12");
    File *l111 = new File("L111");
    File *l112 = new File("L112");
    d11->addComponent(l111);
    d12->addComponent(l112);
    d1->addComponent(d11);
    d1->addComponent(d12);

    Directory *d2 = new Directory("D2");
    File *l21 = new File("L21");
    File *l22 = new File("L22");
    d2->addComponent(l21);
    d2->addComponent(l22);

    Directory *d3 = new Directory("D3");
    File *l31 = new File("L31");
    File *l32 = new File("L32");
    File *l33 = new File("L33");
    d3->addComponent(l31);
    d3->addComponent(l32);
    d3->addComponent(l33);

    root->addComponent(d1);
    root->addComponent(d2);
    root->addComponent(d3);

    std::cout << root->displayInfo();

    std::cout << "Remove D1" << std::endl;
    root->removeComponent(d1);
    std::cout << root->displayInfo();
}