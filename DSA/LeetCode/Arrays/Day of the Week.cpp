class Solution 
{
    public:
            string dayOfTheWeek(int day, int month, int year) 
            {
                string week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

                static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4}; 
                year -= month < 3;
                int index = (year + year/4 + year/400 - year/100 + t[month-1] + day) % 7;
                return week[index];
            }
};