const int num = 1e9;
class Solution {
public:
   int strangePrinter(string h) {
      int x = h.size();
      if(x == 0) return 0;
      vector < vector <int> > ok(x, vector <int>(x, num));
      for(int m = 1; m <= x; m++){
      for(int i = 0, j = m - 1; j < x; i++, j++){
         if(m == 1){
            ok[i][j] = 1;
            }else if(m == 2){
               ok[i][j] = h[i] == h[j] ? 1 : 2;
            }else{
               for(int k = i; k < j; k++){
                  int temp = ok[i][k] + ok[k + 1][j];
                  ok[i][j] = min(ok[i][j], h[k] == h[j] ? temp - 1: temp);
               }
            }
         }
      }
      return ok[0][x - 1];
   }
};
