#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

#define LOOP 10000000

unsigned char code[] = {0xb8, 0x00, 0x00, 0x00, 0x00, 0xc3};

int main(void) {
  int i = 0;
  void* mem = mmap(NULL, sizeof(code), PROT_WRITE | PROT_EXEC, MAP_ANON | MAP_PRIVATE, -1, 0);
  memcpy(mem, code, sizeof(code));

  int (*func)() = mem;

  for (i=0; i<LOOP; i++) {
    func();
  }

  return 0;
}
