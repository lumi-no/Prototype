#include <iostream>
#include <memory>
#include <string>


class Prototype {
public:
    virtual std::shared_ptr<Prototype> clone() const = 0;
    virtual void display() const = 0;
    virtual ~Prototype() = default;
};


class ConcretePrototypeA : public Prototype {
private:
    std::string attribute;

public:
    ConcretePrototypeA(const std::string& attr) : attribute(attr) {}

    std::shared_ptr<Prototype> clone() const override {
        return std::make_shared<ConcretePrototypeA>(*this);
    }

    void display() const override {
        std::cout << "ConcretePrototypeA with attribute: " << attribute << std::endl;
    }
};


class ConcretePrototypeB : public Prototype {
private:
    int value;

public:
    ConcretePrototypeB(int val) : value(val) {}

    std::shared_ptr<Prototype> clone() const override {
        return std::make_shared<ConcretePrototypeB>(*this);
    }

    void display() const override {
        std::cout << "ConcretePrototypeB with value: " << value << std::endl;
    }
};

int main() {
    auto prototypeA = std::make_shared<ConcretePrototypeA>("Prototype A");
    auto prototypeB = std::make_shared<ConcretePrototypeB>(42);

    auto cloneA = prototypeA->clone();
    auto cloneB = prototypeB->clone();

    prototypeA->display();
    cloneA->display();

    prototypeB->display();
    cloneB->display();

    return 0;
}
