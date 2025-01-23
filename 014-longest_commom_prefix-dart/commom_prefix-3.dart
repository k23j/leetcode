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
  if (strs.isEmpty) return '';
  if (strs.length == 1) return strs[0];

  String minString = getMinString(strs);

  //Outerloop
  for (int count = 0; count < minString.length; count++) {
    //Innerloop
    for (String string in strs) {
      if (string[count] != minString[count])
        return minString.substring(0, count);
    }
  }

  return minString;
}

String getMinString(List<String> strs) {
  int minStringId = 0;

  //For each word
  for (int id = 1; id < strs.length; id++) {
    if (strs[id].length < strs[minStringId].length) {
      minStringId = id;
    }
  }

  return strs[minStringId];
}
