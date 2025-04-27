class Deque {
private:
  int** blockMap;
  int blockSize;      
  int currentSize;      
  int blockCount;     
  int firstBlock;     
  int firstIndex;     
  int lastBlock;      
  int lastIndex;      
  void expandFront();
  void expandBack();
public:
  Deque();
  ~Deque();
  void pushFront(int value);
  void pushBack(int value);
  void popFront();
  void popBack();
  int getFront();
  int getBack();
  bool isEmpty();
  int getSize();
  const int& operator[](int index);
};
