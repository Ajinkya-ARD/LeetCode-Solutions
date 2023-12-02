class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        num3 = sorted(nums1+nums2)
        l=len(num3)
        sum=0
        li=[]
        if l % 2 == 0:
            return (num3[(l//2)-1]+num3[(l//2)])/2
        else:
            return num3[l//2]