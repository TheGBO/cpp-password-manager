#include <string>
#include <iostream>
#include <cstring>
#include <fstream>

//🎺🏴🏴✋🇮🇹🇮🇹GAMER

struct PassValue{
    std::string password;
    std::string user;
};

void mainMenu();

void registerPassword(){
    PassValue pv;
    std::string input;
    std::cout << "Enter An Username:" << std::endl;
    std::cin >> pv.user;
    std::cout << "Enter A Password:" << std::endl;
    std::cin >> pv.password;

    std::ofstream file;
    file.open("password_db", std::ios::app | std::ios::binary);
    file << "user: " << pv.user << "\npass: " << pv.password << "\n---------------------------------" << std::endl;
    file.close();

    std::cout << "Registry saved: \n" << "user: " << pv.user << std::endl << "pass:" << pv.password << "\n" << std::endl;
    mainMenu();
}

void readPasswordDB(){
    std::ifstream file;
    std::string line;
    file.open("password_db");
    if(file.is_open()){
        while(std::getline(file, line)){
            std::cout << line << std::endl;
        }
    }
}

void mainMenu(){
    std::cout << "C++ Password Manager\n" << std::endl;
    std::cout << "Register a Password:w\nRead Passwords:r\nExit:x" << std::endl;
    char input;
    std::cin >> input;
    switch (input)
    {
    case 'w':
        registerPassword();
        break;
    case 'r':
        readPasswordDB();
        mainMenu();
        break;
    case 'x':
        exit(0);
        break;
    default:
        std::cout << "This is not a valid input." << std::endl;
        mainMenu();
    }
}