# NOTE: this is a GNU Makefile.  You must use "gmake" rather than "make".
#
# Makefile for the virtual memory assignment
#    Defines set up assuming the virtual memory assignment is done before 
# 	the file system assignment. If not, use the "filesys first"  
#	defines below. 
#
# Also, if you want to simplify the translation so it assumes
# only linear page tables, don't define USE_TLB.
#
# Copyright (c) 1992 The Regents of the University of California.
# All rights reserved.  See copyright.h for copyright notice and limitation 
# of liability and disclaimer of warranty provisions.

DEFINES = -DUSER_PROGRAM  -DFILESYS_NEEDED -DFILESYS_STUB -DVM -DUSE_TLB
INCPATH = -I../filesys -I../bin -I../vm -I../userprog -I../threads -I../machine
HFILES = $(THREAD_H) $(USERPROG_H) $(VM_H)
CFILES = $(THREAD_C) $(USERPROG_C) $(VM_C)
C_OFILES = $(THREAD_O) $(USERPROG_O) $(VM_O)

# if file sys done first!
# DEFINES = -DUSER_PROGRAM -DFILESYS_NEEDED -DFILESYS -DVM -DUSE_TLB
# INCPATH = -I../vm -I../bin -I../filesys -I../userprog -I../threads -I../machine
# HFILES = $(THREAD_H) $(USERPROG_H) $(FILESYS_H) $(VM_H)
# CFILES = $(THREAD_C) $(USERPROG_C) $(FILESYS_C) $(VM_C)
# C_OFILES = $(THREAD_O) $(USERPROG_O) $(FILESYS_O) $(VM_O)

include ../Makefile.common
include ../Makefile.dep
#-----------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend uses it
# DEPENDENCIES MUST END AT END OF FILE
main.o: ../threads/main.cc ../threads/copyright.h ../threads/utility.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdlib.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../threads/system.h ../threads/thread.h ../threads/synch.h \
 ../threads/list.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/memorybitmap.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../userprog/coremap.h \
 ../threads/list.h ../bin/noff.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h
scheduler.o: ../threads/scheduler.cc ../threads/copyright.h \
 ../threads/scheduler.h ../threads/list.h ../threads/utility.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdlib.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../threads/thread.h ../threads/synch.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/memorybitmap.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../userprog/coremap.h ../threads/list.h ../bin/noff.h \
 ../threads/system.h ../machine/interrupt.h ../machine/stats.h \
 ../machine/timer.h
synch.o: ../threads/synch.cc ../threads/copyright.h ../threads/synch.h \
 ../threads/thread.h ../threads/utility.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/memorybitmap.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../userprog/coremap.h ../threads/list.h \
 ../bin/noff.h ../threads/list.h ../threads/system.h \
 ../threads/scheduler.h ../machine/interrupt.h ../machine/stats.h \
 ../machine/timer.h
system.o: ../threads/system.cc ../threads/copyright.h ../threads/system.h \
 ../threads/utility.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../threads/thread.h ../threads/synch.h ../threads/list.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/memorybitmap.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../userprog/coremap.h ../threads/list.h \
 ../bin/noff.h ../threads/scheduler.h ../machine/interrupt.h \
 ../machine/stats.h ../machine/timer.h ../threads/preemptive.h
thread.o: ../threads/thread.cc ../threads/copyright.h ../threads/thread.h \
 ../threads/utility.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../threads/synch.h ../threads/list.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/memorybitmap.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../userprog/coremap.h ../threads/list.h ../bin/noff.h \
 ../threads/switch.h ../threads/system.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h
utility.o: ../threads/utility.cc ../threads/copyright.h \
 ../threads/utility.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h
threadtest.o: ../threads/threadtest.cc ../threads/copyright.h \
 ../threads/system.h ../threads/utility.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../threads/thread.h ../threads/synch.h ../threads/list.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/memorybitmap.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../userprog/coremap.h ../threads/list.h \
 ../bin/noff.h ../threads/scheduler.h ../machine/interrupt.h \
 ../machine/stats.h ../machine/timer.h
