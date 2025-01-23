const List<String> testCase1 = const [
  "Apple",
  "App",
  "Application",
];

const List<String> testCase2 = const ["flower", "flow", "flight"];

void main() {
  print(longestCommonPrefix(testCase2));
}

String longestCommonPrefix(List<String> strs) {
  //Check
  if (strs.isEmpty) return '';
  if (strs.length == 1) return strs[0];

  //Define longest word size
  int minWordSize = strs[0].length;

  for (int id = 1; id < strs.length; id++) {
    int currentIdLength = strs[id].length;
    if (currentIdLength < minWordSize) {
      minWordSize = currentIdLength;
    }
  }

  String result = '';
  bool breakLoop = false;

  //Outer loop, check letter
  for (int letterId = 0; letterId < minWordSize; letterId++) {
    String currentLetter = strs[0][letterId];
    //Inner loop, check each word
    for (int wordId = 1; wordId < strs.length; wordId++) {
      if (strs[wordId][letterId] != currentLetter) {
        breakLoop = true;
        break;
      }
    }

    if (breakLoop) break;

    result += currentLetter;
  }

  return result;
}
