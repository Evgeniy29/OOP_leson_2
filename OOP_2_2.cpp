#include <iostream>

class Fruit  {

private:
protected: 
    
    std::string name;
    std::string color;

    Fruit() { }
    
public:
	std::string getName() const { return name; }
    std::string getColor() const { return color; }

    
    Fruit( std::string _name, std::string _color) :
        name(_name), color(_color) {
       
    }
    Fruit(const Fruit& a) : name(a.name), color(a.color)  { }
 
};

class Apple : public Fruit { 
public:
    Apple( std::string _name="apple", std::string _color="red") {
        
        this->name = _name;
        this->color = _color;
        
    }
   
};

class Banana : public Fruit {
public:
    Banana( std::string _name="banana", std::string _color="yellow") :
        Fruit( _name, _color) { }
};


class GrannySmith : public Apple {
public:
    GrannySmith( std::string _name="Granny Smith apple", std::string _color="green") : 
        Apple( _name, _color ) {	}
    
};

int main(int argc, const char** argv) { 
	Apple a;
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    
    return 0; 
}
