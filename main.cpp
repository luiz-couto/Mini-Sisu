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
                                
                                //cout <<"k=" << student_list.GetElement(k).name << endl;
                                student_list.ExchangeElement(k);
                                //cout <<"k=" << student_list.GetElement(k).name << endl;
                                k = k-1;
                                
                                
                            }else{
                                break;
                            }
                        }else{
                            break;
                        }
                        
                    }
                    else{
                        student_list.ExchangeElement(k);
                        k = k-1;
                    }

                    //k = k-1;
                }
            }
        }
    }
}

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
                    
                    for(j=a-1;j>0;j--){  // Colocando o estudante retirado na lista de espera da primeira opção
                    
                        if(final_op2.wait_ids[0] == -1){
                            final_op2.wait_ids[0] = last.id;
                            final_op2.wait_grades[0] = last.grade;
                            break;
                        }
                        
                        if(final_op2.wait_ids[j-1] != -1){

                    
                            if((final_op2.wait_grades[j-1] < last.grade) ||
                            (final_op2.wait_grades[j-1] == last.grade && final_op2.wait_ids[j-1] > last.id )){
                                
                                final_op2.wait_ids[j] = final_op2.wait_ids[j-1];
                                final_op2.wait_ids[j-1] = last.id;

                                final_op2.wait_grades[j] = final_op2.wait_grades[j-1];
                                final_op2.wait_grades[j-1] = last.grade;
                           
                            }else{

                                final_op2.wait_ids[j] = last.id;
                                final_op2.wait_grades[j] = last.grade;
                                break;

                            }
                        }
                    }
                    final_op2.classified_ids[n_vac-1] = current_student.id;
                    final_op2.classified_grades[n_vac-1] = current_student.grade;
                    student_list.ChangeSinal(current_student.id,1,a);

                    for(j=n_vac-1;j>0;j--){

                        if(current_student.grade < final_op2.classified_grades[j-1]){
                            break;
                        }else{

                            if(current_student.grade == final_op2.classified_grades[j-1]){
                                
                                if(current_student.id > final_op2.classified_ids[j-1]){
                                    break;
                                }
                                else{
                                    final_op2.classified_ids[j] = final_op2.classified_ids[j-1];
                                    final_op2.classified_ids[j-1] = current_student.id;

                                    final_op2.classified_grades[j] = final_op2.classified_grades[j-1];
                                    final_op2.classified_grades[j-1] = current_student.grade;
                                }

                            }
                            else if(current_student.grade > final_op2.classified_grades[j-1]){

                                final_op2.classified_ids[j] = final_op2.classified_ids[j-1];
                                final_op2.classified_ids[j-1] = current_student.id;

                                final_op2.classified_grades[j] = final_op2.classified_grades[j-1];
                                final_op2.classified_grades[j-1] = current_student.grade;

                            }
                        }
                    }

                }else{ //Colocar na lista de espera

                    student_list.ChangeSinal(current_student.id,2,a);                   
                    
                    for(j=a-1;j>0;j--){
                    
                        if(final_op2.wait_ids[0] == -1){
                            final_op2.wait_ids[0] = current_student.id;
                            final_op2.wait_grades[0] = current_student.grade;
                            break;
                        }
                        
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
                if(k == a){
                    have_zero = false;
                    break;
                }
            }
        }
    }
}

void GetData(CourseList &course_list,StudentList &student_list,FinalList &final_list,int &n,int &a){

    int i; // auxiliar

    cin >> n;
    cin >> a;
    for(i=0;i<n;i++){
        
        fflush(stdin);

        string name;
        cin.ignore();
        getline(cin,name);
        
        fflush(stdin);
       
        int n_vac;
        cin >> n_vac;
        
        course_list.InsertElement(name,n_vac); 
    }

    for(i=0;i<a;i++){

        fflush(stdin);

        string name;
        cin.ignore();
        getline(cin,name);

        fflush(stdin);

        float grade;
        int op1;
        int op2;
        int id = i;

        cin >> grade;
        cin >> op1;
        cin >> op2;

        student_list.InsertElement(name,grade,op1,op2,id);


    }

    
    for(i=0;i<n;i++){
        final_list.InsertElement(course_list.GetElement(i).name,course_list.GetElement(i).vacancies,a);
    }
}

void PrintFinal(CourseList &course_list,StudentList &student_list,FinalList &final_list,int &n,int &a){

    int i,j;

    cout << "------------------------------------------------------------" << endl;
    cout << fixed;
    cout.precision(2);

    for(i=0;i<n;i++){
        
        final current_final = final_list.GetElement(i);
        course current_course = course_list.GetElement(i);
        
        cout << current_final.course_name << " ";
        int n_vac = current_course.vacancies;
        
        if(current_final.classified_grades[n_vac-1] != -1){
            cout << current_final.classified_grades[n_vac-1] << endl;
        }else{
            cout << 0.00 << endl;
        }

        cout << "Classificados" << endl;
        for(j=0;j<n_vac;j++){
            if(current_final.classified_ids[j] != -1){
                student current_student = student_list.GetElementById(current_final.classified_ids[j],a);
                cout << current_student.name << " " << current_final.classified_grades[j] << endl;
            }
        }
        cout << "Lista de epera" << endl;
        for(j=0;j<a;j++){
            if(current_final.wait_ids[j] != -1){
                student current_student = student_list.GetElementById(current_final.wait_ids[j],a);
                cout << current_student.name << " " << current_final.wait_grades[j] << endl;
            }   
        }
        cout << endl;
    }
}


int main(){

    CourseList course_list;     
    StudentList student_list;
    FinalList final_list;
  
    int n;      // Número de matérias
    int a;      // Número de alunos

    GetData(course_list,student_list,final_list,n,a);
    OrdenaListaAlunos(student_list,n,a);
    //cout << student_list.GetElement(1).name << endl;
    PreencheListaFinal(course_list,student_list,final_list,n,a);
    VerificaSegundaOpcao(course_list,student_list,final_list,n,a);
    PrintFinal(course_list,student_list,final_list,n,a);
    
    return 0;

}



