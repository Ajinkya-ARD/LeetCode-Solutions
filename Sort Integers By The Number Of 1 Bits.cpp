class Solution
{
public:
    static int count_set_bits(int n)
    {
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            if (n % 2 == 1)
                ans++;
            n >>= 1;
        }

        return ans;
    }

    static bool comp(int &a, int &b)
    {
        if (count_set_bits(a) < count_set_bits(b))
            return true;
        else if (count_set_bits(a) == count_set_bits(b) and a < b)
            return true;
        else
            return false;
    }

    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};