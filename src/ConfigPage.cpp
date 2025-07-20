#include "ConfigPage.h"

#include <QVBoxLayout>
#include <QLabel>

#include "Styles.h"

namespace ChessEngineArena {

    ConfigPage::ConfigPage(QWidget* parent) : QWidget(parent) {
        auto *layout = new QVBoxLayout(this);
        
        QLabel* title = new QLabel("");
        title->setFont(titleFont);
        layout->addWidget(title);
    }

}