interrupt.o: ../machine/interrupt.cc ../threads/copyright.h \
 ../machine/interrupt.h ../threads/list.h ../threads/copyright.h \
 ../threads/utility.h ../machine/sysdep.h /usr/include/stdlib.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../threads/system.h ../threads/thread.h ../threads/synch.h \
 ../threads/list.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/memorybitmap.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../userprog/coremap.h \
 ../bin/noff.h ../threads/scheduler.h ../machine/interrupt.h \
 ../machine/stats.h ../machine/timer.h
sysdep.o: ../machine/sysdep.cc ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/wchar.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h /usr/include/signal.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/signum.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/bits/siginfo.h \
 /usr/include/i386-linux-gnu/bits/sigaction.h \
 /usr/include/i386-linux-gnu/bits/sigcontext.h \
 /usr/include/i386-linux-gnu/asm/sigcontext.h /usr/include/linux/types.h \
 /usr/include/i386-linux-gnu/asm/types.h /usr/include/asm-generic/types.h \
 /usr/include/asm-generic/int-ll64.h \
 /usr/include/i386-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/i386-linux-gnu/asm/posix_types.h \
 /usr/include/i386-linux-gnu/asm/posix_types_32.h \
 /usr/include/i386-linux-gnu/bits/sigstack.h \
 /usr/include/i386-linux-gnu/sys/ucontext.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h \
 /usr/include/i386-linux-gnu/bits/sigthread.h \
 /usr/include/i386-linux-gnu/sys/types.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/sys/socket.h \
 /usr/include/i386-linux-gnu/sys/uio.h \
 /usr/include/i386-linux-gnu/bits/uio.h \
 /usr/include/i386-linux-gnu/bits/socket.h \
 /usr/include/i386-linux-gnu/bits/sockaddr.h \
 /usr/include/i386-linux-gnu/asm/socket.h \
 /usr/include/asm-generic/socket.h \
 /usr/include/i386-linux-gnu/asm/sockios.h \
 /usr/include/asm-generic/sockios.h \
 /usr/include/i386-linux-gnu/sys/file.h /usr/include/fcntl.h \
 /usr/include/i386-linux-gnu/bits/fcntl.h \
 /usr/include/i386-linux-gnu/bits/stat.h \
 /usr/include/i386-linux-gnu/sys/un.h \
 /usr/include/i386-linux-gnu/sys/mman.h \
 /usr/include/i386-linux-gnu/bits/mman.h \
 /usr/include/i386-linux-gnu/sys/time.h \
 /usr/include/i386-linux-gnu/sys/syscall.h \
 /usr/include/i386-linux-gnu/asm/unistd.h \
 /usr/include/i386-linux-gnu/asm/unistd_32.h \
 /usr/include/i386-linux-gnu/bits/syscall.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/stdlib.h /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/alloca.h \
 ../machine/interrupt.h ../threads/list.h ../threads/copyright.h \
 ../threads/utility.h ../machine/sysdep.h ../threads/system.h \
 ../threads/thread.h ../threads/synch.h ../threads/list.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/memorybitmap.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../userprog/coremap.h ../bin/noff.h \
 ../threads/scheduler.h ../machine/interrupt.h ../machine/stats.h \
 ../machine/timer.h
stats.o: ../machine/stats.cc ../threads/copyright.h ../threads/utility.h \
 ../threads/copyright.h ../machine/sysdep.h /usr/include/stdlib.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../machine/stats.h
timer.o: ../machine/timer.cc ../threads/copyright.h ../machine/timer.h \
 ../threads/utility.h ../threads/copyright.h ../machine/sysdep.h \
 /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../threads/system.h ../threads/utility.h ../threads/thread.h \
 ../threads/synch.h ../threads/list.h ../machine/machine.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/memorybitmap.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../userprog/coremap.h \
 ../threads/list.h ../bin/noff.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h
