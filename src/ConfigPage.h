#ifndef CONFIGPAGE_H
#define CONFIGPAGE_H

#include <QWidget>
#include <QString>
#include <QDoubleSpinBox>

#include "Types.h"

namespace ChessEngineArena {

    class ConfigPage : public QWidget {
        Q_OBJECT
    public:
        explicit ConfigPage(std::function<void(Page)> switchPage, QWidget* parent = nullptr);
        ~ConfigPage() = default;
    private:
        
    };

    class EngineSelector : public QWidget {
        Q_OBJECT
    public:
        explicit EngineSelector(QWidget* parent = nullptr);
        ~EngineSelector() = default;
    private:
        QString getEnginePath(QWidget* parent = nullptr);
    };

    class TimeTextBox : public QDoubleSpinBox {
        Q_OBJECT
    public:
        TimeTextBox(double value, double min, double max, QWidget* parent = nullptr) : QDoubleSpinBox(parent) {
            setValue(value);
            setMinimum(min);
            setMaximum(max);
        }
    private:
        QString textFromValue(double value) const override {
            return QString::number(value) + " sec";
        }

        double valueFromText(const QString& text) const override {
            QString num = text;
            num = num.replace(" sec", "");
            return num.toDouble();
        }
    };

}

#endif