#include "Node.h"

template <class Type>
class LLIterator {
  public:
    LLIterator();
    LLIterator(Node<Type> *ptr);
    Type operator*();
    LLIterator<Type> operator++();
    bool operator==(const LLIterator<Type> &right) const;
    bool operator!=(const LLIterator<Type> &right) const;
  private:
    Node<Type> *current;
};

template <class Type>
LLIterator<Type>::LLIterator() {
  current = NULL;
}

template <class Type>
LLIterator<Type>::LLIterator(Node<Type> *ptr) {
  current = ptr;
}

template <class Type>
Type LLIterator<Type>::operator*() {
  return current->info;
}

template <class Type>
LLIterator<Type> LLIterator<Type>::operator++() {
  current = current -> next;
  return *this;
}

template<class Type>
bool LLIterator<Type>::operator==(const LLIterator<Type> &right) const {
  return current == right.current;
}

template <class Type>
bool LLIterator<Type>::operator!=(const LLIterator<Type> &right) const {
  return current != right.current;
}