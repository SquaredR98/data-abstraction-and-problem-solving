template <class Type>
class ArrayADT
{
public:
  const ArrayADT<Type> &operator=(const ArrayADT<Type> &);
  int size() const;
  int capacity() const;
  int search(const Type &item) const;

  bool empty() const;
  bool full() const;
  bool isItemAtEqual(int location, const Type &item);

  void print() const;
  void addAt(int location, const Type &item);
  void push(const Type &item);
  void removeFrom(int location);
  void getElementAt(int location, Type &retItem);
  void replaceAt(int location, Type &retItem);
  void clear();
  void addNoDuplicates(const Type &item);
  void removeItem(const Type &item);

  ArrayADT(int size = 100);
  ArrayADT(const ArrayADT<Type> &otherList);
  ~ArrayADT();

private:
  Type *list;
  int length;
  int maxSize;
};

template <class Type>
bool ArrayADT<Type>::empty() const
{
  return length == 0;
}

template <class Type>
bool ArrayADT<Type>::full() const
{
  return length == maxSize;
}

template <class Type>
int ArrayADT<Type>::size() const
{
  return length;
}

template <class Type>
int ArrayADT<Type>::capacity() const
{
  return maxSize;
}

template <class Type>
void ArrayADT<Type>::print() const
{
  for (int i = 0; i < length; i++)
  {
    cout << list[i] << " ";
  }
  cout << endl;
}

template <class Type>
inline bool ArrayADT<Type>::isItemAtEqual(int location, const Type &item)
{
  return false;
}

template <class Type>
inline void ArrayADT<Type>::addAt(int location, const Type &item)
{
  if (location < 0 || location >= maxSize)
  {
    cerr << "OutofBoundException: Array index inaccessible";
  }
  else if (length >= maxSize)
  {
    cerr << "ListFullException: List capacity is full";
  }
  else
  {

    for (int i = length; i > location; i--)
    {
      list[i] = list[i - 1];
    }
    list[location] = item;
    length++;
  }
}

template <class Type>
inline void ArrayADT<Type>::push(const Type &item)
{
  if (length >= maxSize)
  {
    cerr << "ListFullException: List capacity is full";
  }
  else
  {

    list[length] = item;
    length++;
  }
}

template <class Type>
inline void ArrayADT<Type>::removeFrom(int location)
{
  if (location < 0 || location >= length)
  {
    cerr << "OutOfBoundException: Array index inaccessible";
  }
  else
  {
    for (int i = location; i < length - 1; i++)
    {
      list[i] = list[i + 1];
    }
    length--;
  }
}

template <class Type>
inline void ArrayADT<Type>::getElementAt(int location, Type &retItem)
{
  if (location < 0 || location >= length)
  {
    cerr << "OutOfBoundException: Array index inaccessible";
  }
  else
  {
    retItem = list[location];
  }
}

template <class Type>
inline void ArrayADT<Type>::replaceAt(int location, Type &item)
{
  if (location < 0 || location >= length)
  {
    cerr << "OutOfBoundException: Array index inaccessible";
  }
  else
  {
    list[location] = item;
  }
}

template <class Type>
inline void ArrayADT<Type>::clear()
{
  length = 0;
}

template <class Type>
inline int ArrayADT<Type>::search(const Type &item) const
{
  int location;
  for (location = 0; location < length; location++)
  {
    if (list[location] == item)
      return location;
  }

  return -1;
}

template <class Type>
inline void ArrayADT<Type>::addNoDuplicates(const Type &item)
{
  int loc;
  if (length == 0)
  {
    int location = length++;
    list[location] = item;
  }
  else if (length == maxSize)
  {
    cerr << "ListFullException: List capacity is full";
  }
  else
  {
    loc = search(item);
    if (loc == -1)
    {
      int location = length++;
      list[location] = item;
    }
    else
    {
      cerr << "ItemExistException: Can't add it.";
    }
  }
}

template <class Type>
inline void ArrayADT<Type>::removeItem(const Type &item)
{
  int loc;

  if (length == 0)
  {
    cerr << "EmptyListException: Can't remove from an empty list.";
  }
  else
  {
    loc = search(item);
    if (loc != -1)
    {
      removeFrom(loc);
    }
    else
    {
      cout << "ItemNotExistException: Item to be deleted do not exist in the list.";
    }
  }
}

template <class Type>
inline ArrayADT<Type>::ArrayADT(int size)
{
  if (size < 0)
  {
    cerr << "NegativeArraySizeException: Array size must be positive so creating a default array size of 100";
    maxSize = 100;
  }
  else
  {
    maxSize = size;
  }
  length = 0;
  list = new Type[maxSize];
  assert(list != NULL);
}

template <class Type>
inline ArrayADT<Type>::ArrayADT(const ArrayADT<Type> &otherList)
{
  maxSize = otherList.maxSize;
  length = otherList.length;
  list = new Type[maxSize];
  assert(list != NULL);

  for (int i = 0; i < length; i++)
  {
    list[i] = otherList.list[i];
  }
}

template <class Type>
inline ArrayADT<Type>::~ArrayADT()
{
  delete[] list;
}
