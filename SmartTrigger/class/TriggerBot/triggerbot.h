#ifndef TRIGGERBOT_H
#define TRIGGERBOT_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QTimer>
#include <class/Memory/memory.h>
#include <class/Offsets/offsets.h>

class TriggerBot : public QObject {
    Q_OBJECT
public:
    explicit TriggerBot(QObject *parent = nullptr);

private slots:
    void loop();

public slots:
    void setEnabled(bool value);
    void setDelay(int value);
    void setChance(int value);
private:
    bool enabled = false;
    int delay;
    int chance;
};

#endif // TRIGGERBOT_H
