#include "vec.h"

void combine4(vec_ptr v, data_t *dest) {
  long i;
  long length = vec_length(v);
  data_t *data = get_vec_start(v);
  data_t acc = IDENT;
  
  for (i=0; i<length; i++) {
    acc = acc OP data[i];
  }
  *dest = acc;
}

/* Include bounds check in loop */
void combine4b(vec_ptr v, data_t *dest) {
  long i;
  long length = vec_length(v);
  data_t acc = IDENT;
  
  for (i=0; i<length; i++) {
    if (i>=0 && i<v->len) {
      acc = acc OP data[i];
    }
  }
  *dest = acc;
}