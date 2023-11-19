class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {

        //corner case
        if(matrix == null || matrix.length == 0) return false;
        if(matrix[0] == null || matrix[0].length == 0) return false;

        int r = matrix.length;
        int c = matrix[0].length;

        int left = 0;
        int right = r * c - 1;

        while(left <= right){
            int mid = left + (right - left)/2;

            int value = matrix[mid / c][mid % c];

            if(value == target){
                return true;
            }
            else if(value < target)

                left = mid + 1;
            else
                right = mid -1;
        }
        return false;
    }
}