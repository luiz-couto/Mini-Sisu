//MINI-SISU - ATIVIDADE PRÁTICA Nº1 - ESTRUTURA DE DADOS
//NOME: LUIZ FELIPE COUTO GONTIJO

#include "lista_cursos.h"

#include <iostream>
#include <sstream>


int main(){

    CourseList course_list;
    
    course_list.InsertElement("Mineração de Gelo",12);
    course_list.InsertElement("Computação de Gelo",40);
    course_list.InsertElement("Medicina de Gelo",120);

    course c = course_list.GetElement(0);
    cout << "Name c:" << c.name << endl;


    course_list.Print();



    return 0;

}

