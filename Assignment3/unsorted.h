
#ifndef unsorted_h
#define unsorted_h

#include "ItemType.h"

struct NodeType;

class UnsortedType {
public:
    UnsortedType();
    ~UnsortedType();
    void MakeEmpty();
    bool IsFull() const;
    int GetLength() const;
    ItemType GetItem(ItemType& item, bool& found);
    void PutItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    ItemType GetNextItem();
    
private:
    NodeType* listData;
    NodeType* currentPos;
    int length;
    
};

#endif /* unsorted_h */
