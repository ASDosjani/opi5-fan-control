#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <wiringPi.h>

// Define
#define FAN_PIN 3
#define THRESHOLD_TEMP 40
#define PNP 1
#define CPU_TEMP_FILE "/sys/class/thermal/thermal_zone0/temp"

int main() {
    int temp;
    bool on = false;

    if (wiringPiSetup() == -1) {
        printf("wiringPiSetup failed\n");
        return 1;
    }

    pinMode(FAN_PIN, OUTPUT);
    printf("Threshold temperature: %d°C\n", THRESHOLD_TEMP);

    while(1) {
        FILE* temp_file = fopen(CPU_TEMP_FILE, "r");

        if (temp_file == NULL) {
            printf("Failed to read CPU temperature file\n");
            return 1;
        }

        fscanf(temp_file, "%d", &temp);
        fclose(temp_file);

        temp /= 1000;

        if (temp < THRESHOLD_TEMP) {
            on = false;
	    digitalWrite(FAN_PIN, PNP);
        } else {
            on = true;
            digitalWrite(FAN_PIN, !PNP);
        }

        printf("CPU: %d°C | %s%\n", temp, on?"ON":"OFF");

        sleep(5);
    }

    return 0;
}
