/*
You are developing a text editor application that allows users to create and edit documents. The application should also 
provide an undo/redo feature that allows users to revert changes or redo previously undone actions.

Implement the Memento design pattern to create a mechanism for saving and restoring the state of the document. Each time a 
user performs an action, such as inserting or deleting text, a snapshot of the document's state should be created and stored. 
The application should be able to restore the document to a previous state when requested.

Your task is to design the classes and implement the logic to handle the state saving and restoration using the Memento
pattern
*/

#include <iostream>
#include <stack>
#include <string>

class Document {
    std::string _content;

public:
    void setContent(const std::string& content) {
        _content = content;
    }

    std::string getContent() const {
        return _content;
    }

    class Memento {
        std::string _content;
        friend class Document;

    public:
        Memento(const std::string& content) : _content(content) {}
    };

    Memento createMemento() const {
        return Memento(_content);
    }

    void restoreFromMemento(const Memento& memento) {
        _content = memento._content;
    }
};

class Caretaker {
    std::stack<Document::Memento> _mementos;

public:
    void saveState(const Document& document) {
        _mementos.push(document.createMemento());
    }

    void undo(Document& document) {
        if (_mementos.size() >= 2) {
            _mementos.pop();
            document.restoreFromMemento(_mementos.top());
            _mementos.pop();
        }
    }
};

int main() {
    Document doc;
    Caretaker caretaker;

    doc.setContent("Initial content");
    caretaker.saveState(doc);

    doc.setContent("Modified content");
    caretaker.saveState(doc);

    std::cout << "Current content: " << doc.getContent() << std::endl;

    caretaker.undo(doc);
    std::cout << "After undo: " << doc.getContent() << std::endl;

    return 0;
}
