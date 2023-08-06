#include "global.h"


int main(int argc, char *argv[]) {
    while (!window.isClosed()) {
        window.renderScore();
        window.motion();
        for (int i = 0; i < 28; i++) {
            window.collisionobstacle(&obstacles[i], &dino);
        }

        for (int i = 0; i < 23; i++) {
            window.collisionrock(&rocks[i], &dino);
        }

        window.clear();

        for (int i = 0; i < 23; i++) {
            rocks[i].draw(rockx[i], window);
        }

        for (int i = 0; i < 28; i++) {
            obstacles[i].draw(obstaclex[i], window);
        }

        dino.draw(window);

        for (int i = 0; i < 100; i++) {
            coins[i].draw(coinx[i], 610 - coiny[i], window, dino);
        }


        if (window.isDead()) {
            for (int i = 0; i < 41; i++) {
                coins[i].respawn();
            }
        }

        window.render();
        window.pollEvent();
        window.gameEnd();
    }
    return 0;
}

