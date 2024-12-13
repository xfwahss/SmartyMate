//
// Created by xfwah on 2024/12/13.
//
#include <QMenu>
#include "DesktopMate.h"
#include <iostream>
#include <QLabel>
#include <QVBoxLayout>

DesktopMate::DesktopMate() : trayIcon() {
    // 置于顶层，不显示边框
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::SubWindow);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->addTrayIcon("../../resources/logo.png");
    this->loadImage("../../resources/shime1.png");
    this->resize(10, 10);
    this->show();
};

DesktopMate::~DesktopMate() = default;

void DesktopMate::addTrayIcon(const QString &iconPath) {
    QIcon trayIconIcon(iconPath);
    this->trayIcon.setIcon(trayIconIcon);
    QMenu *menu = new QMenu(this);
    QAction *exitAction = new QAction(QWidget::tr("Exit"), menu);
    QObject::connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);
    menu->addAction(exitAction);
    this->trayIcon.setContextMenu(menu);
    this->trayIcon.show();
}

void DesktopMate::loadImage(const QString &image) {
    QLabel *label = new QLabel(this);
    QPixmap pixmap(image);
    if (!pixmap.isNull()) {
        label->setPixmap(pixmap);
    } else {
        label->setText("Failed to load image");
    }
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    this->setLayout(layout);
}
