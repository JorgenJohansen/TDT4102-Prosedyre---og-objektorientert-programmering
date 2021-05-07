#include "LinkedList.h"
namespace LinkedList{
Node* LinkedList::insert(Node* pos, const std::string& value){
    if(pos == begin()){
        head = std::make_unique<Node>(value, std::move(head), nullptr);
        pos->prev = begin();
    
    }else{
        auto pos2 = pos->prev;
        //Black magic
        pos2->next = std::make_unique<Node>(value, std::move(pos2->next), pos2);
        pos->prev = pos2->getNext();
    }
    

   return pos->prev;
}
//The remove function takes a pointer to a node, 
//and removes the node from the list. 
//The function returns a pointer to the element 
//after the removed node.
Node* LinkedList::remove(Node* pos){
    
    if(pos == begin()){
        head = std::move(pos->next);
        head->prev = nullptr;
        return head.get();
    }else{
        pos->next->prev = pos->getPrev();
        pos->prev->next = std::move(pos->next);
        return pos->prev->getNext();
    }

}
//Done
Node* LinkedList::find(const std::string& value){
    auto temp = begin();
    while(temp != end() && temp->value != value){
        temp = temp->getNext();
    }
    return temp;
}

void LinkedList::remove(const std::string& value){
    auto delNode = find(value);
    remove(delNode);
}

std::ostream& operator<<(std::ostream& os, const Node& node){
    os << node.getValue();
    return os;
}

std::ostream& operator<<(std::ostream& os, const LinkedList& list){
    auto temp = list.begin();
    while(temp != nullptr){
        os << temp->getValue() << "->";
        temp = temp->getNext();
    }
    return os;
}
}


