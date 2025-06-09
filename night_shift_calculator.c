#include<stdio.h>
#include<stdlib.h>

int calculateOverlapping(shiftStart, shiftEnd, intervalStart, intervalEnd) {
	int adjustedSE = 0;
	int adjustedIE = 0;
	int minute = 0;

	minute = shiftStart;

	for (minute = shiftStart; minute < limit; minute++) {
		if (minute < 1440) {
			if (shiftEnd < shiftStart) {
				adjustedSE += 1440;	// Add one day in minutes.
			}
			if (intervalEnd < intervalStart) {
				adjustedIE += 1440; // Add one day in minutes.
			}
			// Calculate overlap
		}
	}
}

int main(void) {
	int shiftStart = 0;
	int shiftEnd = 0;
	int intervalStart = 0;
	int intervalEnd = 0;

	printf("Inicio da Jornada: ");
	scanf("%d", &shiftStart);
	printf("Fim da Jornada: ");
	scanf("%d", &shiftEnd);

	printf("Inicio da Intervalo: ");
	scanf("%d", &intervalStart);
	printf("Fim da Intervalo: ");
	scanf("%d", &intervalEnd);

	timeWorked = calculateOverlapping(shiftStart, shiftEnd, intervalStart, intervalEnd);
}