#pragma once

#include <iostream>

void Println(std::string msg) {
    std::cout << msg << std::endl;
}

void Print(std::string msg) {
    std::cout << msg;
}

void PrintErr(std::string msg) {
    std::cerr << "[ERROR]: " << msg << std::endl;
}

void PrintInfo(std::string msg) {
    std::cout << "[INFO]: " << msg << std::endl;
}
