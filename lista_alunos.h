#include <iostream>
#include <sstream>

using namespace std;

struct student{

    string name;
    float grade;
    int option_1;        
    int option_2;
    int id;

    int sinal;

    student *prox; 

};

class StudentList{

    private:
       
        student *start;
        student *end;
        int number_of_elements;

    public:

        StudentList();
        ~StudentList();
        void InsertElement(string name, float grade, int option_1, int option_2, int id);
        student GetElement(int position);
        void Print();
        void ExchangeElement(int position);
        student GetElementById(int id, int a);
        void ChangeSinal(int id,int sinal, int a);


};