/*
TAREA 8:

Caramelos...

El explicara el algoritmo:

Esto es un arbol binario, no de busqueda.


ARbol de caramelos
        5
    0       0
          0   0



Donde...
la cantidad de nodos... es igual a N

y la cantidad de Caramelos en los nodos es igual a N



5 NODOS, suma todos los numeros... = 5..
Esa es una caracteristica.


Ahora este algo feo:


        2
    0       0
          3   0

5 NODOS...

El numero qeu esta en el nodo, indica cuantos caramelos tiene esa persona.


EL OBJETIVO
es que cada uno tenga UN caramelo


OBJETIVO:
Cada nodo tenga 1 caramelo.

Si yo tengo 10 nodos, el nodo no tiene que ser superior a diez.

Si tu recorres todos los nodos tiene que tener la suma? no seu qe dijo aqui..


SOLO SE PUEDEN PASAR CARAMELOS
de padre a hijos Y de hijo a padre.

Y solo se puede pasar 1 caramelo a la vez.


Tienes que hacer una cantidad de elementos al arbol para qeu distribuya bien.


TIENES QUE PRESETNAR EL ARBOL ANTES Y DESPUES.

Y...

DECIR CUANTOS RECORRIDOS FUERON NECESARIOS.

no necesariemnte la menor de recorridos. solo los que hiciste.

por ejemplo... hacemos un recorriodo inorden 


raiz.. tengo 5
el hijo no tiene caramelo.
en este ocasion le voy a dar uno de mis paramelos...

        5
    0       0
          0   0
          
          ahora

        4
    1       0
          0   0


          al otro hijo ya no le doy. ahi acaba el recorrido...

          etnonces otro:


        3
    1       1
          0   0



          ahora..


        3
    1       0
          1   0
    ahi acaba el recorrido...







    AHORA EN ESTE CASO:



        2
    0       0
          3   0



        1
    1       0
          3   0



        1
    1       0
          3   0



          Si un hijo ya le dio al abuela... ya no le puede dar un hijo

          solo le puedas dar un caramelo a alguien a la vez...

          Hay que tener cuidado en que derepente te encuentras... no se.
          en en en .

          0
            1
                0

                tons..

                0
                    0
                        1
                        tons...
                            0 
                                1
                                    0
                                    y rebota rebota.  TEN CIDADO PARA UE NO DES VUELTAS...

    Ahora tu chamba es penser en el algoritmo..


    El objetivo al final deberia salri asi.


        1
    1       1
          1  1

          y si sumas.. 5 p fin
          4



          el truco es que en cada vuelta un padre le puede entrar o un hijo a un padre. la idea es que no estes dando dos dos. nada matematicamente, eso es tramap.
          por eso cuando haces el primer coso dibuja y dibuja y ahi te das cuenta donde esta el aerror...

          vuelta 1, ver com ose dibuja
          vuelta 2 tal
          vuvlta 3
          tal
          tal tal
          cosa qeu dibujas y lueg ocomparas con lo que te genra.

          CON ESE AROBL TIENE QUE FUNCIONAR SEGUN EL N NOS METERA WEBADAS.
*/
