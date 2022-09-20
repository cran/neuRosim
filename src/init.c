#include <stddef.h>
#include <R_ext/Rdynload.h>

extern void sim_grf(int *dim, double *filtermat, int *ksize, int *mask, int *type, double *ans, double *max);

static const R_CMethodDef cMethods[] = {
    {"sim_grf", (DL_FUNC) &sim_grf, 7},
    {NULL, NULL, 0}
  };

void R_init_neurosim(DllInfo *info) {
  /* Register the .C routines.
   No and .Call, .Fortran() or .External() routines,
   so pass those arrays as NULL.
   */
  R_registerRoutines(info,
                     cMethods, NULL, NULL, NULL);
  R_useDynamicSymbols(info, TRUE);
}
