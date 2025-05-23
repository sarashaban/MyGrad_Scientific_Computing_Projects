# Date : Nov 28 2013
 
 
# EC = mpif90 -fc=gfortran 
EC = gfortran 
CC = gcc 
CXX = g++ 
FC = gfortran 
 
CFLAGS = -Wall -g -pg -O3
FFLAGS = -Wall -g -pg -O3
FLAGS = -Wall -g -pg -O3
 
INCLUDE = -I / 
LIB_PATH = -L / 
LIBS = -lm
 
# The name of the executable file
EXE = zz 
 
# TO give a name of static libarary 
STATIC_LIB = libXXX.a
 
# Installing directory  
PREFIX = $(HOME)/local
 
# ------------------------------------------------ 
# To link the object files
 
All : $(EXE)
 
OBJS = sparse.o  main.o \
 \
 \
 \



$(EXE) : $(OBJS)
	$(EC) $(FLAGS) -o $(EXE) $(OBJS) $(INCLUDE) $(LIB_PATH) $(LIBS)

 
 
# ------------------------------------------------ 
# To compile the source files 
 
main.o : main.f90 
	$(FC) $(FFLAGS) -c  main.f90
 
sparse.o : sparse.f90 
	$(FC) $(FFLAGS) -c  sparse.f90
 
 
# ------------------------------------------------ 
# make run 
 
run : 
	./$(EXE)
 
clean : 
	rm *.swp  core.* *.mod gmon.prof
cleanall : 
	rm $(OBJS) *.swp *.swo core.* gmon.prof $(STATIC_LIB) *.mod 
