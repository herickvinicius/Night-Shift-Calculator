#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int calculateNightShift(int shiftStart, int shiftEnd, int intervalStart, int intervalEnd) {
	int timeWorked = 0;

	if (shiftEnd < shiftStart) {
		shiftEnd += 24 * 60;
	}

	for (int minute = shiftStart; minute < shiftEnd; minute++) {
		int actualMinute = minute % (24 * 60);
		bool isNightShift = ((intervalStart <= actualMinute && actualMinute < 1440) ||
			(actualMinute >= 0 && actualMinute < intervalEnd));

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
	bool nightFactor = true;

	printf("Inicio da Jornada: ");
	scanf("%d", &shiftStart);
	printf("Fim da Jornada: ");
	scanf("%d", &shiftEnd);

	printf("Inicio da Intervalo: ");
	scanf("%d", &intervalStart);
	printf("Fim da Intervalo: ");
	scanf("%d", &intervalEnd);

	int timeWorked = calculateNightShift(shiftStart, shiftEnd, intervalStart, intervalEnd);
	printf("Tempo noturno trabalhado: %d\n", timeWorked);
	if (timeWorked && nightFactor) {
		int timeFactored = calculateNightFactor(timeWorked);
		printf("Tempo noturno com fator: %d\n", timeFactored);
	}

	return 0;
}