#include <iostream>
using namespace std;


class Pessoa {
    string name;
    int age;
    int day;
    string month;
    int year;

    void inputData(){
        cout << "\nName: ";
        cin >> name;

        cout << "Age: ";
        cin >> age;

        cout << "Day: ";
        cin >> day;

        cout << "Month: ";
        cin >> month;

        cout << "Year: ";
        cin >> year;
    }

public:
    // construtor correto (mesmo nome da classe, sem tipo)
    Pessoa(){
        inputData();
    }

    void printData(){
        cout << "\n-- " << name << " --\n";
        cout << age << " years";
        cout << "\n" << day << "/" << month << "/" << year << endl;
    }
};




void menu();
void printaOpcoes();

int main()
{
    Pessoa Athus;
    Athus.printData();

    return 0;
}

void menu()
{
    bool looping = true;

    while (looping)
    {
        int op;
        printaOpcoes();
        cin >> op;

        switch (op)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            /* code */
            break;
        case 0:
            looping = false;
            printf("\nExiting...");
            /* code */
            break;
        
        default:
            continue;
        }

    }
}

void printaOpcoes()
{
    printf("\n [1] - op  1");
    printf("\n [2] - op  2");
    printf("\n [3] - op  3");
    printf("\n [4] - op  4");
    printf("\n [5] - op  5");
    printf("\n [6] - op  6");
    printf("\n [7] - op  7");
    printf("\n [0] - exit ");
    printf("\n-----------------------------------------------\n :");
}
