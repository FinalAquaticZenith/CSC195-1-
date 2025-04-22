#pragma once
class Shape {
public:
    Shape() {}
    ~Shape() {}

    virtual float Area() { return 0; };
};
