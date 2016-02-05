//
//  toggleBluetooth
//
// CC0 1.0 Universal
//

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <IOBluetooth/IOBluetooth.h>

// private api.
void IOBluetoothPreferenceSetControllerPowerState(bool powered);
bool IOBluetoothPreferenceGetControllerPowerState(void);
bool IOBluetoothPreferencesAvailable(void);

int main(int argc, const char* argv[])
{
  if (!IOBluetoothPreferencesAvailable()) {
    fprintf(stderr, "Error: Bluetooth not available\n");
    return EXIT_FAILURE;
  }

  bool state = IOBluetoothPreferenceGetControllerPowerState();
  if (argc == 2 && strncmp(argv[1], "status", strlen("status")) == 0) {
    printf("Bluetooth is %s\n", state ? "on" : "off");
    return EXIT_SUCCESS;
  }

  IOBluetoothPreferenceSetControllerPowerState(!state);
  usleep(1000000); // wait for state switch
  if (state == IOBluetoothPreferenceGetControllerPowerState()) {
    // nothing changed, failure
    return EXIT_FAILURE;
  }
}
