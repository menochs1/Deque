/**
 * @file Deque.h
 * @author Mason Enochs
 * @date 2025-04-26
 * @brief definition of the deque class and its operations / variables
 * 
 * 
 */


/**
 * 
 *
 * @class Deque Deque.h "Deque/Deque.h"
 * @brief This class defines the operations and methods of the deque class
 *
 */
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

/**
 * expands the front of the deque
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void expandFront();

/**
 * expands the back of the deque
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void expandBack();
public:

/**
 * deque constructor
 *
 * @pre 
 * @post 
 * 
 */
  Deque();

/**
 * deque destructor
 *
 * @pre 
 * @post 
 * 
 */
  ~Deque();

/**
 * pushes a value to the front of the deque
 *
 * @param int value 
 * @pre 
 * @return void \
 * @post 
 * 
 */
  void pushFront(int value);

/**
 * pushes a value to the back of the deque
 *
 * @param int value 
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void pushBack(int value);

/**
 * removes front value from deque
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void popFront();

/**
 * removes back value from deque
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void popBack();

/**
 * returns the value at the front of the deque
 *
 * @pre 
 * @return int 
 * @post 
 * 
 */
  int getFront();

/**
 * returns the value at the back of the deque
 *
 * @pre 
 * @return int 
 * @post 
 * 
 */
  int getBack();

/**
 * checks if deque is empty
 *
 * @pre 
 * @return bool 
 * @post 
 * 
 */
  bool isEmpty();

/**
 * returns size of the deque
 *
 * @pre 
 * @return int 
 * @post 
 * 
 */
  int getSize();

/**
 * prints the contents of the deque
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void print();

/**
 * returns the value at [index] in the deque
 *
 * @param int index 
 * @pre 
 * @return const 
 * @post 
 * 
 */
  const int& operator[](int index);
};
