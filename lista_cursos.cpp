#include "lista_cursos.h"
#include <iostream>
#include <sstream>

CourseList::CourseList(){

    this->start = nullptr;
    this->end = nullptr;
    number_of_elements = 0;

};

CourseList::~CourseList(){




};

void CourseList::InsertElement(string name,int vacancies){

    course *novo = new course;
    novo->name = name;
    novo->vacancies = vacancies;

    if(this->number_of_elements == 0){
        
        novo->prox = nullptr;
        this->start = novo;
        this->end = novo;

    }else{

        this->end->prox = novo;
        novo->prox = nullptr;
        this->end = novo;

    }

    this->number_of_elements++;

};

course CourseList::GetElement(int position){

    course *current = this->start;
    int i;
    
    for(i=0;i<position;i++){
        current = current->prox;
    }

    return *current;


};

