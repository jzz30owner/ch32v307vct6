#include "ethernet.h"


void enable_emac() {
  RCC_APB2EN |= (1 << 14);  
}
