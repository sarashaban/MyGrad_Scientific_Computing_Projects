https://people.sc.fsu.edu/~jburkardt/classes/acs2_openmp_2013/acs2_openmp_2013.html

Tasks:
The task is to make 4 modifications to the program so that it can take advantage of OpenMP. These changes will involve:
1. Adding an "include" or "use" statement to get the OpenMP include file.
2. Calling the OpenMP timer function omp_get_wtime() to initialize the timer measurement wtime.
3. Inserting two OpenMP directives just before the loop. The first directive lists private and shared
variables. The second will tell OpenMP that the total variable is a reduction variable. (This change
is the the hardest, and most important one, to do correctly!)
4. Calling the OpenMP timer function omp_get_wtime() to update the timer measurement wtime.

Once you've made your changes, compile the program. Your compile statement must now include a switch indicating that OpenMP is in use. 

You set the number of threads with a command like
export OMP_THREAD_NUM=4
Run the program 4 times, setting the number of threads to 1, 2, 4 and 8, and recording the value of wall clock time. 


g++ -fopenmp -O2 -std=c++11 quad_omp.cpp -o quad

export OMP_NUM_THREADS=1
./quad

export OMP_NUM_THREADS=2
./quad

export OMP_NUM_THREADS=4
./quad

export OMP_NUM_THREADS=8
./quad
************************************************************************

 export OMP_NUM_THREADS=1
./quad 

  Estimate the integral of f(x) from A to B.
  f(x) = 50 / ( pi * ( 2500 * x * x + 1 ) ).
  A = 0
  B = 10
  Exact integral from 0 to 10 is 0.49936338107645674464...

  Estimate = 0.499442
  Error    = 7.90784e-05
  Wallclock time = 0.0117707 seconds
  
  
export OMP_NUM_THREADS=2
./quad 

  Estimate the integral of f(x) from A to B.
  f(x) = 50 / ( pi * ( 2500 * x * x + 1 ) ).
  A = 0
  B = 10
  Exact integral from 0 to 10 is 0.49936338107645674464...

  Estimate = 0.499442
  Error    = 7.90784e-05
  Wallclock time = 0.00610914 seconds
  
export OMP_NUM_THREADS=4
./quad 

  Estimate the integral of f(x) from A to B.
  f(x) = 50 / ( pi * ( 2500 * x * x + 1 ) ).
  A = 0
  B = 10
  Exact integral from 0 to 10 is 0.49936338107645674464...

  Estimate = 0.499442
  Error    = 7.90784e-05
  Wallclock time = 0.00329667 seconds
  

export OMP_NUM_THREADS=8
/quad 


  Estimate the integral of f(x) from A to B.
  f(x) = 50 / ( pi * ( 2500 * x * x + 1 ) ).
  A = 0
  B = 10
  Exact integral from 0 to 10 is 0.49936338107645674464...

  Estimate = 0.499442
  Error    = 7.90784e-05
  Wallclock time = 0.00215233 seconds



