int srav(double x, double y);
void scan_coefficients(double *ptr_to_a, double *ptr_to_b, double *ptr_to_c);
void discr(double a, double b, double c, double *D);
void resh_kv(double a, double b, double c, double d, double *x1, double *x2);
KORNI resh_lin(double b, double c, double *x1);
KORNI resh(double a, double b, double c, double *x1, double *x2);
void answ(double x1, double x2, KORNI kor);
