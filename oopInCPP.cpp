#include <iostream>
#include <string>
#include <vector>

class Person{
    //if outside public, it is implicitly private
private:
    std::string first;
    std::string last;

public:
    //constructor (instantiate)
    Person(std::string first, std::string last): first(first), last(last){}

    //or
    //Person (std::string first, std::string last){
    // this -> first = first;
    // this-> last = last;
    // }

    Person() = default; //(Dont have to pass variables while creating person in main, constructor optional)

    //use a setter to access from private class
    void setFirstName(std::string first) {this -> first = first;}
    void setLastName(std::string last) {this -> last = last;}

    //getter
    std::string getName(){
        return first + " " + last;
    }

    void printFullName() {std::cout << first << " " << last << std::endl;}
    virtual void printInfo(){
        std::cout << "Name: " << getName() << std::endl;
    }

    static void printPeople(std::vector<Person*> people){
        for (Person *person : people){
            person->printInfo();
        }
    }

};

class Employee: public Person{
private:
    std::string department;
public:
    Employee(std::string firstName, std::string lastName, std::string department): Person(firstName, lastName), department (department){}
    Employee() = default;
    std::string getDepartment(){
        return department;
    }
    void setDepartment(std::string department){
        this->department = department;
    }

    void printInfo() override {
        std::cout << "Name: " << getName() << std::endl;
        std::cout << "Department: " << department << std::endl;
    }
};

int main() {

    std::vector<Person*> people;  //use pointers to ensure the derived class methods use their proper methods

    Person k("Kevin", "Cluely");
    Employee e("Edgar", "Maldonado", "Comp sci");

    people.push_back(&k);
    people.push_back(&e);

    Person::printPeople(people);
    Person::printPeople(people);

}


/*          VOCAB
 *  class - describes the structure
 *  object - a specific example of that structure
 *  instance - another name for object
 *  instantiating - creating an object from a class
 *  methods - functions
 *  data members - variables
 */


 /*
  * abstraction - concept where you make something easy by hiding the complicated stuff
  * encapsulation - granting access to private data only through controlled public interfaces
  *         -Uses public, protected & private classes, setters/getters, and constructors
  * inheritance - create derived classes that inherit properties from their parent classes
  *         -Parent class/base class INHERITED FROM
  *         -Child class (derived class) - does the inheriting
  *         -Using a protected class allows the child/inherited classes to directly access protected objects
  *         -YET it still is private from main
  *         -Override - lets you invoke appropriate versions of methods and helps with code readability
  * polymorphism - multiple different objects as their base object type
  *
 */
