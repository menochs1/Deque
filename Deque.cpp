#include <iomanip>
#include "Deque.h"

Deque::Deque()
{
  this->blockSize = 16;          
  this->currentSize = 0;         
  this->blockCount = 2;        
  this->firstBlock = 0;        
  this->firstIndex = this->blockSize / 2;  
  this->lastBlock = 0;         
  this->lastIndex = (this->blockSize / 2) - 1;  

  this->blockMap = new int*[this->blockCount];

  for (int i = 0; i < this->blockCount; ++i)
    {
      this->blockMap[i] = new int[this->blockSize];
    }
}

Deque::~Deque()
{
  for (int i = 0; i < blockCount; ++i)
    {
      delete[] blockMap[i];
    }
  delete[] blockMap;
}

void Deque::pushFront(int &value)
{
  if (firstIndex == 0)
    {
      expandFront();
    }
  firstIndex--;
  blockMap[firstBlock][firstIndex] = value;
  currentSize++;
}

void Deque::pushBack(int &value)
{
  if (lastIndex == blockSize - 1)
    {
      expandBack();
    }
  lastIndex++;
  blockMap[lastBlock][lastIndex] = value;
  currentSize++;
}

void Deque::popFront()
{
  if (isEmpty())
    {
      cout << "Deque is empty" << endl;
    }
  firstIndex++;
  currentSize--;
  if (firstIndex == blockSize)
    {
      delete[] blockMap[firstBlock];
      firstBlock++;
      firstIndex = 0;
    }
}

void Deque::popBack()
{
  if (isEmpty())
    {
      cout << "Deque is empty" << endl;
    }
  lastIndex--;
  currentSize--;
  if (lastIndex == -1)
    {
      delete[] blockMap[lastBlock];
      lastBlock--;
      lastIndex = blockSize - 1;
    }
}

int Deque::getFront()
{
  if (isEmpty())
    {
      cout << "Deque is empty" << endl;
    }
  return blockMap[firstBlock][firstIndex];
}

int Deque::getBack()
{
  if (isEmpty())
    {
      cout << "Deque is empty" << endl;
    }
  return blockMap[lastBlock][lastIndex];
}

bool Deque::isEmpty()
{
  if(currentSize == 0)
    {
      return true;
    }
  return false;
}

int Deque::getSize()
{
  return currentSize;
}

int& Deque::operator[](int index)
{
  if (index < 0 || index >= currentSize)
    {
      cout << "Index out of range error" << endl;
    }

  int blockOffset = firstIndex + index;
  int targetBlock = firstBlock + blockOffset / blockSize;
  int targetIndex = blockOffset % blockSize;

  return blockMap[targetBlock][targetIndex];
}

void Deque::expandFront()
{
  if (firstBlock == 0)
    {
      int newBlockCount = blockCount * 2;
      int** newBlockMap = new int*[newBlockCount];
      
      int offset = (newBlockCount - blockCount) / 2;
      for (int i = 0; i < blockCount; ++i)
	{
	  newBlockMap[offset + i] = blockMap[i];
	}
      
      for (int i = 0; i < offset; ++i)
	{
	  newBlockMap[i] = new int[blockSize];
	}

      for (int i = offset + blockCount; i < newBlockCount; ++i)
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

void Deque::expandBack()
{
  if (lastBlock == blockCount - 1)
    {
      int newBlockCount = blockCount * 2;
      int** newBlockMap = new int*[newBlockCount];
      
      for (int i = 0; i < blockCount; ++i)
	{
	  newBlockMap[i] = blockMap[i];
	}
      
      for (int i = blockCount; i < newBlockCount; ++i)
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

