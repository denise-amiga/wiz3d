#include "file_system.h"
#include "memblock.h"
#include <string.h>

EXPORT Memblock* CALL CreateMemblock(int size) {
  char* memblock = (char*)calloc(1, size + 4);
  ((int*)memblock)[0] = (int)size;
  return (Memblock*)((int*)memblock+1);
}

EXPORT Memblock* CALL LoadMemblock(const char* filename) {
  size_t size;
  Memblock* memblock = NULL;

  size = GetFileSize(filename);
  if (size > 0) {
    memblock = CreateMemblock(size);
    _GetFileContents(filename, memblock);
  }

  return memblock;
}

EXPORT void CALL DeleteMemblock(Memblock* memblock) {
  free((int*)memblock-1);
}

EXPORT int CALL GetMemblockSize(const Memblock* memblock) {
  return ((const int*)memblock-1)[0];
}

EXPORT unsigned char CALL GetMemblockByte(const Memblock* memblock, int offset) {
  unsigned char val;
  memcpy(&val, (const char*)memblock+offset, sizeof(val));
  return val;
}

EXPORT unsigned short CALL GetMemblockShort(const Memblock* memblock, int offset) {
  unsigned short val;
  memcpy(&val, (const char*)memblock+offset, sizeof(val));
  return val;
}

EXPORT int CALL GetMemblockInt(const Memblock* memblock, int offset) {
  int val;
  memcpy(&val, (const char*)memblock+offset, sizeof(val));
  return val;
}

EXPORT float CALL GetMemblockFloat(const Memblock* memblock, int offset) {
  float val;
  memcpy(&val, (const char*)memblock+offset, sizeof(val));
  return val;
}

EXPORT double CALL GetMemblockDouble(const Memblock* memblock, int offset) {
  double val;
  memcpy(&val, (const char*)memblock+offset, sizeof(val));
  return val;
}

EXPORT void CALL SetMemblockByte(Memblock* memblock, int offset, unsigned char val) {
  memcpy((char*)memblock+offset, &val, sizeof(val));
}

EXPORT void CALL SetMemblockShort(Memblock* memblock, int offset, unsigned short val) {
  memcpy((char*)memblock+offset, &val, sizeof(val));
}

EXPORT void CALL SetMemblockInt(Memblock* memblock, int offset, int val) {
  memcpy((char*)memblock+offset, &val, sizeof(val));
}

EXPORT void CALL SetMemblockFloat(Memblock* memblock, int offset, float val) {
  memcpy((char*)memblock+offset, &val, sizeof(val));
}

EXPORT void CALL SetMemblockDouble(Memblock* memblock, int offset, double val) {
  memcpy((char*)memblock+offset, &val, sizeof(val));
}
