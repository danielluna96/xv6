#include "types.h"
#include "user.h"

int main(int argc, char *argv[]) {
        int ticks;
        ticks = uptime();

        int totalSeconds = ticks / 60;
        int totalMinutes = ticks / 3600;
        int totalHours = ticks / 216000;

        int minutes = totalMinutes - (totalHours * 60);
        int seconds = totalSeconds - (totalMinutes * 60);

        printf(1, "Uptime %d hours %d minutes %d seconds since boot.\n", totalHours, minutes, seconds);
        exit();
}
