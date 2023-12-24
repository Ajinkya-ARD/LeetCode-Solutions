class Solution:
    def totalMoney(self, n: int) -> int:
        # Calculate full weeks and remaining days
        full_weeks, remaining_days = divmod(n, 7)

        # Calculate total money after complete weeks
        # The sum of an arithmetic progression for a week is 28 (1+2+...+7),
        # then it increases by 7 for each subsequent week.
        week_start_sum = 28  # The sum for the first week
        week_end_sum = week_start_sum + 7 * (full_weeks - 1)  # Calculate the sum for the last week
        total_full_weeks_money = (week_start_sum + week_end_sum) * full_weeks // 2

        # Calculate total money for the remaining days
        # The money each day starts at full_weeks + 1 and increases by 1 each day
        remaining_start_money = full_weeks + 1  # Starting money for the first remaining day
        remaining_end_money = remaining_start_money + remaining_days - 1 # Money for the last remaining day
        total_remaining_days_money = (remaining_start_money + remaining_end_money) * remaining_days // 2

        # Sum the money from full weeks and remaining days
        total_money = total_full_weeks_money + total_remaining_days_money
        return total_money