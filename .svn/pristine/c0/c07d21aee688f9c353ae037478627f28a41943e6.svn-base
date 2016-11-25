#include <iostream>
#include <string>

using namespace std;

int
main() {
  string word, compWord, preWord;
  int wLen;
  while ((cin >> word) ) {
    while (word.find("\\") && word.empty()) {
      wLen = word.length() -1;
      preWord = word.substr(0, wLen);
      compWord.append(word);
      cin >> word;
    }
    if (!word.find("\\")) {
      cout << word << endl;
    }
    cout << compWord << endl;
  }
  
  return 0;
}
