//
// Created by Carsten Walther.
//

#include "Configuration.h"
#include "main.h"

unsigned long version = 1624816104;

const Configuration defaults PROGMEM = {
    // foreground color
    0,
    0,
    0,

    // background color
    0,
    0,
    0,

    // settings
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    false,
    0,
    NTP_HOST_NAME,

    // network
    SERVER_HOST,

    // access
    USE_BASIC_AUTH,
    AUTH_USERNAME,
    AUTH_PASSWORD
};
