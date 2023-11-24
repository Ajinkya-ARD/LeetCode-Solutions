class Solution {
    public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {
    for(int i = 0; i < group.length; i++)
        if(group[i] == -1)
            group[i] = m++; // assign none-group elements a group

    int[] inG = new int[m]; // indegree of groups
    int[] inI = new int[n]; // indegree of items
    ArrayList<Integer>[] graphI = new ArrayList[n]; // graph of groups: before group -> after groups
    ArrayList<Integer>[] graphG = new ArrayList[m]; // graph of items: before item -> after items
    ArrayList<Integer>[] g2i = new ArrayList[m]; // group index -> item indexes
    for(int i = 0; i < m; i++) g2i[i] = new ArrayList<>();
    for(int i = 0; i < n; i++) graphI[i] = new ArrayList<>();
    for(int i = 0; i < m; i++) graphG[i] = new ArrayList<>();

    for(int i = 0; i < group.length; i++) g2i[group[i]].add(i);
    for(int i = 0; i < beforeItems.size(); i++) {
        List<Integer> l = beforeItems.get(i);
        for(int b : l) {
            if(group[i] != group[b]) { // order between differnt groups
                graphG[group[b]].add(group[i]);
                inG[group[i]]++;
            } else { // order between items within a group
                inI[i]++;
                graphI[b].add(i);
            }
        }
    }
    // Level1: the code below is a topological sort on the groups
    PriorityQueue<Integer> q = new PriorityQueue<>();
    for(int i = 0; i < m; i++) {
        if(inG[i] == 0) q.offer(i);
    }
    ArrayList<ArrayList<Integer>> orderG = new ArrayList<>();
    while(!q.isEmpty()) {
        int b = q.poll(); // current group with indgree equals 0


        // Level 2: the code below is a topological sort on items within a group
        ArrayList<Integer> temp = new ArrayList<>();
        PriorityQueue<Integer> iq = new PriorityQueue<>();
        for(int i : g2i[b]) {
            if(inI[i] == 0) iq.offer(i);
        }
        while(!iq.isEmpty()) {
            int ib = iq.poll();
            temp.add(ib);
            for(int ia : graphI[ib]) {
                inI[ia]--;
                if(inI[ia] == 0) {
                    iq.offer(ia);
                }
            }
        }
        if(temp.size() != g2i[b].size()) return new int[]{}; // invalid result
        orderG.add(temp); // add the sorted group items into result
        // END inner sort


        for(int after : graphG[b]) { // add new groups with indgree equals 0 into the queue
            inG[after]--;
            if(inG[after] == 0) {
                q.offer(after);
            }
        }
    }
    if(orderG.size() != m) return new int[] {};
    // END outer sort

    int[] result = new int[n];
    int cnt = 0;
    for(ArrayList<Integer> l : orderG) {
        for(int i : l) result[cnt++] = i;
    }
    return result;
}
}