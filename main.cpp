//MINI-SISU - ATIVIDADE PRÁTICA Nº1 - ESTRUTURA DE DADOS
//NOME: LUIZ FELIPE COUTO GONTIJO

#include "lista_cursos.h"
#include "lista_alunos.h"
#include "lista_final.h"

#include <iostream>
#include <sstream>

using namespace std;

StudentList OrdenaListaAlunos(StudentList student_list, int n, int a){

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

    return student_list;
    // student_list.Print();
    // cout << endl;

};

FinalList PreencheListaFinal(CourseList course_list, StudentList student_list, FinalList final_list, int n, int a){

    int i;
    int k=0;  //auxiliar - contador global na lista de alunos
    int j;  // contador que reseta - contador do número de vagas

    student current_student = student_list.GetElement(k);

    for(i=0;i<n;i++){       //n é o numero de materias

        course current_course = course_list.GetElement(i);
        int num_vac = current_course.vacancies;
        
        current_student = student_list.GetElement(k);
        j = 0;

        while(current_student.option_1 == i){

            if(j < num_vac){
                final_list.InsertInClassified(current_student.name,current_student.grade,num_vac,i);
                j++;
                current_student.sinal = 1;
            }else{
                final_list.InsertInWait(current_student.name,current_student.grade,i,a); // sendo a o número total de alunos
            }
            k++;
            if(k > a-1){  // a-1 pois k começa em 0
                break;
            }
            current_student = student_list.GetElement(k); 
            
        }

        if(k > a-1){  // a-1 pois k começa em 0
            break;
        }
        

    } 

    return final_list;




}


int main(){

    CourseList course_list;
    StudentList student_list;
    FinalList final_list;

    int i; //aux
  
    int n = 3;
    int a = 9;
    
    course_list.InsertElement("Mineração de Gelo",2);
    course_list.InsertElement("Computação de Gelo",2);
    course_list.InsertElement("Medicina de Gelo",2);

    for(i=0;i<n;i++){
        final_list.InsertElement(course_list.GetElement(i).name,course_list.GetElement(i).vacancies,a);
    }
  
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

    //student_list.Print();

    std::cout << endl;

    student_list = OrdenaListaAlunos(student_list,n,a);
    
    final_list = PreencheListaFinal(course_list,student_list,final_list,n,a);
    //final_list.InsertInClassified("A",700,2,0);
    //student_list.Print();
    final_list.Print();

    
    // student_list.ExchangeElement(1);
    // student_list.ExchangeElement(0);
    
   
    //student_list.Print();





    return 0;

}