preemptive.o: ../threads/preemptive.cc ../threads/preemptive.h \
 ../threads/system.h ../threads/copyright.h ../threads/utility.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdlib.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../threads/thread.h ../threads/synch.h ../threads/list.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/memorybitmap.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../userprog/coremap.h ../threads/list.h \
 ../bin/noff.h ../threads/scheduler.h ../machine/interrupt.h \
 ../machine/stats.h ../machine/timer.h /usr/include/unistd.h \
 /usr/include/i386-linux-gnu/bits/posix_opt.h \
 /usr/include/i386-linux-gnu/bits/environments.h \
 /usr/include/i386-linux-gnu/bits/confname.h /usr/include/getopt.h \
 /usr/include/i386-linux-gnu/sys/ptrace.h \
 /usr/include/i386-linux-gnu/sys/wait.h /usr/include/signal.h \
 /usr/include/i386-linux-gnu/bits/signum.h \
 /usr/include/i386-linux-gnu/bits/siginfo.h \
 /usr/include/i386-linux-gnu/bits/sigaction.h \
 /usr/include/i386-linux-gnu/bits/sigcontext.h \
 /usr/include/i386-linux-gnu/asm/sigcontext.h /usr/include/linux/types.h \
 /usr/include/i386-linux-gnu/asm/types.h /usr/include/asm-generic/types.h \
 /usr/include/asm-generic/int-ll64.h \
 /usr/include/i386-linux-gnu/asm/bitsperlong.h \
 /usr/include/asm-generic/bitsperlong.h /usr/include/linux/posix_types.h \
 /usr/include/linux/stddef.h \
 /usr/include/i386-linux-gnu/asm/posix_types.h \
 /usr/include/i386-linux-gnu/asm/posix_types_32.h \
 /usr/include/i386-linux-gnu/bits/sigstack.h \
 /usr/include/i386-linux-gnu/sys/ucontext.h \
 /usr/include/i386-linux-gnu/bits/sigthread.h \
 /usr/include/i386-linux-gnu/sys/resource.h \
 /usr/include/i386-linux-gnu/bits/resource.h \
 /usr/include/i386-linux-gnu/sys/user.h
addrspace.o: ../userprog/addrspace.cc ../threads/copyright.h \
 ../threads/system.h ../threads/copyright.h ../threads/utility.h \
 ../machine/sysdep.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../threads/thread.h ../threads/synch.h ../threads/list.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/memorybitmap.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../userprog/coremap.h ../threads/list.h \
 ../bin/noff.h ../threads/scheduler.h ../machine/interrupt.h \
 ../machine/stats.h ../machine/timer.h ../userprog/addrspace.h \
 ../userprog/syscall_utils.h
bitmap.o: ../userprog/bitmap.cc ../threads/copyright.h \
 ../userprog/bitmap.h ../threads/utility.h ../threads/copyright.h \
 ../machine/sysdep.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../filesys/openfile.h
exception.o: ../userprog/exception.cc ../threads/copyright.h \
 ../threads/system.h ../threads/copyright.h ../threads/utility.h \
 ../machine/sysdep.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../threads/thread.h ../threads/synch.h ../threads/list.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/memorybitmap.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../userprog/coremap.h ../threads/list.h \
 ../bin/noff.h ../threads/scheduler.h ../machine/interrupt.h \
 ../machine/stats.h ../machine/timer.h ../userprog/syscall.h \
 ../userprog/syscall_utils.h ../userprog/addrspace.h \
 ../userprog/exception_imp.h ../userprog/synchconsole.h \
 ../threads/synch.h ../machine/console.h /usr/include/c++/4.6/map \
 /usr/include/c++/4.6/bits/stl_tree.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/stl_map.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/stl_multimap.h \
 /usr/include/c++/4.6/bits/range_access.h
progtest.o: ../userprog/progtest.cc ../threads/copyright.h \
 ../threads/system.h ../threads/copyright.h ../threads/utility.h \
 ../machine/sysdep.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../threads/thread.h ../threads/synch.h ../threads/list.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/memorybitmap.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../userprog/coremap.h ../threads/list.h \
 ../bin/noff.h ../threads/scheduler.h ../machine/interrupt.h \
 ../machine/stats.h ../machine/timer.h ../machine/console.h \
 ../userprog/addrspace.h ../threads/synch.h
