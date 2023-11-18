template<class Type>
struct Node {
  Type info;
  Node<Type> *link;
};