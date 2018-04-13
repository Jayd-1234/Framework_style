#include <Vc/Vc>
#include <omp.h>

using namespace std;
using namespace Vc;

// How does Vc fit in the framework? 
// Emulates the mean operation of numpy (np.mean(x1))
double mean(double *x, int len)
{
    double sum=0.0;

   // Can be parallelized with OpenMP.
   // #pragma omp parallel for
    for(int i=0; i<len; i++)
    {
        sum += x[i];
    }    

    return sum/len;
}