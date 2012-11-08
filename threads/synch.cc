// synch.cc 
//	Routines for synchronizing threads.  Three kinds of
//	synchronization routines are defined here: semaphores, locks 
//   	and condition variables (the implementation of the last two
//	are left to the reader).
//
// Any implementation of a synchronization routine needs some
// primitive atomic operation.  We assume Nachos is running on
// a uniprocessor, and thus atomicity can be provided by
// turning off interrupts.  While interrupts are disabled, no
// context switch can occur, and thus the current thread is guaranteed
// to hold the CPU throughout, until interrupts are reenabled.
//
// Because some of these routines might be called with interrupts
// already disabled (Semaphore::V for one), instead of turning
// on interrupts at the end of the atomic operation, we always simply
// re-set the interrupt state back to its original value (whether
// that be disabled or enabled).
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "synch.h"
#include "system.h"

//----------------------------------------------------------------------
// Semaphore::Semaphore
// 	Initialize a semaphore, so that it can be used for synchronization.
//
//	"debugName" is an arbitrary name, useful for debugging.
//	"initialValue" is the initial value of the semaphore.
//----------------------------------------------------------------------

Semaphore::Semaphore(const char* debugName, int initialValue)
{
    name = debugName;
    value = initialValue;
    queue = new List<Thread*>;
}

//----------------------------------------------------------------------
// Semaphore::Semaphore
// 	De-allocate semaphore, when no longer needed.  Assume no one
//	is still waiting on the semaphore!
//----------------------------------------------------------------------

Semaphore::~Semaphore()
{
    delete queue;
}

//----------------------------------------------------------------------
// Semaphore::P
// 	Wait until semaphore value > 0, then decrement.  Checking the
//	value and decrementing must be done atomically, so we
//	need to disable interrupts before checking the value.
//
//	Note that Thread::Sleep assumes that interrupts are disabled
//	when it is called.
//----------------------------------------------------------------------

void
Semaphore::P()
{
    IntStatus oldLevel = interrupt->SetLevel(IntOff);	// disable interrupts
    
    while (value == 0) { 			// semaphore not available
	queue->Append(currentThread);		// so go to sleep
	currentThread->Sleep();
    } 
    value--; 					// semaphore available, 
						// consume its value
    
    interrupt->SetLevel(oldLevel);		// re-enable interrupts
}

//----------------------------------------------------------------------
// Semaphore::V
// 	Increment semaphore value, waking up a waiter if necessary.
//	As with P(), this operation must be atomic, so we need to disable
//	interrupts.  Scheduler::ReadyToRun() assumes that threads
//	are disabled when it is called.
//----------------------------------------------------------------------

void
Semaphore::V()
{
    Thread *thread;
    IntStatus oldLevel = interrupt->SetLevel(IntOff);

    thread = queue->Remove();
    if (thread != NULL)	   // make thread ready, consuming the V immediately
	scheduler->ReadyToRun(thread);
    value++;
    interrupt->SetLevel(oldLevel);
}

// Dummy functions -- so we can compile our later assignments 
// Note -- without a correct implementation of Condition::Wait(), 
// the test case in the network assignment won't work!
Lock::Lock(const char* debugName) 
{  
    name = debugName;
    holderThread = NULL;
    lockSem = new Semaphore("Semaphore from Lock", 1);
}

Lock::~Lock(){
    delete lockSem;
}

void Lock::Acquire() {
    ASSERT(!isHeldByCurrentThread());	// Arrgh! - Thread already owns the lock!
    lockSem->P();						// Si el lock esta libre, lo 
										  // toma; si no, espera a que
										  // le sea entregado.
	holderThread = currentThread;		// Indica el poseedor del lock. 
}


void Lock::Release() {
    ASSERT(isHeldByCurrentThread());	// Arrgh! - Thread not in possesion of the lock and doing a Release()!
    holderThread = NULL;				// Primero marcamos como NULL el holder, ya que de ocurrir un cambio de contexto
										  // antes de realizarlo habiendo desactivado el semaforo, puede hacer que al volver,
										  // pisemos el nuevo thread al volver a este punto.
    lockSem->V();						// Se libera el lock.
}

bool Lock::isHeldByCurrentThread() {
    return(currentThread == holderThread); // Chequea que el thread actual sea el poseedor del lock.
}

Condition::Condition(const char* debugName, Lock* condLock) { 
    name = debugName;
    this->conditionLock = condLock;
    waitingList = new List<Semaphore*>;
}

Condition::~Condition() {
    delete conditionLock;
    delete waitingList;
 }

void Condition::Wait() { 
    ASSERT(conditionLock->isHeldByCurrentThread()); // Chequea que el thread actual sea el poseedor del lock
    
    Semaphore *tmpSem = new Semaphore("Temporary Semaphore for Cond Var", 0); // Inicialmente cero, asi lo obligo a esperar la señal.
    waitingList->Append(tmpSem);					// Añado el nuevo semaforo a waitingQueue a la espera de la señal
    conditionLock->Release();						// Libero el lock
    tmpSem->P();									// Espero el signal (V()) en el semaforo
    conditionLock->Acquire();						// Recupero el cerrojo
    delete tmpSem;									// Elimino el semaforo creado

}
void Condition::Signal() { 
    ASSERT(conditionLock->isHeldByCurrentThread()); // Chequea que el thread actual sea el poseedor del lock

    if (!waitingList->IsEmpty())
      (waitingList->Remove())->V();	// Tomo un thread y le indico que puede continuar
}

void Condition::Broadcast() { 
    ASSERT(conditionLock->isHeldByCurrentThread());	// Chequea que el thread actual sea el poseedor del lock

    while (!waitingList->IsEmpty())
      (waitingList->Remove())->V();
    
}

MailBox::MailBox(char* debugName, Lock* port){
    name = debugName;
    mailRcv = new Condition("Cond of Receiver", port);
    mailSnd = new Condition("Cond of Sender", port);
	isBusy = 0;
	message = 0;
}

MailBox::~MailBox(){
    delete mailRcv;
    delete mailSnd;
};

void MailBox::Send(Lock* port, int msg){
    port->Acquire();
    while (isBusy == 1) mailRcv->Wait(); // Si hay alguien usando el 
											// puerto, se espera
    message = msg;						 // Se guarda el mensaje
    isBusy = 1;							 //	Se indicia que el
											// puerto esta en uso
    mailSnd->Signal();				 	 // Aviso a un threads entre los
											// que estan escuchando ese
											// puerto que hay un mensaje
	ASSERT(port->isHeldByCurrentThread());
    port->Release();					 
}

void MailBox:: Receive(Lock* port, int *msg) {
    port->Acquire();
	while (isBusy == 0) mailSnd->Wait(); // No hay mensajes en el 
											//puerto? Espera a que haya
    *msg = message;					 	 // Obtiene el mensaje.

    isBusy = 0;							 //	El mailBox esta libre.
    mailRcv->Signal();				// Aviso que ya recibi el msj
    
    ASSERT(port->isHeldByCurrentThread());
    
    port->Release();
}
