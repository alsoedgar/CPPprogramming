//
// Created by maldo on 11/29/2025.
//

#include <iostream>
#include <vector>

void printList(const std::vector<std::string> &cars){
    for (const auto &car : cars){
        std::cout << car << " ";
    }
    std::cout << std::endl;
}

void printListInts(const std::vector<int> &ints){
    for (const int &x: ints){
        std::cout << x << " - ";
    }
    std::cout << std::endl;
}

int main(){
    //vectors are resizable arrays that use memory from the heap
    //allows them to actively remove, add, and access items in a contiguous list

    std::vector<std::string> cars = {"Volvo", "Tesla", "BMW", "Camero"};

    std::cout << "items in list: " << cars.size() << "\n";

    printList(cars);

    std::cout << "Add a car: ";
    std::string inputCar;
    std::cin >> inputCar;

    cars.push_back(inputCar);

    std::cout << "items in list: " << cars.size() << "\n";
    printList(cars);

    std::cout << "Car at index 1 = " << cars.at(1) << std::endl;

    std::cout << "Is list empty? ->  " << (cars.empty() ? "yes" : "no");

    std::cout << std::endl;
    std::cout << "Removing last item...\n"; cars.pop_back();
    printList(cars);

    std::cout << "Max amount of items in list: " << cars.max_size() << std::endl;
    std::cout << "clearing entire list...\n";
    cars.clear();
    std::cout << "List: ";
    printList(cars);

    std::cout << "creating a new vector of with a bigger memory allocation...\n";
    std::vector<int> ints;
    std::cout << "Capacity of ints in list: " << ints.capacity() << std::endl;
    ints.reserve(100);
    ints.resize(100, 0);
    std::cout << "Capacity of ints in list now: " << ints.capacity() << std::endl;

    for (int &x : ints){
        x = 0;
    }

    std::cout << "Printing list of integers";
    printListInts(ints);

    std::cout << "Resizing ints vector..\n";
    ints.resize(10);
    printListInts(ints);
}