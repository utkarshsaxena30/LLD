/*
Imagine you are developing a text editor application that allows users to format and display text. The 
application supports a wide range of font styles and sizes, but you notice that the memory usage is high when 
multiple instances of the same font are created.

Your task is to implement the Flyweight pattern to optimize the memory usage of font objects. Create a Font 
class that represents a font style and size combination. Instead of creating a new Font object each time a 
specific style and size are requested, use a Flyweight Factory to manage a pool of shared Font objects.

The Flyweight Factory should keep track of the existing Font objects and provide a method for clients to request 
a Font object based on a specific style and size. If a Font object with the requested style and size already 
exists in the pool, it should be returned. Otherwise, a new Font object should be created, added to the pool, 
and returned.

Demonstrate the usage of the Flyweight pattern by creating multiple text elements with different font styles and 
sizes. Verify that the memory usage is optimized by reusing shared Font objects instead of creating new ones 
for identical combinations of style and size.
*/

#include<iostream>
#include<string>

class Font {
    private:
        std::string style_, size_;
    public: 
        Font(std::string style, std::string size) {
            style_ = style;
            size_ = size;
        }

        void display() {
            std::cout << "Font Style: " << style_ << ", Font Size: " << size_ << std::endl;
        }
};

class Text {
    private: 
        std::string content_;
    public: 
        Text() {
            content_ = "";
        }

        Text(std::string content) {
            content_ = content;
        }

        void setContent(std::string content) {
            content_ = content;
        }

        std::string getContent() {
            return content_;
        }
};

class FontFlyweight {
    private: 
        std::unique_ptr<Font> font;
    public: 
        FontFlyweight(std::string style, std::string size) {
            font = std::make_unique<Font>(style, size);
        }
        void displayFormattedContent(std::string content) {
            std::cout << "This is " << content << " being displayed in ";
            font->display();
        }
};

class FontFlyweightFactory {
    private:
        std::unordered_map<std::string, FontFlyweight*> cache;
    public: 
        FontFlyweight* getFont(std::string style, std::string size) {
            if(cache.find(style + size) == cache.end()) {
                cache[style + size] = new FontFlyweight(style, size);
            }
            return cache[style + size];
        }
};

class File {
    private: 
        std::vector<Text> texts_;
        FontFlyweight* font_;
    public:
        File(std::string style, std::string size) {
            FontFlyweightFactory *factory = new FontFlyweightFactory();
            font_ = factory->getFont(style, size);
        }
        void addText(std::string content) {
            texts_.push_back(Text(content));
        }
        void displayFile() {
            for(auto text: texts_) {
                font_->displayFormattedContent(text.getContent());
                std::cout << std::endl;
            }
        }
};

int main() {
    File *file = new File("Arial", "28px");
    file->addText("Initialized");
    file->addText("Testing");

    file->displayFile();
}