console.o: ../machine/console.cc ../threads/copyright.h \
 ../machine/console.h ../threads/utility.h ../threads/copyright.h \
 ../machine/sysdep.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../threads/system.h ../threads/utility.h ../threads/thread.h \
 ../threads/synch.h ../threads/list.h ../machine/machine.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/memorybitmap.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../userprog/coremap.h \
 ../threads/list.h ../bin/noff.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h
machine.o: ../machine/machine.cc ../threads/copyright.h \
 ../machine/machine.h ../threads/utility.h ../threads/copyright.h \
 ../machine/sysdep.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../machine/translate.h ../machine/disk.h ../threads/system.h \
 ../threads/utility.h ../threads/thread.h ../threads/synch.h \
 ../threads/list.h ../machine/machine.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/memorybitmap.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../userprog/coremap.h \
 ../threads/list.h ../bin/noff.h ../threads/scheduler.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h
mipssim.o: ../machine/mipssim.cc ../threads/copyright.h \
 ../machine/machine.h ../threads/utility.h ../threads/copyright.h \
 ../machine/sysdep.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../machine/translate.h ../machine/disk.h ../machine/mipssim.h \
 ../threads/system.h ../threads/utility.h ../threads/thread.h \
 ../threads/synch.h ../threads/list.h ../machine/machine.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../userprog/memorybitmap.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../userprog/coremap.h ../threads/list.h ../bin/noff.h \
 ../threads/scheduler.h ../machine/interrupt.h ../machine/stats.h \
 ../machine/timer.h
translate.o: ../machine/translate.cc ../threads/copyright.h \
 ../machine/machine.h ../threads/utility.h ../threads/copyright.h \
 ../machine/sysdep.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/memorybitmap.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../machine/machine.h \
 ../userprog/coremap.h ../threads/list.h ../threads/utility.h \
 ../bin/noff.h ../threads/system.h ../threads/thread.h ../threads/synch.h \
 ../threads/list.h ../threads/scheduler.h ../machine/interrupt.h \
 ../machine/stats.h ../machine/timer.h
syscall_utils.o: ../userprog/syscall_utils.cc ../threads/system.h \
 ../threads/copyright.h ../threads/utility.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../threads/thread.h ../threads/synch.h ../threads/list.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/memorybitmap.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../userprog/coremap.h ../threads/list.h \
 ../bin/noff.h ../threads/scheduler.h ../machine/interrupt.h \
 ../machine/stats.h ../machine/timer.h ../userprog/syscall_utils.h \
 ../userprog/addrspace.h /usr/include/c++/4.6/map \
 /usr/include/c++/4.6/bits/stl_tree.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/stl_map.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/stl_multimap.h \
 /usr/include/c++/4.6/bits/range_access.h
synchconsole.o: ../userprog/synchconsole.cc ../userprog/synchconsole.h \
 ../threads/synch.h ../threads/copyright.h ../threads/thread.h \
 ../threads/utility.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../threads/synch.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../userprog/memorybitmap.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../userprog/coremap.h \
 ../threads/list.h ../bin/noff.h ../threads/list.h ../machine/console.h \
 ../threads/system.h ../threads/scheduler.h ../machine/interrupt.h \
 ../machine/stats.h ../machine/timer.h
memorybitmap.o: ../userprog/memorybitmap.cc ../userprog/memorybitmap.h \
 ../userprog/bitmap.h ../threads/copyright.h ../threads/utility.h \
 ../threads/copyright.h ../machine/sysdep.h /usr/include/stdlib.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../filesys/openfile.h ../machine/machine.h ../machine/translate.h \
 ../machine/disk.h
coremap.o: ../userprog/coremap.cc ../userprog/memorybitmap.h \
 ../userprog/bitmap.h ../threads/copyright.h ../threads/utility.h \
 ../threads/copyright.h ../machine/sysdep.h /usr/include/stdlib.h \
 /usr/include/features.h /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../filesys/openfile.h ../machine/machine.h ../machine/translate.h \
 ../machine/disk.h ../userprog/coremap.h ../threads/list.h \
 ../threads/utility.h ../threads/system.h ../threads/thread.h \
 ../threads/synch.h ../threads/list.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../bin/noff.h \
 ../threads/scheduler.h ../machine/interrupt.h ../machine/stats.h \
 ../machine/timer.h
