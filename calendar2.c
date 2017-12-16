#include<stdlib.h>
#include<stdio.h>


int day_counter(int day, int month, int year)
{
	int a,y,m,day_of_week;
	a = (14 - month)/12;
	y = year - a;
	m = month + 12*a -2;
	day_of_week = (( day + y + y/4 - y/100 + y/400 +(31*m)/12)%7);
    return day_of_week;
}


int leap_year(int year)
{
	if((( year%4 == 0) && (year%100 != 0)) || (year%400 == 0))
			return 1;
	return 0;
}


int correct_date(int day, int month,int year)
{
	if (month > 12)
	{
		return 0;
	}
	if (month == 2)
	{ 
		if(day >= 28 + leap_year(year))
			return 0;
	}
	if(((month < 8) && (month%2 == 1)) || ((month > 7) && (month%2 == 0)))
	{
		if(day <= 31)
			return 1;
	}
	if( day <= 30 )
	{
		return 1;
	}
	return 0;
}


void switch_day(int day,int month, int year)
{
		switch(day_counter(day,month,year))
			{
			case 0:
				{
					printf("\n\tSunday\n\n");
					break;
				}
			case 1:
				{
					printf("\n\tMonday\n\n");
					break;
				}
			case 2:
				{
					printf("\n\tTuesday\n\n");
					break;
				}
			case 3:
				{
					printf("\n\tWednesday\n\n");
					break;
				}
			case 4:
				{
					printf("\n\tThursday\n\n");
					break;
				}
		    case 5:
				{
					printf("\n\tFriday\n\n");
					break;
				}
			case 6:
				{
					printf("\n\tSayurday\n\n");
			break;
				}
			default:
				{
				printf("Error");
				break;
				}
			}

}



int main()
{
	printf("\n\tEnter Day Month Year\n\n");
	int day,month,year;
	for(;;)
	{
		printf("\t");
		scanf("%d%d%d",&day,&month,&year);
		if(correct_date(day,month,year))
		{
			switch_day(day,month,year);
		} else printf("\nwrong date\n\n");

	}
	return 0;
}
