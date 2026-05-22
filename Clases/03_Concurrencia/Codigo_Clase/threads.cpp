/*
Clase 18-05-26

PURA TEORIA:
#include <threads>
std:: thread t;
std:: mutex m;

m.lock();
       sum+=
m.unlock();

lo mejor es hacer sumas locales y luego recien hacer un proces oque sume todo post proceso

sum = S0+S1+S2+S3;

LO QUE VAMOS HACER:

std:: thread t;
std:: mutex m;std:: thread t;
std:: mutex m;std:: thread t;
std:: mutex m;std:: thread t;
std:: mutex m;std:: thread t;
std:: mutex m;std:: thread t;
std:: mutex m;std:: thread t;
std:: mutex m;std:: thread t;
std:: mutex m;std:: thread t;
std:: mutex m;std:: thread t;
std:: mutex m;std:: thread t;
std:: mutex m;std:: thread t;
std:: mutex m;std:: thread t;
std:: mutex m;std:: thread t;
std:: mutex m;std:: thread t;
std:: mutex m;std:: thread t;
std:: mutex m;std:: thread t;
std:: mutex m;std:: thread t;
std:: mutex m;std:: thread t;
std:: mutex m;




*/





//CLASE 19-05-26

// en threads se le llaa en el main que origina el paralelismo, ejemplo si se llama thread t(nombre de funcion, vvariables de funcion) y se coloca el t.join()
// el t.join() sirve para mantener la ejecucion en el thread ahi hasta que se cumpla el thread
//

/*
para usar la cantidad de threads que tengas en el computador se coloca de esta forma
 int i=0, nthreads = thread::hardware_concurrency()
 vectir<thread> ths(nthreads)

 for( i=0; i <nthreads; i++)
    ths[i] = thread(F1,char('a'+1),100);
 for( i=0 ; i<nthreads ;i++)
    ths[i].join();

    EL JOIN ES MUY IMPORTANTE, ES EL QUE ESPERA PARA QUE LOS THREADS SE CUMPLAN

 */
 /*
 va ser un algoritmo secuencial por que el mutex es para bloquear el segmento critico, impide que se lea en paralelo, si no es nesesario no usar si es bien usado usarlo impreseptible sin bloquear todo
 con una variable global y mutex(el mutex si o si debe ser global por que es como un semaforo, si lo colocas dentreo de la varuabke seria ponerlo dentro de cada carro y no guardaria como uno quiere)
 mutex m
 int sum=0;
 int f2(int x, int f){

    for(int i=0;i<f;i++){
         m.lock();
         sum+=x;
         m.unlock();
     }
 }
  int main(){
  int yh = thread::hardware_concurrency()
  vectir<thread> ths(yh)

  for( i=0; i <yh; i++)
     ths[i] = thread(F1,5,1000);
  for( i=0 ; i<yh ;i++)
     ths[i].join();
  }

 */

 /*
 con el objetivo de tener un array con una unica suma

 void f1(int *ar, int n, int*s){

    for(int i =0;i<n; i++){
      *s += ar[i];
    }
 }
 int main()
 { int ar[16] = {2,3,54,7,8,4,5,1,5,6,2,4,5,4};
 int sum[4] = {0,0,0,0}
 int xsum =0;

 int i =0, nt=4;
 vector<thread>ths(nt);
     for(i=0;i<nt; i++){
         ths[i] =thread(f1,&ar[i*4],4,&xsum[i])
     }
     for(i=0;i< nt; i++){
      ths[i].join();
     }for(i =0; i<nt; i++){
       sum += xsum[i];
     }
 }



 HACER UN ALGORITHMO DE ORDENAMIENTO QUE QUEME TODOS LOS NUCLEOS

 */



