#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

int calculateNightShift(int shiftStart, int shiftEnd, int intervalStart, int intervalEnd) {
	int timeWorked = 0;

	if (shiftEnd < shiftStart) {
		shiftEnd += 24 * 60;
	}

	for (int minute = shiftStart; minute < shiftEnd; minute++) {
		int currentMinute = minute % (24 * 60);
		bool crossesMidnight = intervalEnd <= intervalStart;
		bool isNightShift = crossesMidnight
			? (currentMinute >= intervalStart || currentMinute < intervalEnd)
			: (currentMinute >= intervalStart && currentMinute < intervalEnd);

		if (isNightShift) {
			timeWorked++;
		}
	}
	
	return timeWorked;
}

int calculateNightFactor(int timeWorked) {
	float nightFactor = 52.5;
	
	int nightHours = floor(timeWorked / nightFactor);
	printf("Night Hours: %d\n", nightHours);

	float remainingMinutes = fmod(timeWorked, nightFactor);
	printf("Remaining Minutes: %f\n", remainingMinutes);
	
	int convertedMinutes = round(remainingMinutes / nightFactor) * 60;
	printf("Converted Minutes: %d\n", convertedMinutes);

	printf("TOTAL: %d\n", nightHours * 60 + convertedMinutes);
	return (nightHours * 60) + convertedMinutes;
}

int main(void) {
	int shiftStart = 0;
	int shiftEnd = 0;
	int intervalStart = 0;
	int intervalEnd = 0;
	char response[1];
	bool nightFactor;

	printf("Insert the time in minutes ((Hour * 60) + minutes\n\n");

	printf("Work shift start: ");
	scanf("%d", &shiftStart);
	printf("Work shift end: ");
	scanf("%d", &shiftEnd);

	printf("Interval start: ");
	scanf("%d", &intervalStart);
	printf("Interval end: ");
	scanf("%d", &intervalEnd);

	printf("Do you want to calculate with Night Factor? [y/n]\n");
	scanf("%s", response);

	if (strcmp(response, "y") == 0 || strcmp(response, "Y") == 0) {
		nightFactor = true;
	} else if (strcmp(response, "n") == 0 || strcmp(response, "N") == 0) {
		nightFactor = false;
	} else {
		printf("Not a real answer, huh?\n");
		return 1;
	}

	int timeWorked = calculateNightShift(shiftStart, shiftEnd, intervalStart, intervalEnd);
	printf("Total night time wowrked: %d\n", timeWorked);
	if (timeWorked && nightFactor) {
		int timeFactored = calculateNightFactor(timeWorked);
		printf("Total night time (with reduced hour rule applied): %d\n", timeFactored);
	}

	return 0;
}