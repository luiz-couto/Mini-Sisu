#include "lista_final.h"
#include <iostream>
#include <sstream>

FinalList::FinalList(){

    this->start = nullptr;
    this->end = nullptr;
    number_of_elements = 0;

};

FinalList::~FinalList(){




};

void FinalList::InsertElement(string course_name, int number_v, int number_students){

    final *novo = new final;
    
    novo->course_name = course_name;
    novo->passing_score = 0;
    
   
    novo->classified_ids = new int[number_v];
    novo->classified_grades = new float[number_v];
    novo->wait_ids = new int[number_students];
    novo->wait_grades = new float[number_students];

    int i;

    for(i=0;i<number_v;i++){                        //Inicializando com -1(ou seja, sem valor real)

        novo->classified_ids[i] = -1;
        novo->classified_grades[i] = -1;

    }

    

    for(i=0;i<number_students;i++){                        //Inicializando com -1(ou seja, sem valor real)

        novo->wait_ids[i] = -1;
        novo->wait_grades[i] = -1;

    }
    

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

void FinalList::Print(){

    final *current = this->start;
    int i;
   
    for(i=0;i<this->number_of_elements;i++){

        cout << "Curso:" << current->course_name << endl;
        int j;
        for(j=0;j<2;j++){
             cout << current->classified_grades[j] << " - " << endl;
        }

        current = current->prox;

    }



};

void FinalList::PrintCourse(int course, int n_vac, int a){

    final *current = this->start;
    int i;

    for(i=0;i<course;i++){
        current = current->prox;
    }

    cout << current->course_name << endl << endl;

    cout << "Classificados" << endl;
    for(i=0;i<n_vac;i++){
        cout << current->classified_ids[i] << " - " << current->classified_grades[i] << endl;
    }
    cout << "Lista de espera" << endl;
    for(i=0;i<a;i++){
        cout << current->wait_ids[i] << " - " << current->wait_grades[i] << endl << endl;
    }


}



final FinalList::GetElement(int position){

    final *current = this->start;
    int i;
    
    for(i=0;i<position;i++){
        current = current->prox;
    }

    return *current;


};

void FinalList::InsertInClassified(int id, float grade, int number_v, int position){

    int i;

    final f = this->GetElement(position);
    


    for(i=0;i<number_v;i++){

        if(f.classified_ids[i] == -1){
          
            f.classified_ids[i] = id;
            f.classified_grades[i] = grade;
            
            //f.passing_score = grade;
            break;
        }

    }



};

void FinalList::InsertInWait(int id, float grade, int position, int a){
    
    int i;

    final f = this->GetElement(position);
    


    for(i=0;i<a;i++){

        if(f.wait_ids[i] == -1){
          
            f.wait_ids[i] = id;
            f.wait_grades[i] = grade;
            
            //f.passing_score = grade;
            break;
        }

    }
}

