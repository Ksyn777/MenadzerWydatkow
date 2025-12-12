#include "mainwindow.h"
#include "databasemanager.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if (!DatabaseManager::getInstance().connectToDatabase()) {
        qDebug() << "Nie udało się połączyć z bazą danych!";
        return -1; // Zakończ program, jeśli nie ma bazy
    }

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "MenadzerWydatkow_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
