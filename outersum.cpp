#include <omp.h>
#include "mex.h"

extern "C" void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[])
{
    auto& column = prhs[0];
    auto& row = prhs[1];
    auto& scalar = prhs[2];
    auto& out = plhs[0];

    auto l = mxGetPr(scalar);
    auto m = mxGetM(column);
    auto n = mxGetN(row);

    auto C = (double*)mxGetPr(column);
    auto R = (double*)mxGetPr(row);
    auto a = int(l[0]);
   
    out = mxCreateDoubleMatrix(m, n,mxREAL);
    auto B = (double*)mxGetPr(out);

#pragma omp parallel for schedule(static)
    for(mwSize j = 0; j < n; j++)
        for(mwSize i = 0; i < m; i++)
            B[i + j*m] = C[i]+R[j]*a;
}
