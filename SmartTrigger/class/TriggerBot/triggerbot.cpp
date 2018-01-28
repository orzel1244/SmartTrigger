#include "triggerbot.h"

TriggerBot::TriggerBot(QObject *parent) : QObject(parent){
    srand (time(NULL));
    QTimer *timerD = new QTimer(this);
    connect(timerD, SIGNAL(timeout()), this, SLOT(loop()));
    timerD->start(0);
}

void TriggerBot::loop(){
    if(enabled){
        // here the hack goes..
        DWORD clientDll = memory.getModule("client.dll");
        DWORD playerBase = memory.read(clientDll+offsets.playerBase);
        DWORD playerTeam = memory.read(playerBase+offsets.team);

        DWORD crosshairValue = memory.read(playerBase+offsets.crosshair);
        if(crosshairValue != 0){
            DWORD ent = memory.read(clientDll+offsets.entBase+(crosshairValue-1)*0x10);
            DWORD entTeam = memory.read(ent+offsets.team);
            if(entTeam != playerTeam){

                // [idea]:
                // chance = 25%

                // example 1
                // random number = 21 [from 1 to 100]
                // result: 21 < 25% then shoot

                // example 2
                // random number = 29
                // result 29 > 25% then DONT SHOOT


                int random = rand() % 100 + 1;
                if(random > chance){
                    // not shooting
                    Sleep(130);
                } else {
                    Sleep(delay);  //Delay before shooting
                    fire();
                }

            }
        }
    }
}

void TriggerBot::fire(){
    mouse_event(MOUSEEVENTF_LEFTDOWN,NULL,NULL,NULL,NULL);
    //Sleep(10); //Delay between shots
    mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL);
    //Sleep(10); //Delay after shooting
}

void TriggerBot::setEnabled(bool value){
    enabled = value;
    if(value){
        memory.assignProcess();
    }
}

void TriggerBot::setDelay(int value){
    delay = value;
}

void TriggerBot::setChance(int value){
    chance = value;
}
