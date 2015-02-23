#include <stdio.h>
#include <stdlib.h>

#include <gmp.h>

void modexp(mpz_t rop,
            const mpz_t base, const mpz_t exp, const mpz_t mod,
            mp_bitcnt_t expbitlen)
{
  mp_bitcnt_t i;
  int b;

  mpz_set_ui(rop, 1);

  for (i = 0; i < expbitlen; i += 1) {
    mpz_mul(rop, rop, rop);
    mpz_mod(rop, rop, mod);

    if (mpz_tstbit(exp, expbitlen-i-1)) {
      mpz_mul(rop, rop, base);
      mpz_mod(rop, rop, mod);
    }
  }
}

int main(int argc, char **argv)
{
  mpz_t g, q, p;
  mpz_t x, y;
  mpz_t s;

  if (argc < 2) {
    exit(23);
  }

  mpz_init2(g, 128);
  mpz_init2(q, 32);
  mpz_init2(p, 128);
  mpz_init2(x, 32);
  mpz_init2(y, 128);
  mpz_init2(s, 256);

  mpz_set_str(g, "48802643297876824865825546560303609273", 10);
  mpz_set_str(q, "2525388007", 10);
  mpz_set_str(p, "146629964838044688397621290070212084109", 10);
  mpz_set_str(x, "541182456", 10);
  mpz_set_str(y, argv[1], 10);

  if ((mpz_cmp(y, p) >= 0) ||
      (mpz_cmp_ui(y, 0) <= 0)) {
    exit(42);
  }

  modexp(s, y, x, p, 32);

  return 0;
}
