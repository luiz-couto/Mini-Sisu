//MINI-SISU - ATIVIDADE PRÁTICA Nº1 - ESTRUTURA DE DADOS
//NOME: LUIZ FELIPE COUTO GONTIJO

#include "lista_cursos.h"
#include "lista_alunos.h"
#include "lista_final.h"

#include <iostream>
#include <sstream>

using namespace std;

void OrdenaListaAlunos(StudentList &student_list, int n, int a){

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

    //return student_list;
    // student_list.Print();
    // cout << endl;

};

void PreencheListaFinal(CourseList &course_list, StudentList &student_list, FinalList &final_list, int n, int a){

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
                final_list.InsertInClassified(current_student.id,current_student.grade,num_vac,i);
                j++;
                student_list.ChangeSinal(current_student.id,1,a);
            }else{
                final_list.InsertInWait(current_student.id,current_student.grade,i,a); // sendo a o número total de alunos
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

    




}

void VerificaSegundaOpcao(CourseList &course_list,StudentList &student_list,FinalList &final_list,int n,int a){

    int k;
    bool have_zero = true;

    student current_student = student_list.GetElement(0);
    
    
    while(have_zero == true){
        
        k = 0;
        int i,j;
        for(i=0;i<a;i++){

            student current_student = student_list.GetElement(i);
            
            if(current_student.sinal == 0){

                int op2 = current_student.option_2;
                course course_op2 = course_list.GetElement(op2);
                final final_op2 = final_list.GetElement(op2);

                int n_vac = course_op2.vacancies;
                if((current_student.grade > final_op2.classified_grades[n_vac-1]) ||
                (current_student.grade == final_op2.classified_grades[n_vac-1] && current_student.id < final_op2.classified_ids[n_vac-1] )){

                    student last = student_list.GetElementById(final_op2.classified_ids[n_vac-1],a);
                    student_list.ChangeSinal(last.id,0,a);
                    final_op2.classified_ids[n_vac-1] = current_student.id;
                    final_op2.classified_grades[n_vac-1] = current_student.grade;
                    student_list.ChangeSinal(current_student.id,1,a);

                    for(j=2;j<n_vac-1;j++){

                        if(current_student.grade < final_op2.classified_grades[n_vac - j]){
                            break;
                        }else{

                            if(current_student.grade == final_op2.classified_grades[n_vac - j]){
                                
                                if(current_student.id > final_op2.classified_ids[n_vac - j]){
                                    break;
                                }
                                else{
                                    final_op2.classified_ids[n_vac-(j+1)] = final_op2.classified_ids[n_vac-j];
                                    final_op2.classified_ids[n_vac-j] = current_student.id;

                                    final_op2.classified_grades[n_vac-(j+1)] = final_op2.classified_grades[n_vac-j];
                                    final_op2.classified_grades[n_vac-j] = current_student.grade;
                                }


                            }
                            else if(current_student.grade > final_op2.classified_grades[n_vac - j]){

                                final_op2.classified_ids[n_vac-(j+1)] = final_op2.classified_ids[n_vac-j];
                                final_op2.classified_ids[n_vac-j] = current_student.id;

                                final_op2.classified_grades[n_vac-(j+1)] = final_op2.classified_grades[n_vac-j];
                                final_op2.classified_grades[n_vac-j] = current_student.grade;


                            }

                        }

                    }


                }else{ //Colocar na lista de espera

                    student_list.ChangeSinal(current_student.id,2,a);                   
                    
                    for(j=a-1;j>0;j--){
                    
                        if(final_op2.wait_ids[j-1] != -1){
                    
                            if((final_op2.wait_grades[j-1] < current_student.grade) ||
                            (final_op2.wait_grades[j-1] == current_student.grade && final_op2.wait_ids[j-1] > current_student.id )){
                                
                                final_op2.wait_ids[j] = final_op2.wait_ids[j-1];
                                final_op2.wait_ids[j-1] = current_student.id;

                                final_op2.wait_grades[j] = final_op2.wait_grades[j-1];
                                final_op2.wait_grades[j-1] = current_student.grade;
                           
                            }else{

                                final_op2.wait_ids[j] = current_student.id;
                                final_op2.wait_grades[j] = current_student.grade;
                                break;


                            }
                        }
                    }   
    


                }



            }else{
                
                k++;
                if(k == a-1){
                    have_zero = false;
                    break;
                }
            }



        }

    }
    



}


int main(){

    CourseList course_list;
    StudentList student_list;
    FinalList final_list;

    int i; //aux
  
    int n = 2;
    int a = 5;
    
    course_list.InsertElement("Mineração de Gelo",2);
    course_list.InsertElement("Engenharia Metalurgica",1);
    //course_list.InsertElement("Medicina de Gelo",2);

    for(i=0;i<n;i++){
        final_list.InsertElement(course_list.GetElement(i).name,course_list.GetElement(i).vacancies,a);
    }
  
    //course c = course_list.GetElement(0);
    //cout << "Name c:" << c.name << endl;


    //course_list.Print();

    student_list.InsertElement("Kristoff",500,0,1,0);
    student_list.InsertElement("Gothi",500,0,1,1);
    student_list.InsertElement("Gerda",500,1,0,2);
    student_list.InsertElement("Hans",500,1,0,3);
    student_list.InsertElement("Olavo",500,0,1,4);
    // student_list.InsertElement("I",700,2,0,5);
    // student_list.InsertElement("B",650,0,1,6);
    // student_list.InsertElement("F",650,1,0,7);
    // student_list.InsertElement("H",750,2,1,8);
    

    //student_list.ExchangeElement(1); // Muda o elemento da posição informada com o elemento da próxima posição

    //student_list.Print();

    std::cout << endl;

    OrdenaListaAlunos(student_list,n,a);
    
    PreencheListaFinal(course_list,student_list,final_list,n,a);
    VerificaSegundaOpcao(course_list,student_list,final_list,n,a);
    //final_list.InsertInClassified("A",700,2,0);
    //student_list.Print();
    //final_list.Print();
    final_list.PrintCourse(0,course_list.GetElement(0).vacancies,a);
    final_list.PrintCourse(1,course_list.GetElement(1).vacancies,a);
    //final_list.PrintCourse(2,course_list.GetElement(2).vacancies,a);
    
    // student_list.ExchangeElement(1);
    // student_list.ExchangeElement(0);
    
   
    //student_list.Print();





    return 0;

}



