#include <iostream>

int getCharIndex(char c) {
  int idx = -1;
  if (c >= 'a' && c <= 'z') {
    idx = c - 'a';
  } else if (c >= 'A' && c <= 'Z') {
    idx = c - 'A';
  }
  return idx;
}

void countFrequency(const std::string &str, int *frequency) {
  int idx;
  for (const char &c : str) {
    idx = getCharIndex(c);
    if (idx != -1) {
      ++frequency[idx];
    }
  }
}

bool isPermutationOfPallindrome1(const std::string &str) {
  int frequency[26] = {0};
  countFrequency(str, frequency);

  bool oddAppeared = false;
  std::cout << std::endl;
  for (int i = 0; i < 26; ++i) {
    if (frequency[i] % 2 && oddAppeared) {
      return false;
    } else if (frequency[i] % 2 && !oddAppeared) {
      oddAppeared = true;
    }
  }
  return true;
}

bool isPermutationOfPallindrome2(const std::string &str) {
  int oddCount = 0;
  int frequency[26] = {0};
  int idx = 0;
  for (const char &c : str) {
    idx = getCharIndex(c);
    if (idx != -1) {
      ++frequency[idx];
      if (frequency[idx] % 2) {
        ++oddCount;
      } else {
        --oddCount;
      }
    }
  }
  return (oddCount <= 1);
}

int toggle(int bitVector, int index) {
  if (index < 0)
    return bitVector;

  int mask = 1 << index;
  // if bit is not set
  if ((bitVector & mask) == 0) {
    bitVector |= mask;
  } else { // if bit is set
    bitVector &= ~mask;
  }
  return bitVector;
}

bool isExactlyOneBitSet(int bitVector) {
  return ((bitVector & (bitVector - 1)) == 0);
}

bool isPermutationOfPallindrome3(const std::string &str) {
  int bitVector = 0;
  int id = 0;
  for (const char &c : str) {
    id = getCharIndex(c);
    bitVector = toggle(bitVector, id);
  }
  return (bitVector == 0 || isExactlyOneBitSet(bitVector));
}

int main() {
  std::string str("Tact Coa");
  std::cout << "Does \"" << str
            << "\"  has a string whose permutation is a pallindrome? "
            << "( 1 for true, 0 for false ) : ";
  std::cout << "Approach 1:" << isPermutationOfPallindrome1(str) << std::endl;
  std::cout << "Approach 2:" << isPermutationOfPallindrome2(str) << std::endl;
  std::cout << "Approach 3:" << isPermutationOfPallindrome3(str) << std::endl;

  std::string str1("A big Cat");
  std::cout << "Does \"" << str1
            << "\" has a string whose permutation is a pallindrome? "
            << "( 1 for true, 0 for false ) : ";
  std::cout << "Approach 1:" << isPermutationOfPallindrome1(str1) << std::endl;
  std::cout << "Approach 2:" << isPermutationOfPallindrome2(str1) << std::endl;
  std::cout << "Approach 3:" << isPermutationOfPallindrome3(str1) << std::endl;

  std::string str2("Aba cbc");
  std::cout << "Does \"" << str2
            << "\" has a string whose permutation is a pallindrome? "
            << "( 1 for true, 0 for false ) : ";
  std::cout << "Approach 1:" << isPermutationOfPallindrome1(str2) << std::endl;
  std::cout << "Approach 2:" << isPermutationOfPallindrome2(str2) << std::endl;
  std::cout << "Approach 3:" << isPermutationOfPallindrome3(str2) << std::endl;
  return 0;
}