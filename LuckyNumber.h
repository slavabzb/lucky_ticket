#ifndef LUCKYNUMBER_H
#define LUCKYNUMBER_H

#include <cmath>
#include <vector>



template< typename T >
class LuckyNumber
{
  typedef T value_t;
  typedef std::vector< value_t > container_t;



public:

  value_t decomposition_count( value_t j, value_t n, value_t m )
  {
    if ( m == 0 ) {
      return ( n <= this->l ) ? 1 : 0;
    }

    if ( m == n ) {
      return 1;
    }

    if ( j > 0 ) {
      value_t right = this->decomposition_count( j - 1, n - 1, m ) +
        this->decomposition_count( this->l, n - 1, m - 1 );

      return right;
    }
    else {
      value_t left = this->decomposition_count( this->l, n - 1, m - 1 );

      return left;
    }
  }



  void generate_decomposition( container_t& v, value_t num, value_t j, value_t n, value_t m )
  {
    if ( m == 0 ) {
      if ( n > this->l ) {
        return;
      }

      for ( value_t i = 1; i <= n; i++ ) {
        v.push_back( 0 );
      }

      return;
    }

    if ( m == n ) {
      for ( value_t i = 1; i <= n; i++ ) {
        v.push_back( 1 );
      }

      return;
    }

    value_t b = this->decomposition_count( j - 1, n - 1, m );

    if ( num <= b && j > 0 ) {
      v.push_back( 0 );
      this->generate_decomposition( v, num, j - 1, n - 1, m );
    }
    else {
      v.push_back( 1 );

      if ( j == 0 ) {
        this->generate_decomposition( v, num, j, n - 1, m - 1 );
      }
      else {
        this->generate_decomposition( v, num - b, this->l, n - 1, m - 1 );

        return;
      }
    }
  }



  container_t generate_lucky_ticket( value_t iNumber, value_t iNum )
  {
    value_t iHalf = iNumber / 2.0;
    value_t iLength = iHalf * this->l;
    value_t b = 1;

    value_t i;
    for ( i = 0; i <= iLength; ++i ) {
      if ( i <= ( iLength / 2.0 ) ) {
        b = this->decomposition_count( this->l, i + iHalf - 1, iHalf - 1 );
      }
      else {
        b = this->decomposition_count( this->l, iLength - i + iHalf - 1, iHalf - 1 );
      }

      if ( ( iNum - std::pow( b, 2 ) ) < 0 ) {
        break;
      }

      iNum -= std::pow( b, 2 );
    }

    value_t iNumLeft = iNum / static_cast<double_t>( b );
    value_t iNumRight = iNum % b;

    container_t left;
    this->generate_decomposition( left, iNumLeft + 1, this->l, i + iHalf - 1, iHalf - 1 );

    container_t right;
    this->generate_decomposition( right, iNumRight + 1, this->l, i + iHalf - 1, iHalf - 1 );

    container_t lucky_ticket;
    for ( std::size_t k = 0; k < left.size(); ++k ) {
      lucky_ticket.push_back( left[ k ] );
    }

    for ( std::size_t k = 0; k < right.size(); ++k ) {
      lucky_ticket.push_back( right[ k ] );
    }

    return lucky_ticket;
  }



  container_t generate_lucky_ticket_list( value_t iNumber )
  {
    for ( value_t i = 0; i < 55251; ++i ) {

    }
  }



  const value_t l = 3;
};

#endif // LUCKYNUMBER_H