exception_imp.o: ../userprog/exception_imp.cc ../threads/system.h \
 ../threads/copyright.h ../threads/utility.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdlib.h /usr/include/features.h \
 /usr/include/i386-linux-gnu/bits/predefs.h \
 /usr/include/i386-linux-gnu/sys/cdefs.h \
 /usr/include/i386-linux-gnu/bits/wordsize.h \
 /usr/include/i386-linux-gnu/gnu/stubs.h \
 /usr/include/i386-linux-gnu/gnu/stubs-32.h \
 /usr/lib/gcc/i686-linux-gnu/4.6/include/stddef.h \
 /usr/include/i386-linux-gnu/bits/waitflags.h \
 /usr/include/i386-linux-gnu/bits/waitstatus.h /usr/include/endian.h \
 /usr/include/i386-linux-gnu/bits/endian.h \
 /usr/include/i386-linux-gnu/bits/byteswap.h /usr/include/xlocale.h \
 /usr/include/i386-linux-gnu/sys/types.h \
 /usr/include/i386-linux-gnu/bits/types.h \
 /usr/include/i386-linux-gnu/bits/typesizes.h /usr/include/time.h \
 /usr/include/i386-linux-gnu/sys/select.h \
 /usr/include/i386-linux-gnu/bits/select.h \
 /usr/include/i386-linux-gnu/bits/sigset.h \
 /usr/include/i386-linux-gnu/bits/time.h \
 /usr/include/i386-linux-gnu/sys/sysmacros.h \
 /usr/include/i386-linux-gnu/bits/pthreadtypes.h /usr/include/alloca.h \
 /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h \
 /usr/include/wchar.h /usr/lib/gcc/i686-linux-gnu/4.6/include/stdarg.h \
 /usr/include/i386-linux-gnu/bits/stdio_lim.h \
 /usr/include/i386-linux-gnu/bits/sys_errlist.h /usr/include/string.h \
 ../threads/thread.h ../threads/synch.h ../threads/list.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../userprog/memorybitmap.h ../userprog/bitmap.h \
 ../filesys/openfile.h ../userprog/coremap.h ../threads/list.h \
 ../bin/noff.h ../threads/scheduler.h ../machine/interrupt.h \
 ../machine/stats.h ../machine/timer.h ../userprog/synchconsole.h \
 ../threads/synch.h ../machine/console.h ../userprog/syscall.h \
 ../userprog/syscall_utils.h ../userprog/addrspace.h \
 ../userprog/exception_imp.h /usr/include/c++/4.6/map \
 /usr/include/c++/4.6/bits/stl_tree.h \
 /usr/include/c++/4.6/bits/stl_algobase.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++config.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/os_defines.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/cpu_defines.h \
 /usr/include/c++/4.6/bits/functexcept.h \
 /usr/include/c++/4.6/bits/exception_defines.h \
 /usr/include/c++/4.6/bits/cpp_type_traits.h \
 /usr/include/c++/4.6/ext/type_traits.h \
 /usr/include/c++/4.6/ext/numeric_traits.h \
 /usr/include/c++/4.6/bits/stl_pair.h /usr/include/c++/4.6/bits/move.h \
 /usr/include/c++/4.6/bits/concept_check.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.6/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.6/bits/stl_iterator.h \
 /usr/include/c++/4.6/debug/debug.h /usr/include/c++/4.6/bits/allocator.h \
 /usr/include/c++/4.6/i686-linux-gnu/./bits/c++allocator.h \
 /usr/include/c++/4.6/ext/new_allocator.h /usr/include/c++/4.6/new \
 /usr/include/c++/4.6/exception /usr/include/c++/4.6/bits/stl_function.h \
 /usr/include/c++/4.6/backward/binders.h \
 /usr/include/c++/4.6/bits/stl_map.h \
 /usr/include/c++/4.6/initializer_list \
 /usr/include/c++/4.6/bits/stl_multimap.h \
 /usr/include/c++/4.6/bits/range_access.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
