#ifndef __ELLYZ__DATA_STRUCTURES__STATIC_LIST__
#define __ELLYZ__DATA_STRUCTURES__STATIC_LIST__

typedef struct {
  void** list;
  unsigned int size;
  unsigned int allocated;
} StaticList;

StaticList* staticListAlloc(const unsigned long long byteSize, const unsigned int length);
unsigned int staticListInsert(StaticList* staticList, void* element);
long staticListFind(const StaticList* staticList, const void* element);

#endif//__ELLYZ__DATA_STRUCTURES__STATIC_LIST__