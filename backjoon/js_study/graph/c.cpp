#include<iostream>
#include<string>
#include<sstream>

int main() {
        std::istringstream iss("test 123 123hah ahha");
        std::string str, str2;
        int str1;
        int inta;

        std::cout<< iss.str() <<std::endl;
        iss >> str;
        iss >> str1 >> str2 >> inta;
        std::cout<<"str  : "<< str  <<std::endl;
        std::cout<<"str1 : "<< str1 <<std::endl;
        std::cout<<"str2 : "<< str2 <<std::endl;
        std::cout<<"inta : "<< inta <<std::endl;

}

