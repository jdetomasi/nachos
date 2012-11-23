// synch.h
//	NOTA: Este es el unico fichero fuente con los comentarios en español
//	2000 - Jose Miguel Santos Espino - ULPGC
//
//	Estructuras de datos para sincronizar hilos (threads)
//
//	Aqui se definen tres mecanismos de sincronizacion: semaforos
//	(semaphores), cerrojos (locks) y variables condicion (condition var-
//	iables). Solo estan implementados los semaforos; de los cerrojos y
//	variables condicion solo se proporciona la interfaz. Precisamente el
//	primer trabajo incluye realizar esta implementacion.
//
//	Todos los objetos de sincronizacion tienen un parametro "name" en
//	el constructor; su unica finalidad es facilitar la depuracion del
//	programa.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// synch.h -- synchronization primitives.  

#ifndef SYNCH_H
#define SYNCH_H

#include "copyright.h"
#include "thread.h"
#include "list.h"

class Thread;

// La siguiente clase define un "semaforo" cuyo valor es un entero positivo.
// El semaforo ofrece solo dos operaciones, P() y V():
//
//	P() -- espera a que value>0, luego decrementa value
//
//	V() -- incrementa value, despiera a un hilo en espera si lo hay
//
// Observen que esta interfaz NO permite leer directamente el valor del
// semaforo -- aunque hubieras podido leer el valor, no te sirve de nada,
// porque mientras tanto otro hilo puede haber modificado el semaforo,
// si tu has perdido la CPU durante un tiempo.

class Semaphore {
  public:
    // Constructor: da un valor inicial al semaforo
    Semaphore(const char* debugName, int initialValue);
    ~Semaphore();   					
    const char* getName() { return name;}			

    // Las unicas operaciones publicas sobre el semaforo
    // ambas deben ser *atomicas*
    void P();
    void V();
    
  private:
    const char* name;
    // valor del semaforo, siempre es >= 0
    int value;
    // Cola con los hilos que esperan en P() porque el valor es cero
    List<Thread*> *queue;
    
};

// La siguiente clase define un "cerrojo" (Lock). Un cerrojo puede tener
// dos estados: libre y ocupado. Solo se permiten dos operaciones sobre
// un cerrojo:
//
//	Acquire -- espera a que el cerrojo esta libre y lo marca como ocupado
//
//	Release -- marca el cerrojo como libre, despertando a algun otro
//                 hilo que estuviera bloqueado en un Acquire
//
// Por conveniencia, nadie excepto el hilo que tiene adquirido el cerrojo
// puede liberarlo. No hay ninguna operacion para leer el estado del cerrojo.


class Lock {
  public:
  // Constructor: inicia el cerrojo como libre
  Lock(const char* debugName);
  ~Lock();
  const char* getName() { return name; }

  // Operaciones sobre el cerrojo. Ambas deben ser *atomicas*
  void Acquire(); 
  void Release();

  // devuelve 'true' si el hilo actual es quien posee el cerrojo.
  // util para comprobaciones en el Release() y en las variables condicion
  bool isHeldByCurrentThread();	

  private:
    const char* name;
    // Thread actualmente utilizando el lock.
    Thread* holderThread;
    // Semaforo binario. Maneja el lock.
    Semaphore* lockSem;
    int oldPriority;
};

//  La siguiente clase define una "variable condicion". Una variable condicion
//  no tiene valor alguno. Se utiliza para encolar hilos que esperan (Wait) a
//  que otro hilo les avise (Signal). Las variables condicion estan vinculadas
//  a un cerrojo (Lock). 
//  Estas son las tres operaciones sobre una variable condicion:
//
//     Wait()      -- libera el cerrojo y expulsa al hilo de la CPU.
//                    El hilo se espera hasta que alguien le hace un Signal()
//
//     Signal()    -- si hay alguien esperando en la variable, despierta a uno
//                    de los hilos. Si no hay nadie esperando, no ocurre nada.
//
//     Broadcast() -- despierta a todos los hilos que estan esperando
//
//
//  Todas las operaciones sobre una variable condicion deben ser realizadas
//  adquiriendo previamente el cerrojo. Esto significa que las operaciones
//  sobre variables condicion han de ejecutarse en exclusion mutua.
//
//  Las variables condicion de Nachos deberian funcionar segun el estilo
//  "Mesa". Cuando un Signal() o Broadast() despierta a otro hilo,
//  este se coloca en la cola de preparados. El hilo despertado es responsable
//  de volver a adquirir el cerrojo. Esto lo deben implementar en el cuerpo de
//  la funcion Wait().
//  En contraste, tambien existe otro estilo de variables condicion, segun
//  el estilo "Hoare", segun el cual el hilo que hace el Signal() pierde
//  el control del cerrojo y entrega la CPU al hilo despertado, quien se
//  ejecuta de inmediato y cuando libera el cerrojo, devuelve el control
//  al hilo que efectuo el Signal().
//
//  El estilo "Mesa" es algo mas facil de implementar, pero no garantiza
//  que el hilo despertado recupere de inmediato el control del cerrojo.

class Condition {
 public:
    // Constructor: se le indica cual es el cerrojo al que pertenece
    // la variable condicion
    Condition(const char* debugName, Lock* conditionLock);	
    ~Condition();	
    const char* getName() { return (name); }

    // Las tres operaciones sobre variables condicion.
    // El hilo que invoque a cualquiera de estas operaciones debe tener
    // adquirido el cerrojo correspondiente; de lo contrario se debe
    // producir un error.
    void Wait();	
    void Signal();
    void Broadcast();

  private:
    const char* name;
    // Lock que debe poseer un thread para utilizar las operaciones sobre la var. de cond.
    Lock* conditionLock;
    // Lista de semaforos creados por cada Thread que espera por un Signal (o Broadcast)
    List<Semaphore*> *waitingList;
};

class Port {
public: 
    // Se crea un puerto indicando por que puerto se realizara la comunicacion
    Port(const char* debugName);
    ~Port();
    const char* getName() { return(name);}

    // Envia un mensaje (msg) a traves del puerto (port)
    void Send(int msg);
    // Recibe un mensaje (msg) a traves del puerto (port)
    void Receive(int *msg);
private:
    const char* name;
    int message, isBusy;

    Lock* portLock;

    // Indican si se ha enviado o recibido el mensaje
    Condition* mailSnd;
    Condition* mailRcv;
};

/*

Codigo original del Nachos para las variables condicion - NO USAR
  
class Condition {
  public:
    Condition(char* debugName);		// initialize condition to 
					// "no one waiting"
    ~Condition();			// deallocate the condition
    char* getName() { return (name); }
    
    void Wait(Lock *conditionLock); 	// these are the 3 operations on 
					// condition variables; releasing the 
					// lock and going to sleep are 
					// *atomic* in Wait()
    void Signal(Lock *conditionLock);   // conditionLock must be held by
    void Broadcast(Lock *conditionLock);// the currentThread for all of 
					// these operations

  private:
    char* name;
    // plus some other stuff you'll need to define
};

*/

#endif // SYNCH_H
