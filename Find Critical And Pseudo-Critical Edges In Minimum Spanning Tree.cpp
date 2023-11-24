class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // Mark edges id
        for(int i = 0; i < edges.size(); i++){
            edges[i].push_back(i);
        }
        // Sort for kruscal algorithm
        sort(edges.begin(), edges.end(), 
            [](const vector<int> & a, const vector<int> & b) -> bool{ 
            return a[2] < b[2]; 
        });
        
        int w = _mst(n, edges, -1, -1);
        unordered_set<int> crit;
        unordered_set<int> ncrit;
        
        // Find critical
        // Disable i edge and see if mst value become larger or mst broken(-1)
        for(int i = 0; i < edges.size(); i++){
            int wr = _mst(n, edges, i, -1);
            if(wr > w || wr == -1){
                crit.insert(edges[i][3]);
            }
        };
