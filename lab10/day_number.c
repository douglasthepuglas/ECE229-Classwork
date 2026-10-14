/**************************************************
 * Author:      Bill Westrick
 * Lab:         Lecture 10 example
 * Description: Enter a year day number from 1 to 365
 *              will return the month and day and day of the week.
 * ***********************************************/
 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// what day of the week is Jan 1st
#define JAN1DOW 4
#define YEAR "2026"

const char *GetOrdinalSuffix(int ord);


int main(void)
{
    char *MonthName[] = {"January","February","March","April",
                    "May","June","July","August","September",
                    "October","November","December"};
    int MonthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *WeekDayName[] = {"Sunday","Monday","Tuesday","Wednesday",
                        "Thursday","Friday","Saturday"};
                        
    int day_of_year;
    int day;    // day of month
    int month;  // month number
    int dow;    // day of week number
    
    printf("\nEnter day number from 1 to 365: ");
    scanf("%d", &day_of_year);
    
    // find the month and the day of the month.
    for(day = day_of_year, month = 0; day>MonthDays[month] && month<12; ++month){
        day -= MonthDays[month];
    }
    
    // find day of week
    dow = (JAN1DOW + day_of_year - 1) % 7;
    
    printf("\nThe %d%s day of " YEAR " is %s %s %d%s\n"
            , day_of_year, GetOrdinalSuffix(day_of_year)
            , WeekDayName[dow], MonthName[month]
            , day, GetOrdinalSuffix(day));
    
    
    printf("\n\n");
    return 0;
}

const char *GetOrdinalSuffix(int ord)
{
    static const char *suffix[] = { "st", "nd", "rd", "th" };
    
    if((ord % 10)>=1 && (ord % 10) <=4 
        && !((ord % 100)>=11 && (ord % 100)<=13))
    {
        return suffix[(ord % 10)-1]; 
    }
    return suffix[3]; // otherwise return "th"
}