#include <iostream>
#include <sstream>

using namespace std;

struct course{

    string name;        
    int vacancies;

    course *prox; 

};

class CourseList{

    private:
       
        course *start;
        course *end;
        int number_of_elements;

    public:

        CourseList();
        ~CourseList();
        void InsertElement(string name,int vacancies);
        course GetElement();
        void Print();


};





