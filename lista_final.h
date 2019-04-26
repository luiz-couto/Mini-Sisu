#include <iostream>
#include <sstream>

using namespace std;

struct final{

    string course_name;        
    float passing_score; //nota de corte
    
    
    int *classified_ids;
    float *classified_grades;

    int *wait_ids;
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
        void InsertInClassified(int id, float grade, int number_v, int position);
        void InsertInWait(int id, float grade, int position,int a);
        final GetElement(int position);
        void Print();
        void PrintCourse(int course,int n_vac, int a);


};





