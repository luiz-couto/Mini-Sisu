#include "lista_alunos.h"
#include <iostream>
#include <sstream>

StudentList::StudentList(){

    this->start = nullptr;
    this->end = nullptr;
    number_of_elements = 0;

};

StudentList::~StudentList(){




};

void StudentList::InsertElement(string name, float grade, int option_1, int option_2, int id){

    student *novo = new student;
    novo->name = name;
    novo->grade = grade;
    novo->option_1 = option_1;
    novo->option_2 = option_2;
    novo->sinal = 0;
    novo->id = id;

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

void StudentList::Print(){

    student *current = this->start;
    int i;
   
    for(i=0;i<this->number_of_elements;i++){

        cout << "Nome do aluno:" << current->name << endl;
        cout << "Nota:" << current->grade << endl;
        cout << "OP 1:" << current->option_1 << endl;
        cout << "OP 2:" << current->option_2 << endl;

        current = current->prox;

    }



};

student StudentList::GetElement(int position){

    student *current = this->start;
    int i;
    
    for(i=0;i<position;i++){
        current = current->prox;
    }

    return *current;


};

student StudentList::GetElementById(int id, int a){

    student *current = this->start;
    int i;
    
    for(i=0;i<a;i++){
        
        if(current->id == id){
            break;
        }
        current = current->prox;
    }

    return *current;


};

void StudentList::ChangeSinal(int id, int sinal, int a){

    student *current = this->start;
    int i;
    
    for(i=0;i<a;i++){
        
        if(current->id == id){
            current->sinal = sinal;
            break;
        }
        current = current->prox;
    }
}


void StudentList::ExchangeElement(int position){


    student *s = this->start;
    int i;
    
    for(i=0;i<position;i++){
        s = s->prox;
    }
    
    if(position == 0){
       
        student *s_prox = s->prox;
    
        s->prox = s_prox->prox;
        s_prox->prox = s;
        this->start = s_prox;
  
    }else{

        student *s_prox = s->prox;
        
        student *s_prev = this->start;
        for(i=0;i<position-1;i++){
            s_prev = s_prev->prox;
        }

        s->prox = s_prox->prox;
        s_prox->prox = s;
        s_prev->prox = s_prox;
        
        if(s->prox == nullptr){
            this->end = s;
        }

    }




}

