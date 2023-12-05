class Solution {
    public String reverseWords(String s) {
        int i = 0, j = 0;
        int n = s.length();
        char[] chs = s.toCharArray();
        while (i < n && j < n) {
            while (i < n && chs[i] == ' ') {
                i++;
            }
            j = i;
            while (j < n && chs[j] != ' ') {
                j++;
            }
            reverse(chs, i, j - 1);
            i = j;
        }
        return new String(chs);
    }

    private void reverse(char[] chs, int s, int t) {
        while (s < t) {
            char tmp = chs[s];
            chs[s] = chs[t];
            chs[t] = tmp;
            s++;
            t--;
        }
    }
}