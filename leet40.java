class Solution {
  
    public boolean isCircularSentence(String sentence) {
      
        if (sentence.charAt(0) != sentence.charAt(sentence.length() - 1))
            return false;

        // Find the first space in the string
        int k = sentence.indexOf(" ");
        if (k == -1)
            return true;

        // Iterate through all spaces in the string
        while (k != -1) {
            if (sentence.charAt(k - 1) != sentence.charAt(k + 1)) {
                return false;
            }

            // Find the next space in the string, starting from position after current space
            k = sentence.indexOf(" ", k+1);
        }
        
        // If we've made it through all checks, the sentence is circular
        return true;
    }
}
