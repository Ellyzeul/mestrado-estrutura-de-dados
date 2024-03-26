#ifndef __ELLYZ__DATA_STRUCTURES__STATIC_LIST__
#define __ELLYZ__DATA_STRUCTURES__STATIC_LIST__

typedef struct {
  void** list;
  unsigned int size;
  unsigned int allocated;
} StaticList;

StaticList* staticListAlloc(const unsigned long long byteSize, const unsigned int length);
unsigned int staticListInsert(StaticList* staticList, void* element);
void staticListInsertAt(StaticList* staticList, void* element, unsigned int index);
void staticListDelete(StaticList* staticList, unsigned int index);
void* staticListElementAt(const StaticList* staticList, unsigned int index);
unsigned int staticListSize(const StaticList* staticList);
long staticListFind(const StaticList* staticList, const void* element);
StaticList* staticListConcat(const StaticList* prepend, const StaticList* append);

#endif//__ELLYZ__DATA_STRUCTURES__STATIC_LIST__