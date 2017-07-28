#include "app/QCpdWindow.h"
#include <QApplication>
#include <QPrinter>
#include <QPainter>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString text{"Hello World!"};
    QPrinter printer;

    auto dialog = std::make_unique<QCpdWindow>(&printer);
    dialog->setWindowTitle("Print Document");

    if (dialog->exec() != QDialog::Accepted)
        return -1;

    QPainter painter;
    painter.begin(&printer);

    QRect rect({100, 100}, QSize{500, 500});
    painter.drawText(rect, Qt::AlignLeft|Qt::AlignTop, text);
    painter.drawEllipse(rect);

    painter.end();

    return 0;
}
