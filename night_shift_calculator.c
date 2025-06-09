#include <stdio.h>
#include <stdlib.h>

int calculateNightShift(int shiftStart, int shiftEnd, int intervalStart, int intervalEnd) {
	// int adjustedSE = shiftEnd + 1440;
	int adjustedIE = intervalEnd + 1440;
	int minute = 0;
	int limit = 0;
	int timeWorked = 0;

	// if (shiftEnd < shiftStart) {
	// 	adjustedSE += 1440;	// Add one day in minutes.
	// }
	// if (intervalEnd < intervalStart) {
	// 	adjustedIE += 1440; // Add one day in minutes.
	// }

	if (shiftStart <= intervalStart) {
		minute = intervalStart;
	} else {
		minute = shiftStart;
	}
	limit = adjustedIE;


	for (int i = shiftStart; i < limit; i++) {
		if (minute < 1440) {
			if(minute <= adjustedIE) {
				timeWorked++;
			}
		} else {
			minute = minute % 1440;
			if(minute <= intervalEnd) {
				timeWorked++;
			}
		}
		minute++;
	}
	return timeWorked;
}

int main(void) {
	int shiftStart = 0;
	int shiftEnd = 0;
	int intervalStart = 0;
	int intervalEnd = 0;
	// int timeWorked = 0;

	printf("Inicio da Jornada: ");
	scanf("%d", &shiftStart);
	printf("Fim da Jornada: ");
	scanf("%d", &shiftEnd);

	printf("Inicio da Intervalo: ");
	scanf("%d", &intervalStart);
	printf("Fim da Intervalo: ");
	scanf("%d", &intervalEnd);

	int timeWorked = calculateNightShift(shiftStart, shiftEnd, intervalStart, intervalEnd);

	printf('Tempo noturno trabalhado: %d\n', timeWorked);

	return 0;
}