#pragma config(Sensor, S2,     HTIRS,               sensorI2CCustom)
#include "drivers/hitechnic-irseeker-v1.h"
// This is the Code for testing a IR Seeker Version 1
task main () {
  int _dir = 0;
	int dcS1, dcS2, dcS3, dcS4, dcS5 = 0;

  nxtDisplayCenteredTextLine(0, "HiTechnic");
  nxtDisplayCenteredBigTextLine(1, "IR Seekr");
  nxtDisplayCenteredTextLine(3, "Test 1");
  nxtDisplayCenteredTextLine(5, "This is for the");
  nxtDisplayCenteredTextLine(6, "v1 seeker");
  wait1Msec(2000);

  while(true) {
    eraseDisplay();

    // read all of the sensors' values at once,
    // exit the app if an error occurs
    if (! HTIRSreadAllStrength(HTIRS, dcS1, dcS2, dcS3, dcS4, dcS5)) {
      nxtDisplayTextLine(4, "ERROR!!");
      wait1Msec(2000);
      StopAllTasks();
    }

    // read the direction from which the signal is coming,
    // exit the app if an error occurs
    _dir = HTIRSreadDir(HTIRS);
    if (_dir < 0) {
      nxtDisplayTextLine(4, "ERROR!!");
      wait1Msec(2000);
      StopAllTasks();
    }

    // display the info from the sensor
    nxtDisplayTextLine(0,"HT IR Seeker");
    nxtDisplayTextLine(2, "dir: %2d", _dir);
    nxtDisplayTextLine(3, "S1: %3d", dcS1);
    nxtDisplayTextLine(4, "S2: %3d", dcS2);
    nxtDisplayTextLine(5, "S3: %3d", dcS3);
    nxtDisplayTextLine(6, "S4: %3d", dcS4);
    nxtDisplayTextLine(7, "S5: %3d", dcS5);
    wait10Msec(100);
  }
}
