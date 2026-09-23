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


 */

#include <iostream>
#include <vector>

using namespace std;

void ConversionStraInt(const string &resultado, vector<int> &v){

   const char* p_char = resultado.data();
   const char* p_fin = resultado.data() + resultado.length() ;

   while(p_char < p_fin){

      if(*p_char >= '0' && *p_char <= '9'){
         int ins = *p_char - '0';
         v.push_back(ins);
      }else if(*p_char == 'X' || *p_char == 'x'){
         v.push_back(-1);
      }

      p_char++;

   }

}

void AdivinarNumero(vector<int> &v){

   int* p = v.data();

   int* ini = p;

   int* q = v.data() + v.size() - 1;

   int suma = 0;
   int indice_x = 0;

   while( p <= q){

      if(*p >= 0){
         suma+=*p;
      }else{
         indice_x = p - ini;
      }

      p++;

   }

   int n_encontrado = (9 - (suma % 9)) % 9;

   v.operator[](indice_x) = n_encontrado;

   

   cout<<"-----------------------------------------"<<endl;
   cout<<"TU NUMERO ES: ";
   while( ini <= q){

      cout<< *ini <<"";
      ini++;

   } 

   cout<<endl;

}


 int main(){

   string resultado = " ";

   cout << "---------------------------------------------------------------\n"
         << "JUEGO! Adivina el numero que falta:\n"
         << "- Multiplica por tu cuenta un numero cualquiera x 27\n"
         << "- Tu resultado, quitale un numero poniendole 'X' encima y yo lo adivinare!\n"
         << "---------------------------------------------------------------\n"
         << "RESULTADO = ";
   cin >> resultado;

   vector<int> v;

   ConversionStraInt(resultado, v);
   AdivinarNumero(v);


 }