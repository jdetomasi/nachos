// synch.h
//	NOTA: �ste es el �nico fichero fuente con los comentarios en espa�ol
//	2000 - Jos� Miguel Santos Espino - ULPGC
//
//	Estructuras de datos para sincronizar hilos (threads)
//
//	Aqu� se definen tres mecanismos de sincronizaci�n: sem�foros
//	(semaphores), cerrojos (locks) y variables condici�n (condition var-
//	iables). S�lo est�n implementados los sem�foros; de los cerrojos y
//	variables condici�n s�lo se proporciona la interfaz. Precisamente el
//	primer trabajo incluye realizar esta implementaci�n.
//
//	Todos los objetos de sincronizaci�n tienen un par�metro "name" en
//	el constructor; su �nica finalidad es facilitar la depuraci�n del
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

// La siguiente clase define un "sem�foro" cuyo valor es un entero positivo.
// El sem�foro ofrece s�lo dos operaciones, P() y V():
//
//	P() -- espera a que value>0, luego decrementa value
//
//	V() -- incrementa value, despiera a un hilo en espera si lo hay
//
// Observen que esta interfaz NO permite leer directamente el valor del
// sem�foro -- aunque hubieras podido leer el valor, no te sirve de nada,
// porque mientras tanto otro hilo puede haber modificado el sem�foro,
// si t� has perdido la CPU durante un tiempo.

class Semaphore {
  public:
    // Constructor: da un valor inicial al sem�foro  
    Semaphore(const char* debugName, int initialValue);	// set initial value
    ~Semaphore();   					// destructor
    const char* getName() { return name;}			// para depuraci�n

    // Las �nicas operaciones p�blicas sobre el sem�foro
    // ambas deben ser *at�micas*
    void P();
    void V();
    
  private:
    const char* name;        		// para depuraci�n
    int value;         		// valor del sem�foro, siempre es >= 0
    List<Thread*> *queue;       // Cola con los hilos que esperan en P() porque el
                       		// valor es cero
};

// La siguiente clase define un "cerrojo" (Lock). Un cerrojo puede tener
// dos estados: libre y ocupado. S�lo se permiten dos operaciones sobre
// un cerrojo:
//
//	Acquire -- espera a que el cerrojo est� libre y lo marca como ocupado
//
//	Release -- marca el cerrojo como libre, despertando a alg�n otro
//                 hilo que estuviera bloqueado en un Acquire
//
// Por conveniencia, nadie excepto el hilo que tiene adquirido el cerrojo
// puede liberarlo. No hay ninguna operaci�n para leer el estado del cerrojo.


class Lock {
  public:
  // Constructor: inicia el cerrojo como libre
  Lock(const char* debugName);

  ~Lock();          // destructor
  const char* getName() { return name; }	// para depuraci�n

  // Operaciones sobre el cerrojo. Ambas deben ser *at�micas*
  void Acquire(); 
  void Release();

  // devuelve 'true' si el hilo actual es quien posee el cerrojo.
  // �til para comprobaciones en el Release() y en las variables condici�n
  bool isHeldByCurrentThread();	

  private:
    const char* name;				// para depuraci�n
    Thread* holderThread;                       // Thread actualmente utilizando el lock.
    Semaphore* lockSem;                          // Semaforo binario. Maneja el lock.
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

    // libera el objeto
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
    Lock* conditionLock;
    List<Semaphore*> *waitingList;
};

class MailBox {
public: 
    MailBox(char* debugName, Lock* port);	// initialize a Mail Box for message 
											// passing 
    ~MailBox();								// deallocate the Mail Box
    const char* getName() { return(name);}

    void Send(Lock* port, int msg);			// Sends a message
    void Receive(Lock* port, int *msg);		// Receive a message
private:
    const char* name;
    int message, isBusy;
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
