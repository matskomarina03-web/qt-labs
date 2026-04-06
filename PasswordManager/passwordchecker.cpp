#include "passwordchecker.h"
#include <QCryptographicHash>
#include <QNetworkRequest>
#include <QNetworkReply>
PasswordChecker::PasswordChecker(QObject *parent)
    : QObject(parent)
{
}

void PasswordChecker::check(const QString &password)
{
    QByteArray sha1 = QCryptographicHash::hash(
                          password.toUtf8(),
                          QCryptographicHash::Sha1
                          ).toHex().toUpper();

    QByteArray prefix = sha1.left(5);
    QByteArray suffix = sha1.mid(5);

    QUrl url("https://api.pwnedpasswords.com/range/" + prefix);
    QNetworkRequest request(url);

    request.setRawHeader("Add-Padding", "true");
    request.setTransferTimeout(10000);

    QNetworkReply *reply = m_network.get(request);

    connect(reply, &QNetworkReply::finished, this, [=]()
            {
                if (reply->error() != QNetworkReply::NoError)
                {
                    emit checkError(reply->errorString());
                    reply->deleteLater();
                    return;
                }

                QByteArray data = reply->readAll();
                QList<QByteArray> lines = data.split('\n');

                bool found = false;
                int count = 0;

                for (const QByteArray &line : lines)
                {
                    QList<QByteArray> parts = line.split(':');
                    if (parts.size() == 2)
                    {
                        if (parts[0].trimmed() == suffix)
                        {
                            found = true;
                            count = parts[1].toInt();
                            break;
                        }
                    }
                }

                emit checkFinished(found, count);

                reply->deleteLater();
            });
}
