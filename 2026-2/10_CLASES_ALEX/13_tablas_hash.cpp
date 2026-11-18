/*

Concepto simple

Objetivo:

tienes un conjunto de enttradas, por ejemplo numeros, aunqeu pdoria ser aucalqueir tipo de datos.
strings.. floats..ojbetos con varios... o eso p.

por otro lado tienes una tabla, que es como un vector. es ahi donde meteras esos datos.

quizas con strings usar ASCII o sumando lso caracteres de sus nombres y asi p.
ademas hay una funcion digmaos f(x) entra uno de ess y sale una posicion...


7 9                                             0   
10 2        f(x) = x % 7                        1
1 5 6                                           2
5 6                                             3    
                                                4
                                                5
                                                6
                                                       

El objetivo...



regresando a lo de l profe...


7 9                                             0[7]   
10 2        f(x) = x % 7                        1[8]
1 5 6                                           2[9]
5 6                                             3    
                                                4[4]
                                                5
                                                6

Segun la f(x) no tiene colisiones.. esl a perfecta, pero en la practica se dan.
Hay que manejar las colisiones. suponiendo que 2 valores cane alli.

Hay varias formas:

1) Simple pero no eficiente:
Buscar la primera posicion vacia. osea.. el 2 cae en 2, pero la promera acia seria en 3[aqui]
La commplejidad es O(K)
por ende la funcion tien un orden constante.

La idea de la tabla hash es que ese sea O(K) (cuando no hay repetidos aun)

ENTRADA: O(K)
BUSQUEDA: O(K) -> salida... asi tu ecuacion sea compleja.
tu ecuceniaon debe ser constante.


2 mod 7 = 2 cae en [9]

Busnaod la primera pisicon vacia depues del n osea lel 3, pero que pasa si todas estan llenas.. y digamos la del 0 estaba vacia, 
entonces el 2 estaria lejos de 9

Que pasaria con la busqueda del dos?
se malogro porque si tienes al dos,  y no estas seguro que ni este ahi. porque se podria haber puesto en un lugar vacio.
No es eficiente, nada garantiza de que el lugar ese este vacio.

Es una forma para solucionarlo de forma punteal.. pero quiebbra el orden constante.
de todas maneras lo quiebra....


solo nos lo dice porque lo uestra en los libros.


OTRA FORMA:


Usar una 2da funcion... llamada.. fx2(x) = x² % 7
cosa qeue si f1(x) colisiona, vas a fx2..

Osea usar 2 funciones de dispersion para encontrar el lugar.
pero nohay ninguna garantiza que la 2da te de que no caiga en un lugar vacio.




DESCARTANDO ESAS IDEAS..
en la misma tabla...
la mejor salida.

es que que esa lsita sea una lista de punteros que apunte a una LE para que no haya problemas.

7 9                                             0[ ]   
10 2        f(x) = x % 7                        1[ ] -> 8 -> 1
1 5 6                                           2[ ] -> 9 -> 2
5 6                                             3[ ] -> 10  
                                                4[ ] -> 4
                                                5[ ] -> 5
                                                6[ ] -> 6

Haces todo, pero la minibusqueda que harias en las LE...

osea O(N)


osea va a ser un N pero chiquito que tiende a ser como uno o como ceor.. asi que aun se considera una tabla hash.



Si las colisiones son chiquitas de 1 o 0, tons.. en la practica es como si fuera constante..

Si por algun razon genera picos en tu diagrama de colisiones entonces es una tabla hash, tu funcion de dispersion es mala. porque 
son casi N


Mantener que las colisiones sean bajitas.. numeros bajas cercanos a cero.


No hay parametros en esa funcion..  
osea 9 datos, en 7 espacios.. entonces que pasa si.

OTRA FORMA es;;;;

si esto en vez de ser 7, le ponemos 700 hay demasiado espacios. tednria que serm ala t funcion ..

O HACS UNA MEJOR FUNCION o.. AMPLIAS EL ESPACIO DE DISPERSION.



mientras que x % primo , la posibidldad que haya colisiones se reduce....

en cambios s hacer ujn 

x%48 la probaldada de mayores ccondiciones es mas porque es muy divisible.

asi qeu nlo  norlmal es poenr n njumero proimo.



OBJETIVO:
ENTRADA Y SALIDA SEAN MASOMENOS TIEMPO CONSTANTE.

esa LE pdoria ser un vector, un arbol.. ahi seria log N 


tons..
5nn vecto de estrcturas... y la funcion.

aqui no nos complquenmos con el extendible hashing jajaaj la ocsa es que no tenga tantas c
ccolisiones yya. no comlicarnos la vida.

quizas contar la cantidad ecoolciisones que haya para cerciorarnos.


el profe pone de ejmplo un arbol digital para hacer referencia al hash.

PERO NO TOMARA ESO, ESO NO HACEMOS EN EL CURSO, SOLO ES UN EJEMPLO AL AIRE. ajjaa
es una fumada lo que esta haciendo ya nos dijo que esto no enetra a lexamen jaajjajajajajajaj

*/