#include <stdlib.h>

#include "lib_kalman.h"

int main(void) {
  static KalmanTypeDef random = {0};

  Kalman_FilterInit(&random);
  for (;;) {
    Kalman_FilterUpdate(&random, rand() % 100);
  }
}
