#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double f(double x) { return exp(x) + sin(2.0 * x); }

int main(int argc, char *argv[]) {
  srand(time(0));

  double start = -4.0, finish = -3.0, e = 1e-6, mid = (finish + start) / 2.0;

  if (f(start) * f(finish) > 0) {
    printf("Could not find\n");
    exit(0);
  }

  while (fabs(f(mid)) >= e) {
    mid = (finish + start) / 2.0;
    if (f(mid) > 0) {
      start = (f(start) > f(finish)) ? mid : start;
      finish = (f(start) < f(finish)) ? mid : finish;
    } else {
      start = (f(start) < f(finish)) ? mid : start;
      finish = (f(start) > f(finish)) ? mid : finish;
    }
  }

  printf("Found: %lF\n", start);

  return 0;
}
