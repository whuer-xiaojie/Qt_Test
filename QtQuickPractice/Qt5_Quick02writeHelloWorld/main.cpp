#include <QGuiApplication>
#include <QQmlApplicationEngine>



int main(int argc, char *argv[])

{

    QGuiApplication app(argc, argv);



    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/new/prefix1/main.qml")));



    return app.exec();

}
