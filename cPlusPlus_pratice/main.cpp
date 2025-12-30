#include <iostream>

int main() {
    std::cout << "Hello, World!"; //printf("Hello, World!\n");
    int number;
    std::cout << "please enter a number: \n"; //printf("please enter a number: \n");
    std::cin >> number; //scanf("%d", &number);
    std::cout << "You entered: " << number << std::endl; //printf("You entered: %d\n", number);


    return 0;
}