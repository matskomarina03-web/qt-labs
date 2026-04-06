#ifndef PASSWORDCHECKER_H
#define PASSWORDCHECKER_H
#include <QObject>
#include <QNetworkAccessManager>

class PasswordChecker : public QObject
{
    Q_OBJECT
public:
    PasswordChecker();
    explicit PasswordChecker(QObject *parent = nullptr);
    void check(const QString &password);
signals:
    void checkFinished(bool found, int count);
    void checkError(const QString &message);
private:
    QNetworkAccessManager m_network;

};

#endif // PASSWORDCHECKER_H
