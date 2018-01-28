#ifndef TRIGGERBOT_H
#define TRIGGERBOT_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QTimer>
#include <class/Memory/memory.h>
#include <class/Offsets/offsets.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class TriggerBot : public QObject {
    Q_OBJECT
public:
    explicit TriggerBot(QObject *parent = nullptr);

private slots:
    void loop();
    void fire();
public slots:
    void setEnabled(bool value);
    void setDelay(int value);
    void setChance(int value);
private:
    Memory memory;
    Offsets offsets;
    bool enabled = false;
    int delay;
    int chance;
};

#endif // TRIGGERBOT_H
