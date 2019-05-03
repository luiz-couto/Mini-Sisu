# Mini-Sisu (Em desenvolvimento) - C++
Trabalho Prático Nº1 - Estrutura de Dados - UFMG - Luiz Felipe Couto Gontijo

## Para compilar
Utilize na pasta do diretório o comando 'make'.
Depois, basta executar o arquivo main criado com './main'


## Entrada e saída
A partir das observações ressaltadas no e-mail, o resumo do formato de entrada e saída desejados pelo MEC de Arendelle é:
### Entrada:
A primeira linha da entrada contém 2 inteiros N(2≤N≤27) e M(1≤M≤210),representando respectivamente o número de cursos e número de alunos a serem considerados na edição do Mini SISU. Os N pares de linhas seguintes contém informações sobre os N cursos.  A primeira linha de um par contém uma string S(1≤|S|≤100) representando o nome do curso, sem acentuação.  A segunda linha do par contém um inteiro v(0≤v≤210), representando a quantidade de vagas disponíveis no curso. Os cursos são numerados de 0 a N−1 de acordo com a ordem em que aparecem na entrada. Após as informações dos cursos, os próximos M pares de linhas trazem as informacões sobre os M alunos.  A primeira linha de um par contém uma string S′(1≤|S′|≤100) representando o nome do(a)aluno(a), sem acentuacão.   A segunda linha do par contém um número decimal n(0.0≤n≤1000.0) seguido  de  dois  inteiros p(0≤p≤N−1)  e s(0≤s≤N−1), representando  respectivamente  anota obtida pelo(a) aluno(a), sua primeira e sua segunda opção de curso.  As opções de curso de um(a) aluno(a) serão sempre diferentes.  Os alunos são numerados de 0 a M−1 de acordo com a ordem emque aparecem na entrada.

### Saída:
Para cada curso, na mesma ordem da entrada, deverá ser impresso em uma mesma linha o  nome  do  curso e a nota de corte  (com  duas  casas  decimais  (dica: use  ‘%.2f’  no  lugar  de  ‘%f’ao  imprimir).   Na  próxima  linha  deverá  ser  impresso  somente  a  string  “Classificados”.   Em  seguida deverão ser impressas Ci linhas, contendo o nome do aluno e sua nota, na ordem de classificação, sendo Ci o número de alunos classificados para o curso i.  Ou seja,os alunos deverão estar em ordem descendente de nota, seguindo os critérios de desempate especificados anteriormente.  Posteriormente deverá ser impressa a string ”Lista de espera” em sua própria linha, seguida de Ei(número de alunos na fila de espera do curso i) linhas contendo os nomes e as notas dos alunos que estão na fila de esperado curso, também em ordem decrescente de nota.


