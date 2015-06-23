#include <stdio.h>



int main()
{
    int A[ 100 ], k, s, i;
    int L = 3, Base = 10;
    A[ 0 ] = s = k = 0;

    for ( ; ; ) {
        if ( A[ k ] == Base || s < 0 ) {
            if ( k == 0 ) {
              break;
            }

            s += A[k] * ( ( k / L ) * 2 - 1 );
            A[ --k ]++;
            s -= ( k / L ) * 2 - 1;
        }
        else if ( k == 2 * L - 1 ) {
            for ( i = 0; i <= k; i++ ) {
              putchar(A[i]+'0');
            }
            putchar('\n');
            A[ k ]++;
            s--;
        }
        else {
            k++;
            A[ k ] = s - ( 2 * L - 1 - k ) * ( Base - 1 );
            if ( A[ k ] < 0 ) A[ k ] = 0;
            s -= A[ k ] * ( ( k / L ) * 2 - 1 );
        }
    }

    return 0;
}
