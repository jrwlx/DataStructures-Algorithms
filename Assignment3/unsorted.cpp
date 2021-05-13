
#include "unsorted.h"
struct NodeType {
    ItemType info;
    NodeType* next;
};

UnsortedType::UnsortedType() {
    length = 0;
    listData = NULL;
}

UnsortedType::~UnsortedType() {
    NodeType* tempPtr;
    
    while (listData != NULL) {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}

void UnsortedType::MakeEmpty() {
    NodeType* tempPtr;
    
    while (listData != NULL) {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

bool UnsortedType::IsFull() const {
    NodeType *location;
    try {
        location = new NodeType;
        delete location;
        return false;
    } catch (std::bad_alloc exception) {
        return true;
    }
}

int UnsortedType::GetLength() const {
    return length;
}

ItemType UnsortedType::GetItem(ItemType& item, bool& found) {
    bool moreToSearch;
    NodeType* location;
    
    location = listData;
    found = false;
    moreToSearch = (location != NULL);
    
    while (moreToSearch && !found) {
        switch (item.ComparedTo(location->info)) {
            case LESS:
            case GREATER: location = location->next;
                moreToSearch = (location != NULL);
                break;
            case EQUAL: found = true;
                item = location->info;
                break;
                
        }
    }
    return item;
}

void UnsortedType::PutItem(ItemType item) {
    NodeType *location = new NodeType; //creates a new node
    location->info = item; //stores item in node
    location->next = listData; //first node's address in new node's next
    listData = location;
    length++;
}

void UnsortedType::DeleteItem(ItemType item) {
    NodeType *tempPtr, *predLoc, *location;
    bool found = false;
    
    location = listData;
    predLoc = NULL;
    length--;
    
    while (!found) {
        switch (item.ComparedTo(location->info)) {
            case GREATER:
            case LESS: predLoc = location;
                location = location->next;
                break;
            case EQUAL: found = true;
                break;
        }
    }
    
    tempPtr = location;
    if (predLoc == NULL)
        location = location->next;
    else
        predLoc->next = location->next;
    
    delete tempPtr;
}

void UnsortedType::ResetList() {
    currentPos = NULL;
}

ItemType UnsortedType::GetNextItem() {
    if (currentPos == NULL) {
        currentPos = listData;
    }
    else {
        currentPos = currentPos->next;
    }
    
    return currentPos->info;
}




