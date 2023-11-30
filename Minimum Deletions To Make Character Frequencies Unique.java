class Solution {
    public int minDeletions(String s) {
        int[] freq = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a'] ++;
        }
        // 3 3 2
        Arrays.sort(freq);
        // System.out.println(Arrays.toString(freq));
        int res = 0;
        while (true) {
            boolean dup = false;
            for (int i = 0; i < freq.length - 1; i ++) {
                if (freq[i] == 0) continue;
                if (freq[i] == freq[i + 1]) {
                    dup = true;
                    res ++;
                    freq[i] --;
                    break;
                }
            }
            // System.out.println(Arrays.toString(freq));
            Arrays.sort(freq);
            if (!dup) break;
        }
        return res;
    }
}