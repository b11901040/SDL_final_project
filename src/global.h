#ifndef SDL_GLOBAL_H
#define SDL_GLOBAL_H
#pragma once
#include "window.h"
#include "dinosaur.h"
#include "coin.h"
#include "rock.h"
#include "obstacle.h"

Window window;
dinosaur dino(window);
rock rocks[] = {rock(window), rock(window), rock(window), rock(window), rock(window), rock(window), rock(window),
                  rock(window), rock(window), rock(window), rock(window), rock(window), rock(window), rock(window),
                  rock(window), rock(window), rock(window), rock(window), rock(window), rock(window), rock(window),
                  rock(window), rock(window)};;
int rockx[] = {650, 960, 1040, 5850, 2110, 3600, 3680, 4100, 5000, 5080, 5160, 5240, 5320, -6010, 5930, 6500, 6590,
8200, 9000, 9080, 9160, 9240, 9320};

obstacle obstacles[] = {obstacle(window), obstacle(window), obstacle(window), obstacle(window), obstacle(window),
                        obstacle(window), obstacle(window), obstacle(window), obstacle(window), obstacle(window),
                        obstacle(window), obstacle(window), obstacle(window), obstacle(window), obstacle(window),
                        obstacle(window), obstacle(window), obstacle(window), obstacle(window), obstacle(window),
                        obstacle(window), obstacle(window), obstacle(window), obstacle(window), obstacle(window),
                        obstacle(window), obstacle(window), obstacle(window), obstacle(window)};

int obstaclex[] = {300, 2410, 4000, 4200, 1500, 1530, 1800, 1830, 2800, 2850, 3300, 3330, 4600, 5600, 4800, 6200, 6900,
                   7200, 7570, 7600, 8000, 8500, 8530, 8750, 8800, 9600, 9630, 9660};

coin coins[] = {coin(window), coin(window), coin(window), coin(window), coin(window), coin(window), coin(window),
                coin(window), coin(window), coin(window), coin(window), coin(window), coin(window), coin(window),
                coin(window), coin(window), coin(window), coin(window), coin(window), coin(window), coin(window),
                coin(window), coin(window), coin(window), coin(window), coin(window), coin(window), coin(window),
                coin(window), coin(window), coin(window), coin(window), coin(window), coin(window), coin(window),
                coin(window), coin(window), coin(window), coin(window), coin(window), coin(window), coin(window),
                coin(window), coin(window), coin(window), coin(window), coin(window), coin(window), coin(window),
                coin(window), coin(window), coin(window), coin(window), coin(window),
                coin(window), coin(window), coin(window), coin(window), coin(window), coin(window), coin(window),
                coin(window), coin(window), coin(window), coin(window), coin(window), coin(window), coin(window),
                coin(window), coin(window), coin(window), coin(window), coin(window), coin(window),
                coin(window), coin(window), coin(window), coin(window), coin(window), coin(window),
                coin(window), coin(window), coin(window), coin(window),
                coin(window), coin(window), coin(window), coin(window), coin(window),
                coin(window), coin(window), coin(window), coin(window), coin(window), coin(window), coin(window), coin(window), coin(window), coin(window), coin(window)};

int coinx[] = {400, 420, 440, 460, 480, 1100, 1130, 1160, 1190, 1220, 1515, 1485, 1455, 1545, 1575, 2000, 2030, 1910,
               1940, 1970, 2410, 2380, 2350, 2440, 2470, 2500, 2530, 2560, 2590, 2620, 3110, 3140, 2960, 2990, 3020,
               3050, 3080, 3600, 3570, 3540, 3630, 3900, 3930, 3960, 4145, 4600, 4570, 4540, 4630, 4660, 4850, 4880,
               4910, 5050, 5100,
               5150, 5200, 5250, 5300, 5350, 5400, 5880, 5910, 5940, 6440, 6470, 6500, 6530, 6900, 6870, 6840, 6930,
               6960, 7200, 7170, 7140, 7230, 7260,
               7910, 7940, 7970, 8030, 8060, 8090, 8775, 8745, 8715, 8805, 8835, 9210, 9180, 9150, 9090, 9120, 9940, 9910, 9880, 9790,
               9820, 9850};
int coiny[] = {0, 0, 0, 0, 0, 90, 150, 200, 150, 90, 150, 100, 30, 100, 30, 0, 0, 0, 0, 0,
               150, 100, 30, 100, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 150, 110,
               60, 110, 0, 0, 0, 90, 150, 100, 30, 100, 30, 0, 0, 0, 90, 90, 90, 90, 90, 90, 90, 90,
               90, 90, 90, 90, 150, 200, 150, 150, 100, 30, 100, 30, 150, 100, 30, 100, 30, 0, 0, 0, 0, 0, 0,
               150, 100, 30, 100, 30, 90, 90, 90, 90, 90, 0,0,0,0,0,0};


#endif //SDL_GLOBAL_H
