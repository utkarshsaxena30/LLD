/* 
Imagine you are developing a drawing application that supports different shapes, such as circles and squares, 
and different rendering modes, such as raster and vector. You want to decouple the abstraction of shapes from 
their implementation and provide the ability to easily switch between different rendering modes.

Your task is to implement the Bridge pattern to achieve this decoupling. Create an abstraction class called 
Shape that defines the common interface for all shapes. Then, create implementation classes Circle and Square 
that inherit from the Shape class and represent specific shapes.

Next, create an implementation interface called Renderer that defines the common methods for rendering shapes. 
Implement two concrete classes, RasterRenderer and VectorRenderer, that provide different rendering 
implementations.

Finally, modify the Shape class to include a reference to a Renderer object, and delegate the rendering 
operations to the implementation classes. This allows you to switch the rendering mode at runtime by providing 
different implementations of the Renderer interface to the shapes.

After implementing the Bridge pattern, demonstrate its usage by creating instances of different shapes and 
rendering them using different rendering modes.
*/
#include<iostream>

class ShapeRenderer {
    public:
        virtual void renderShape() const = 0;
};

class RasterRenderer: public ShapeRenderer {
    public: 
        void renderShape() const override {
            std::cout << "Rendered shape using Rasters" << std::endl;
        }
};

class VectorRenderer: public ShapeRenderer {
    public:     
        void renderShape() const override {
            std::cout << "Rendered shape using Vectors" << std::endl;
        }
};

class Shape {
    int sides;
    public:
        virtual void render() const = 0;
        virtual ~Shape() = default;
};

class Circle: public Shape {
    ShapeRenderer *renderer = NULL;
    public:
        Circle(ShapeRenderer *renderer) {
            this->renderer = renderer;
        }
        void render() const override {
            std::cout << "Circle Rendered" << std::endl;
            renderer->renderShape();
        }
};


class Square: public Shape {
    ShapeRenderer *renderer = NULL;
    public: 
        Square(ShapeRenderer *renderer) {
            this->renderer = renderer;
        }
        void render() const override {
            std::cout << "Square Rendered" << std::endl;
            renderer->renderShape();
        }
};

int main() {
    Circle *circle = new Circle(new RasterRenderer());
    circle->render();

    Square *square = new Square(new VectorRenderer());
    square->render();
}
