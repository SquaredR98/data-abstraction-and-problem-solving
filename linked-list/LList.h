#include "LLIterator.h"

template <class Type>
class LList
{
public:
  // Overload the assignment operator
  const LList<Type> &operator=(const LList<Type> &);

  // Initializes list to empty state
  void initializeLise();

  // Check if list is empty
  bool isListEmpty() const;

  // Print the elements of the list
  void print() const;

  // Returns the length of the list
  int length() const;

  // Destroys the list
  void destroyList();

  // Returns the first element of the list
  Type front() const;

  // Returns the last element of the list
  Type back() const;

  // Function to find an element in the list
  virtual bool search(const Type &item) const = 0;

  // Function to insert the element at the first position in the list
  virtual void insertFirst(const Type &item) const = 0;

  // Function to insert at the end of the list
  virtual void insertLast(const Type &item) const = 0;

  // Function to delete containing item
  virtual void deleteNode(const Type &item) const = 0;

  // An iterator to return the begining of the iterator
  LLIterator<Type> begin();

  // An iterator to return the end of the list iterator
  LLIterator<Type> end();

  // Default Constructor
  LList();

  // Copy Constructor
  LList(const LList<Type> &otherList);

  // Destructor
  ~LList();

protected:
  int count; // Keeps track of the number of elements in the list
  Node<Type> *first, *last;

private:
  void copyList(const LList<Type> &otherList);
};

template<class Type>
bool LList<Type>::isListEmpty() const {
  return first == NULL;
}