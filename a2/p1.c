#include <stdio.h>
#include <time.h>
static const char *const wday[] = {
"Sunday", "Monday", "Tuesday", "Wednesday",
"Thursday", "Friday", "Saturday", "-unknown-"
};
int main()
{
struct tm time_str;
time_str.tm_year = 2001 - 1900;
time_str.tm_mon = 7 - 1;
time_str.tm_mday = 4;
time_str.tm_hour= 0;
time_str.tm_min= 0;
time_str.tm_sec= 1;
time_str.tm_isdst = -1;
if (mktime(&time_str) == (time_t)(-1))
time_str.tm_wday = 7;
printf("%s\n", wday[time_str.tm_wday]);
time_str.tm_mday= 40;
printf ( "Result 1 :The time is: %s", asctime (&time_str) );
if (mktime(&time_str) == (time_t)(-1))
time_str.tm_wday = 7;
printf("%s\n", wday[time_str.tm_wday]);
printf ( "Result 2 :The time is: %s", asctime (&time_str) );
return 0;
}
