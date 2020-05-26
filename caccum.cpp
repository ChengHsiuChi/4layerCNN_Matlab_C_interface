#include <omp.h>
#include "mex.h"

extern "C" void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[])
{
    auto& indices = prhs[0];
    auto& matrix = prhs[1];
    auto& out = plhs[0];
    auto& temp = prhs[2];
    
    auto l = mxGetM(indices);
    auto m = mxGetPr(temp);
    auto n = int(m[0]);

    auto A = (float*)mxGetPr(matrix);
    auto a = mxGetPr(indices);
   
    out = mxCreateNumericMatrix(n, 1 , mxSINGLE_CLASS, mxREAL);
    auto B = (float*)mxGetPr(out);

#pragma omp parallel for
    for(mwSize i = 0; i < n; i++)
        B[i] = 0;
#pragma omp parallel for //schedule(static)
    for(mwSize i = 0; i < l; i++)
        B[int(a[i])-1] = B[int(a[i])-1] + A[i];
}
