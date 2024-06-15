/***********************************************************************
* Copyright (C) 2024, iStar.
*
* File Name:        appconfigsubscriber.h
* Description:      AppConfigSubscriber订阅者，发送当前AppConfig数据结构
* Version:          V1.0.0
* Author:           Feihong Pan
* Date:             2024-2-19
* Modify Record：
***********************************************************************/

#ifndef APPCONFIGSUBSCRIBER_H
#define APPCONFIGSUBSCRIBER_H

#include "MCtrlCommFuncLib_global.h"

#include "Communication/MQTT/isubscriber.h"

class MCTRLCOMMFUNCLIB_EXPORT AppConfigSubscriber : public ISubscriber
{
    Q_OBJECT
public:
    /// <summary>
    /// 析构函数
    /// </summary>
    ~AppConfigSubscriber();

    /// <summary>
    /// 单例
    /// </summary>
    static AppConfigSubscriber *getInstance();

signals:

private:
    /// <summary>
    /// 构造函数
    /// </summary>
    explicit AppConfigSubscriber(QString name, QObject *parent = nullptr);

    /// <summary>
    /// 饿汉式单例模式删除拷贝构造函数和赋值构造函数
    /// </summary>
    AppConfigSubscriber(const AppConfigSubscriber &) = delete;
    AppConfigSubscriber &operator=(const AppConfigSubscriber &) = delete;

    /// <summary>
    /// 收到相应CMD命令发送AppConfig数据
    /// </summary>
    virtual void decoding(const QString &topic, const QByteArray &message) override;

private:
    static AppConfigSubscriber *self;
};

#endif // APPCONFIGSUBSCRIBER_H
