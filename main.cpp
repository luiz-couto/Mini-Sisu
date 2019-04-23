//MINI-SISU - ATIVIDADE PRÁTICA Nº1 - ESTRUTURA DE DADOS
//NOME: LUIZ FELIPE COUTO GONTIJO

#include "lista_cursos.h"
#include "lista_alunos.h"
#include "lista_final.h"

#include <iostream>
#include <sstream>

using namespace std;

void OrdenaListaAlunos(StudentList student_list, int n, int a){

    int i;
    int j;


   
    for(i=0;i<n;i++){

        for(j=1;j<a;j++){
           
            student current = student_list.GetElement(j);
            
            if(current.option_1 == i){
               
                int k = j-1;
               
                while(k >= 0){   //-1,Pois deve-se comparar com a primeira posição também
               
                    student prev = student_list.GetElement(k);
                
                    if(prev.option_1 <= i){
                        
                        if(prev.option_1 == i){
                           
                            if(prev.grade < current.grade){
                                student_list.ExchangeElement(k);
                            }
                        }
                        
                        break;
                    }
                    else{
                        student_list.ExchangeElement(k);
                    }

                    k = k-1;
                }
            }
            
        }





    }

    student_list.Print();
    cout << endl;

}


int main(){

    CourseList course_list;
    StudentList student_list;
    FinalList final_list;

    int n = 3;
    int a = 9;
    
    course_list.InsertElement("Mineração de Gelo",12);
    course_list.InsertElement("Computação de Gelo",40);
    course_list.InsertElement("Medicina de Gelo",120);

    //course c = course_list.GetElement(0);
    //cout << "Name c:" << c.name << endl;


    //course_list.Print();

    student_list.InsertElement("C",500,0,2);
    student_list.InsertElement("D",750,1,0);
    student_list.InsertElement("E",700,1,2);
    student_list.InsertElement("A",700,0,1);
    student_list.InsertElement("G",800,2,0);
    student_list.InsertElement("I",700,2,0);
    student_list.InsertElement("B",650,0,1);
    student_list.InsertElement("F",650,1,0);
    student_list.InsertElement("H",750,2,1);
    

    //student_list.ExchangeElement(1); // Muda o elemento da posição informada com o elemento da próxima posição

    student_list.Print();

    std::cout << endl;

    OrdenaListaAlunos(student_list,n,a);
    
    // student_list.ExchangeElement(1);
    // student_list.ExchangeElement(0);
    
   
    //student_list.Print();





    return 0;

}



