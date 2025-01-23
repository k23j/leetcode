const List<String> testCase1 = const [
  "Apple",
  "App",
  "Application",
];

const List<String> testCase2 = const ["flower", "flow", "flight"];

const List<String> testCase3 = const ["a", "b"];

void main() {
  print(longestCommonPrefix(testCase3));
}

String longestCommonPrefix(List<String> strs) {
  if (strs.isEmpty) return "";
  if (strs.length == 1) return strs[0];

  int minWordSize = minWordLength(strs);

  //Outer check letter
  for (int letterId = 0; letterId < minWordSize; letterId++) {
    //Inner check word
    for (String word in strs) {
      if (word[letterId] != strs[0][letterId]) {
        return strs[0].substring(0, letterId);
      }
    }
  }

  return strs[0].substring(0, minWordSize);
}

int minWordLength(List<String> strs) {
  int minWord = strs[0].length;

  for (int id = 1; id < strs.length; id++) {
    int currentLength = strs[id].length;
    if (currentLength < minWord) minWord = currentLength;
  }

  return minWord;
}
