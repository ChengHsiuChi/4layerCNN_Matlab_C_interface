#include <omp.h>
#include "mex.h"

extern "C" void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[])
{
    auto& matrix = prhs[0];
    auto& indices = prhs[1];
    auto& out = plhs[0];
    
    auto m = mxGetM(indices);
    auto n = mxGetN(indices);
   
    auto A = (double*)mxGetPr(matrix);
    auto a = mxGetPr(indices);
   
    out = mxCreateDoubleMatrix(m, n,mxREAL);
    auto B = (double*)mxGetPr(out);

#pragma omp parallel for schedule(static)
    for(mwSize j = 0; j < n; j++)
        for(mwSize i = 0; i < m; i++)
            B[j * m + i] = A[int(a[j*m+i]) - 1];
            
}
