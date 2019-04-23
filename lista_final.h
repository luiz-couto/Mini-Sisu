#include <iostream>
#include <sstream>

using namespace std;

struct final{

    string course_name;        
    float passing_score; //nota de corte
    
    
    string *classified_names;
    float *classified_grades;

    string *wait_names;
    float *wait_grades;


    final *prox; 

};

class FinalList{

    private:
       
        final *start;
        final *end;
        int number_of_elements;

    public:

        FinalList();
        ~FinalList();
        void InsertElement(string course_name, int number_v, int number_students);
        void InsertInClassified(string name, float grade, int number_v, int position);
        final GetElement(int position);
        void Print();


};





