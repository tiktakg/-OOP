#include <iostream>

class Shape
{
public:
    virtual int getSquare() = 0;     
    virtual int getPerimeter() = 0;  

    int setNumber()
    {
        int number;
        std::cout << "Write x or y\n";
        std::cin >> number;
        return number;
    }
};

class Square : Shape
{
public:
    int x;
    int y;
    Square()
    {
        x = setNumber();
        y = setNumber();
    }

    int getSquare() override
    {
        return x * y;
    }

    int getPerimeter() override
    {
        return x + y + x + y;
    }
};

template<typename T> T add(T, T);

template<typename T> T add(T a, T b)
{
    return a + b;
}

int main()
{
    Square sq;

    std::cout << "Perimetr - " << sq.getPerimeter() << std::endl;
    std::cout << "Ploshagi - " << sq.getSquare() << std::endl << std::endl;
   
    std::cout << add(4,5) << std::endl;
    std::cout << add(std::string("sdf"), std::string("11ASd")) << std::endl;
    std::cout << add('3', '5') << std::endl;
}


