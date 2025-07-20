#ifndef STYLES_H
#define STYLES_H

#include <QFont>

namespace ChessEngineArena {

    QFont setFont(char* family, int size, bool bold);
    
    extern QFont titleFont;
}

#endif