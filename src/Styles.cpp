#include "Styles.h"

#include <string_view>

namespace ChessEngineArena {

    QFont setFont(const char* family, int size, bool bold) {
        QFont font;

        font.setFamily(family);
        font.setPointSize(size);
        font.setBold(bold);

        return font;
    }

    QFont titleFont = setFont("Arial", 40, true);
    
}