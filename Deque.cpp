/**
 * @file Deque.cpp
 * @author Mason Enochs
 * @date 2025-04-26
 * @brief Implementaiton of Deque class
 * 
 * 
 */
#include <iostream>
#include <iomanip>
#include "Deque.h"

using namespace std;


/**
 * constructor for initial values
 *
 * @pre 
 * @post 
 * 
 */
Deque::Deque()
{
  this->blockSize = 1000;          
  this->currentSize = 0;         
  this->blockCount = 2;        
  this->firstBlock = 0;        
  this->firstIndex = this->blockSize / 2;  
  this->lastBlock = 0;         
  this->lastIndex = this->blockSize / 2;  

  this->blockMap = new int*[this->blockCount];

  // initializes all 0 in deque
  for (int i = 0; i < this->blockCount; i++)
    {
      this->blockMap[i] = new int[this->blockSize];
      for(int j = 0; j < this->blockSize; j++)
        {
            this->blockMap[i][j] = 0;
        }
    }
}


/**
 * destructor to deallocate memory
 *
 * @pre 
 * @post 
 * 
 */
Deque::~Deque()
{
  for (int i = 0; i < blockCount; ++i)
    {
      delete[] blockMap[i];
    }
  delete[] blockMap;
}


/**
 * prints the contents of the deque
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
void Deque::print()
{
  if (isEmpty()) {
    cout << "Deque is empty!" << endl;
    return;
  }

  int count = 0;
  int block = firstBlock;
  int index = firstIndex;

  cout << "[ ";
  while (count < currentSize) {
    cout << blockMap[block][index] << " ";

    count++;
    index++;
    if (index == blockSize) {
      index = 0;
      block++;
    }
  }
  cout << "]" << endl;
}


/**
 * pushes a falue to the front of the deque
 *
 * @param int value 
 * @pre 
 * @return void 
 * @post 
 * 
 */
void Deque::pushFront(int value)
{
  // expands if more room is needed
  if (firstIndex == 0)
    {
      expandFront();
    }
  firstIndex--;
  blockMap[firstBlock][firstIndex] = value;
  currentSize++;
}


/**
 * pushes a value to the back of the deque
 *
 * @param int value 
 * @pre 
 * @return void 
 * @post 
 * 
 */
void Deque::pushBack(int value)
{
  //expands if more room is needed
  if (lastIndex == blockSize - 1)
    {
      expandBack();
    }
  lastIndex++;
  blockMap[lastBlock][lastIndex] = value;
  currentSize++;
}


/**
 * removes from the front
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
void Deque::popFront()
{
  if (isEmpty())
    {
      cout << "Deque is empty" << endl;
    }
  firstIndex++;
  currentSize--;
  // removes room if unused and not needed
  if (firstIndex == blockSize)
    {
      delete[] blockMap[firstBlock];
      firstBlock++;
      firstIndex = 0;
    }
}


/**
 * removes from the back
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
void Deque::popBack()
{
  if (isEmpty())
    {
      cout << "Deque is empty" << endl;
    }
  lastIndex--;
  currentSize--;
  // removes room if unsued and not neede
  if (lastIndex == -1)
    {
      delete[] blockMap[lastBlock];
      lastBlock--;
      lastIndex = blockSize - 1;
    }
}


/**
 * returns the value at the front
 *
 * @pre 
 * @return int 
 * @post 
 * 
 */
int Deque::getFront()
{
  if (isEmpty())
    {
      cout << "Deque is empty" << endl;
    }
  return blockMap[firstBlock][firstIndex];
}


/**
 * returns the value at the back
 *
 * @pre 
 * @return int 
 * @post 
 * 
 */
int Deque::getBack()
{
  if (isEmpty())
    {
      cout << "Deque is empty" << endl;
    }
  return blockMap[lastBlock][lastIndex];
}


/**
 * checks if the deque is empty
 *
 * @pre 
 * @return bool 
 * @post 
 * 
 */
bool Deque::isEmpty()
{
  if(currentSize == 0)
    {
      return true;
    }
  return false;
}


/**
 * retrieves the size of the deque
 *
 * @pre 
 * @return int 
 * @post 
 * 
 */
int Deque::getSize()
{
  return currentSize;
}


/**
 * returns the value at [index] in the deque
 *
 * @param int index 
 * @pre 
 * @return const 
 * @post 
 * 
 */
const int& Deque::operator[](int index)
{
  if (isEmpty() || index < 0 || index >= currentSize)
    {
      cout << "Index out of range error" << endl;
      return NULL;
    }

  int blockOffset = firstIndex + index;
  int targetBlock = firstBlock + blockOffset / blockSize;
  int targetIndex = blockOffset % blockSize;

  return blockMap[targetBlock][targetIndex];
}


/**
 * expands the front of the deque
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
void Deque::expandFront()
{
  if (firstBlock == 0)
    {
      int newBlockCount = blockCount * 2;
      int** newBlockMap = new int*[newBlockCount];
      
      int offset = (newBlockCount - blockCount) / 2;
      for (int i = 0; i < blockCount; i++)
	{
	  newBlockMap[offset + i] = blockMap[i];
	}
      
      for (int i = 0; i < offset; i++)
	{
	  newBlockMap[i] = new int[blockSize];
	}

      for (int i = offset + blockCount; i < newBlockCount; i++)
	{
	  newBlockMap[i] = new int[blockSize];
	}

      delete[] blockMap;
      blockMap = newBlockMap;
      firstBlock += offset;
      lastBlock += offset;
      blockCount = newBlockCount;
    }
}


/**
 * expands the back of the deque
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
void Deque::expandBack()
{
  if (lastBlock == blockCount - 1)
    {
      int newBlockCount = blockCount * 2;
      int** newBlockMap = new int*[newBlockCount];
      
      for (int i = 0; i < blockCount; i++)
	{
	  newBlockMap[i] = blockMap[i];
	}
      
      for (int i = blockCount; i < newBlockCount; i++)
	{
	  newBlockMap[i] = new int[blockSize];
	}
      
      delete[] blockMap;
      blockMap = newBlockMap;
      blockCount = newBlockCount;
    }
  
  lastBlock++;
  lastIndex = -1;
}

