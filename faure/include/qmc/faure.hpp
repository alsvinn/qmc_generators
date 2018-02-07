#include <string>

namespace faure {
int *binomial_table ( int qs, int m, int n );
void faure ( int dim_num, int *seed, double quasi[] );
double *faure_generate ( int dim_num, int n, int skip );
int i4_log_i4 ( int i4, int j4 );
int i4_min ( int i1, int i2 );
int i4_power ( int i, int j );
int prime ( int n );
int prime_ge ( int n );
void r8mat_write ( std::string output_filename, int m, int n, double table[] );
void timestamp ( );
}
