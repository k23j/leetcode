# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []

class Solution {
private:
  //This function returns a pair with the first guess, and the result (greater, lesser, or 0 for right guess)
  // 0  => right guess
  //-2  => current guess is lesser than result
  //-1  => current guess is greater than result
  pair<int,int> getFirstGuess(const int& x) {
    //If lesser than 100 start at 2 growing
    if (x <= 100) return {2, -2};

    long long firstGuess = x / 10 + 1;
    long long result = firstGuess * firstGuess;

    while (result > x) {
      firstGuess /= 2;
      result = firstGuess * firstGuess;
    }

    double difference = static_cast<double>(result) / x;
    int stepSize = firstGuess/10 + 1;

    while (difference < .75 ) {
      firstGuess += stepSize;
      result = firstGuess * firstGuess;
      difference = static_cast<double>(result) / x;
    }

    //If first guess is the result
    if (result == x) return {firstGuess, 0};

    //If first guess is greater
    return {firstGuess, result < x ? -2 : -1};
  }

  // 0  => right guess
  //-2  => current guess is lesser than result
  //-1  => current guess is greater than result
  int tryGuess(int target, int guess, int lastGuessResult) {
    long long result = static_cast<long long>(guess) * guess;
    int currentGuessResult;

    if (result == target) return guess;

    currentGuessResult = (result < target) ? -2 : -1;

    //On switch guess direction
    if (lastGuessResult != currentGuessResult) {
      return (currentGuessResult < lastGuessResult) ? guess : guess - 1;
    }

    return tryGuess(target, guess + 1, currentGuessResult);
  }

public:
  int mySqrt(int x) {
    if (x <= 1) return x;

    pair<int,int> firstGuess = getFirstGuess(x);
    
    //Target, FirstGuess, Direction (-2 growing, -1 reducing)
    return tryGuess(x, firstGuess.first, firstGuess.second);
  }
};

```