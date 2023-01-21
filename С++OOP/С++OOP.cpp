#include <iostream>
#include <string.h>

int main()
{
    struct Student
    {
        std::string firstName;
        std::string lastName;
        int age;

        Student(std::string firstNameC = "", std::string lastNameC = "", int ageC = 0)
        {
            firstName = firstNameC;
            lastName = lastNameC;
            age = ageC;
        }
        ~Student()
        {
            std::cout << "Your clss is deleted\n";
        }

        void printData()
        {
            std::cout << "Your first name = " << firstName << std::endl;
            std::cout << "Your last name = " << lastName << std::endl;
            std::cout << "Your age  = " << age << std::endl;

        }
        void enterData(std::string firstNameC = "", std::string lastNameC = "", int ageC = 0)
        {
            firstName = firstNameC;
            lastName = lastNameC;
            age = ageC;
        }
    };

    Student firstStudent;
    firstStudent.printData();
}

