#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep function
// Simulating a temperature register that changes asynchronously
volatile int temperature_register = 25;
// Function simulating a hardware sensor update in a separate execution environment
void update_temperature()
{
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        temperature_register += (rand() % 5 - 2); // Simulate temperature fluctuation
        printf("Sensor updated temperature to: %d\n", temperature_register);
    }
}
int main()
{
    printf("Reading temperature sensor...\n");
    // Simulating a loop that continuously reads the temperature
    for (int i = 0; i < 5; i++)
    {
        printf("Current temperature: %d\n", temperature_register);
        sleep(1);
    }
    return 0;
}