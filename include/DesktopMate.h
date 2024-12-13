//
// Created by xfwah on 2024/12/13.
//

#ifndef SMARTYMATE_DESKTOPMATE_H
#define SMARTYMATE_DESKTOPMATE_H

#include <QWidget>
#include <QApplication>
#include <QSystemTrayIcon>

class DesktopMate : public QWidget {
private:
    QSystemTrayIcon trayIcon;

    void addTrayIcon(const QString &iconPath);

    void loadImage(const QString &image);

public:
    explicit DesktopMate();

    ~DesktopMate() override;
};

#endif //SMARTYMATE_DESKTOPMATE_H
