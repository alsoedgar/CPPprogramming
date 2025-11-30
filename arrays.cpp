//
// Created by maldo on 11/29/2025.
//

#include <iostream>
#include <array>

void printArray(const std::array<int, 5> &arr){
    for (int num : arr){
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main(){
    //static data structure that requires size to be declared at before runtime
    //is used by the STACK, size can not be changed, however values can be modified
    //

    std::array<int, 5> arr;
    arr.fill(1); //fills all values with the number 1

    printArray(arr);

    std::cout << "Is array empty?: " << (arr.empty() ? "Empty" : "Not empty ");

    std::cout << "\nvalue at end " << arr.back() << std::endl;
    std::cout << "checking value at index 2: " << arr.at(2) << std::endl;
    //std::cout << "value at index 10" << arr.at(10) << std::endl; throws error because 10 can NOT be accessed

    std::cout << "size of array: " << arr.size() << std::endl;
    std::cout << "Creating new array filled with 10...\n";
    std::array<int, 5> newarr;
    newarr.fill(10);
    printArray(newarr);

    arr.swap(newarr);
    std::cout << "swapping two arrays..." << "\nprinting original array...\n";
    printArray(arr);

}