/*
* MATRIX Creator HAL Application Boilerplate
* Copyright (C) 2017 Dominik Renzel (https://nmaster.gitlab.io)
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <unistd.h>
#include <cmath>
#include <signal.h>
#include <iostream>

#include <matrix_hal/everloop_image.h>
#include <matrix_hal/everloop.h>
#include <matrix_hal/wishbone_bus.h>

namespace hal = matrix_hal;
using namespace std;

hal::WishboneBus bus;
hal::Everloop everloop;
hal::EverloopImage image1d;

void disableEverloop(){

  for (hal::LedValue& led : image1d.leds) {
    led.red = 0;
    led.green = 0;
    led.blue = 0;
    led.white = 0;
  }

  everloop.Write(&image1d);
}

void signalHandler( int signum ) {
  //switch off all LEDs in everloop
  disableEverloop();
  exit(signum);
}

void print_usage(){
  cout << "This is the commandline help for MATRIX Creator HAL application matrix-app.\n";
}

int main (int argc, char **argv) {
  // parse commandline parameters
  int option = 0;

  while ((option = getopt(argc, argv,"h")) != -1) {
      switch (option) {
           case 'h' : print_usage();
                exit(EXIT_SUCCESS);
           default: break;
      }
  }


  // register signal handler
  signal(SIGINT, signalHandler);

  // initialize MATRIX Creator units
  bus.SpiInit();
  everloop.Setup(&bus);

  // begin application
  unsigned counter = 0;

  while (1) {
    for (hal::LedValue& led : image1d.leds) {
      led.red = 0;
      led.green = 0;
      led.blue = static_cast<int>(std::sin(counter / 128.0) * 7.0) + 8;
      led.white = 0;
    }

    everloop.Write(&image1d);
    ++counter;
    usleep(1000);
  }

  return 0;
}
