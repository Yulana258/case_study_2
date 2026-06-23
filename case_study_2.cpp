#include <iostream>
#include <string>

class Animal {
protected:
    std::string name_;
public:
    Animal(std::string name) : name_(name){
        std::cout <<"[Base] Конструктор Animal: " << name_ << "\n";
    }
    virtual ~Animal() {
        std::cout << "[Base] Деструктор Animal: " <<name_ << "\n";
    }
    virtual void speak() const {
        std::cout << name_ << " издает звук.\n";
    }
    void eat() const {
        std::cout << name_ << " ест рыбу.\n";
    }
}; // точка c запятой здесь объязательна
class Cat: public Animal {
private:
    std::string breed_;
public:
    Cat(std::string name, std::string breed)
        : Animal(name), breed_(breed) {
        std::cout << "[Derived] Конструктор Cat: " << name_ << ", порода:" <<breed_ << "\n";
}
    ~Cat() {
        std::cout << "[Derived] Деструктор Cat: " << name_ << "\n";
    }
    void speak() const {
    std::cout << name_ << " мяукает: Мяу!\n";
    }
    void fetch() const {
        std::cout << name_ << " бегает за мышью.\n";
    }
    // Метод eat внутри класса Cat, поэтому он увидит name_
    void eat(const std::string& food) const {
        std::cout << name_ << " ест " << food << ".\n";
    }
}; // точка c запятой здесь объязательна
int main() {
    std::cout << "--- Начало работы ---\n\n";
    Animal generic("Филлимон");
    Cat myCat("Филл", "дворняга");
    std::cout << "\n--- Вызовы методов ---\n\n";
    generic.speak();
    generic.eat();
    myCat.speak();
    myCat.eat("рыбу");
    // явное приведение типа, для устранения ошибки "no matching function"
    myCat.eat(std::string("рыбу"));
    myCat.fetch();
    std::cout << "\n--- Полиморфизм ---n\n";
    Animal* ptr = &myCat;
    ptr->speak(); //  Виртуальный: вызовет Cat::speak()
    ptr->eat(); // He виртуальный: вызовет Animal::eat()
    std::cout << "\n--- Конец работы ---\n";
    return 0;
}