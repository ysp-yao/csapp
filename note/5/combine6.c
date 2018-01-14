#include "vec.h"

/* 2 x 2 loop unrolling */
void combine6(vec_ptr v, data_t *dest) {
  long i;
  long length = vec_length(v);
  long limit = length - 1;
  data_t *data = get_vec_start(v);
  data_t acc0 = IDENT;
  data_t acc1 = IDENT;

  
  /* Combine 2 element at a time */
  for (i=0; i<limit; i+=2) {
    acc0 = acc0 OP data[i];
    acc1 = acc1 OP data[i+1];
  }
  
  /* Finish any remaining elements */
  for (; i<length; i++) {
    acc0 = acc0 OP data[i];
  }
  *dest = acc0 OP acc1;
}