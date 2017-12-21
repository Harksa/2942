#include "spacerock.h"
#include "enemy.h"

SpaceRock::SpaceRock(int pos_x) : Enemy(pos_x){

    int random = rand() % 10;

    if(random <= 7) {
        life = 5;
        scoreGiven = 20;
        moveSpeed = 0.8f;
        setPixmap(QPixmap(":/pictures/Images/meteorSmall.png"));
    }
    else {
        life = 10;
        scoreGiven = 30;
        moveSpeed = 0.4f;
        setPixmap(QPixmap(":/pictures/Images/meteorBig.png"));
    }
    spawn(pos_x);
}

void SpaceRock::move(){
    setPos(x(), y() + moveSpeed);
    DestroyWhenContactWithPlayer();
    destroyWhenOutsideMap();
}
