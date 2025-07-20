#ifndef CONFIGPAGE_H
#define CONFIGPAGE_H

#include <QWidget>

namespace ChessEngineArena {

    class ConfigPage : public QWidget {
        Q_OBJECT
    public:
    explicit ConfigPage(QWidget* parent = nullptr);
    ~ConfigPage() = default;
    private:
    };

    

}

#endif