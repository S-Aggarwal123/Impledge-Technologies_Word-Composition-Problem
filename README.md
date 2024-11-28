# Impledge-Technologies_Word-Composition-Problem

1. iscompound function : 1. Splits the whole word present in the line in two words prefix and suffix using substr function.
                         2. And then check that if it is present in the set which store all the unique words or if suffix can be compounded with another word.
   
2. Main Loop : 1. Then the words are stored in the set so that we can get the fast lookup which will increase its performance.
               2. Remove the current word from the set so that it is not considered for that word we are checking to be compounded but temporarily remove that.
               3. Now you can track the longest and second largest compunded word.

3. Simple Logic : As, it does not use any type of the recursion and the dynamic programming that requires the extra space.
