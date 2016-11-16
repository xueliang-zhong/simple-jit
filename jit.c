#include <stdlib.h>
#include <sys/mman.h>

#define LOOP 10000000

#define X86_64 1

#ifdef X86_64
unsigned char code[] = {0xb8, 0x00, 0x00, 0x00, 0x00, 0xc3};
#endif

void code_copy(unsigned char* to, unsigned char* from, size_t size) {
  while(size--) {
    *to++ = *from++;
  }
}

int main(void) {
  int i = 0;
  void* mem = mmap(NULL, sizeof(code), PROT_WRITE | PROT_EXEC, MAP_ANON | MAP_PRIVATE, -1, 0);
  code_copy(mem, code, sizeof(code));

  int (*func)() = mem;

  for (i=0; i<LOOP; i++) {
    func();
  }

  return 0;
}
