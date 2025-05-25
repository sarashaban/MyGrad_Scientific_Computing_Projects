# include <cstdlib>
# include <iostream>
# include <cmath>
# include <ctime>

// CHANGE 1) Include the OpenMP include file
# include <omp.h>

using namespace std;

//****************************************************************************80

int main ( int argc, char *argv[] )

//****************************************************************************80
{
  double a = 0.0;
  double b = 10.0;
  double error;
  double exact = 0.49936338107645674464;
  int i;
  int n = 1000000;
  double pi = 3.141592653589793;
  double total;
  double wtime = 0.0;
  double *x;

  cout << "\n";
  cout << "QUAD:\n";
  cout << "  C++ version\n";
  cout << "\n";
  cout << "  Estimate the integral of f(x) from A to B.\n";
  cout << "  f(x) = 50 / ( pi * ( 2500 * x * x + 1 ) ).\n";
  cout << "  A = " << a << "\n";
  cout << "  B = " << b << "\n";
  cout << "  Exact integral from 0 to 10 is 0.49936338107645674464...\n";

  x = new double[n];

  for ( i = 0; i < n; i++ )
  {
    x[i] =  ( ( double ) ( n - i - 1 ) * a   
            + ( double ) (     i     ) * b ) 
            / ( double ) ( n     - 1 );
  }

  // CHANGE 2) Use the OpenMP timer to initialize WTIME
  wtime = omp_get_wtime();

  total = 0.0;

  // CHANGE 3) Add OpenMP directives for parallel reduction
  # pragma omp parallel for private(i) shared(x,n,pi) reduction(+:total)
  for ( i = 0; i < n; i++ )
  {
    total = total + 50.0 / ( pi * ( 2500.0 * x[i] * x[i] + 1.0 ) );
  }

  total = ( b - a ) * total / ( double ) n;

  // CHANGE 4) Call the OpenMP timer again
  wtime = omp_get_wtime() - wtime;

  error = fabs ( total - exact );

  cout << "\n";
  cout << "  Estimate = " << total << "\n";
  cout << "  Error    = " << error << "\n";
  cout << "  Wallclock time = " << wtime << " seconds\n";

  delete [] x;

  return 0;
}
