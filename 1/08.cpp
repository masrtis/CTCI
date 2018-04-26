/* Write a function that takes an MxN matrix. If an element in the matrix is 0, set that row and column to zero. */

#include <vector>

//We need to set the zeros in a way that doesn't trip up the rest of the processing.
//i.e. no forward setting zeros. Keep them in a bit vector.

using namespace std;

typedef vector< vector< int > > matrix;

void ZeroMatrixOut( matrix& mat )
{
    if( mat.size() == 0 )
        return;

    size_t M = mat.size();
    size_t N = mat[0].size();
    vector< bool > zeroRows( M, false );
    vector< bool > zeroCols( N, false );

    for( size_t y = 0; y < M; ++y )
    {
        for( size_t x = 0; x < N; ++x)
        {
            if( mat[y][x] == 0 )
            {
                zeroRows[y] = true;
                zeroCols[x] = true;
            }
        }
    }

    for( size_t y = 0; y < M; ++y )
    {
        for( size_t x = 0; x < N; ++x)
        {
            if( zeroRows[y] || zeroCols[x] )
            {
                mat[y][x] = 0;
            }
        }
    }
    //A more efficient way to achieve the above is to iterate over the zero storage rather than over the matrix, and just
    //wipe a row or column. Saves iterating over matrix elements you won't want to zero out, but you WILL double zero
    //over crossing points
}

#include <iostream>
void PrintMatrix( const matrix& mat )
{
    for(auto y = 0; y < mat.size(); ++y )
    {
        for(auto x = 0; x < mat[0].size(); ++x )
        {
            cout << mat[y][x] << ' ';

            if( x == mat[0].size() - 1 )
                cout << endl;
        }
    }
}

#include <random>
matrix GenerateMatrix()
{
    typedef std::mt19937 rng_type;
    std::uniform_int_distribution<rng_type::result_type> udist(0, 7);
    rng_type rng;
    rng_type::result_type const seedval = 5; // whatever
    rng.seed(seedval);

    matrix out( 5, vector< int >( 8 ) );
    for( int y = 0; y < out.size(); ++y )
    {
        for( int x = 0; x < out[0].size(); ++x )
        {
            out[y][x] = udist( rng );
        }
    }
    return out;
}


int main()
{
    matrix m = GenerateMatrix();
    PrintMatrix( m );

    ZeroMatrixOut( m );

    cout << endl;

    PrintMatrix( m );
    getchar();
    return 0;
}