/*
NECESITAMOS UNA CALCULADORA (EL DE LA PC)

jugaremos a las adivinanzas


27 * (canatidad de sicfracaulqueira) = ?


CAMILA      SAMIR

CAMILA DICE : tiene 3 digitos... - 1! = 2 digitos. 4 y 8 serian.


SAMIR : 5 digitos. - 1 4 digitos :  4 y 8 y 2 y 4



Lo que haremos es advinar el numero que falta.

27 * numero magico = numero de CAMILA




CAMILA
5 1 2 0 X (X es el numero que falta)



4 6 3 X 

27* 463

da 12501


el truco es que es un multi;lico de 9... me suena a modulo.
los multiplos de nueve siempre dan 9.

el truco es que tu vas hacer unprograma que pregunta amiguito 27 * algo y  dimelo pero no me digas el ultimo
numero


todo esto lo metes en tu vector

luego haces eque el programita acabe o llene en el arerglo o no se

com un tipo de nueve dice el teacher..


tabla del 9

9*1 = 9 -> 9
9*2 = 18 -> 1 + 8 = 9
9*3 = 27 -> 2+ 7 =9
9* 4 = 36
9*5 = 45-> 4 +5 = 9

9*9 = 81 -> 8+ 1 = 9

no entendi ni mrd la verdad, a este hdp cada rato le fallaba su webada y lo paraban baiteando.
 */

 #include <iostream>
 #include <vector>
 using namespace std;


 int main(){

    int resultado = 0;

    cout<<"---------------------------------------------------------------\nJUEGO! Adivina el numero que falta:\n-Multiplica por tu cuenta un numero cualquiera x 27\n-Tu resultado, quitale un numero que quieras y yo lo adivinare!\n---------------------------------------------------------------\nRESULTADO =  ";cin>>resultado;

   vector<int> v;

   while(resultado > 0){

      int digito = resultado % 10;
      v.push_back(digito);
      resultado /= 10;

   }

// 8   7   4 = size 3
//[0] [1] [2].  0 + 3 = 
   int* ini = v.data();
   int* fin = v.data() + v.size() - 1 ;

   int suma = 0;

// 8 + 7 + 4
   while(ini <= fin){
      suma += *ini;
      ini++;
   }

   int numero_encontrado = 9 - (suma % 9);



   cout<<"El numero que me OCULTAS es: "<< numero_encontrado <<endl;
 }