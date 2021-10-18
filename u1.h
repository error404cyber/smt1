#include "lib.h"

typedef enum Error { OK, NOT_OK } Error;

void run_all_tests();
Error test_discr();
Error test_kv();
Error test_ln();
