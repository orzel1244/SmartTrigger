#include "triggerbot.h"

TriggerBot::TriggerBot(QObject *parent) : QObject(parent){
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(loop()));
    timer->start(0);
}

void TriggerBot::loop(){
    if(enabled){
        // here the hack goes..
    }
}

void TriggerBot::setEnabled(bool value){
    enabled = value;
}

void TriggerBot::setDelay(int value){
    delay = value;
}

void TriggerBot::setChance(int value){
    chance = value;
}
