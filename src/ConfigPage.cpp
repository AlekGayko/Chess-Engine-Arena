#include "ConfigPage.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFileDialog>
#include <QDebug>
#include <QPushButton>
#include <QSlider>
#include <QDoubleSpinBox>
#include <QCheckBox>

#include "Styles.h"

namespace ChessEngineArena {

    ConfigPage::ConfigPage(std::function<void(Page)> switchPage, QWidget* parent) : QWidget(parent) {
        auto* layout = new QVBoxLayout(this);
        
        auto* title = new QLabel("Tournament Settings");
        title->setFont(titleFont);
        layout->addWidget(title);

        EngineSelector* engSelect1 = new EngineSelector();
        EngineSelector* engSelect2 = new EngineSelector();

        layout->addWidget(engSelect1);
        layout->addWidget(engSelect2);

        auto* tournamentSlider = new QSlider(Qt::Horizontal);
        tournamentSlider->setMinimum(MIN_TOURNAMENT_SIZE);
        tournamentSlider->setMaximum(MAX_TOURNAMENT_SIZE);
        tournamentSlider->setValue(DEFAULT_TOURNAMENT_SIZE);
        tournamentSlider->setAcceptDrops(true);
        auto* sliderLabel = new QLabel("Tournament Size");
        
        layout->addWidget(sliderLabel);
        layout->addWidget(tournamentSlider);

        auto* moveTimeBox = new TimeTextBox(DEFAULT_MOVETIME, MIN_MOVETIME, MAX_MOVETIME);
        auto* moveTimeLabel = new QLabel("Movetime");

        layout->addWidget(moveTimeLabel);
        layout->addWidget(moveTimeBox);

        auto* openingBookBox = new QCheckBox();
        auto* openingBookLabel = new QLabel("Use Opening Book");
        openingBookBox->setChecked(false);

        layout->addWidget(openingBookLabel);
        layout->addWidget(openingBookBox);

        auto* startButton = new QPushButton("Start Tournament");
        layout->addWidget(startButton);

        connect(startButton, &QPushButton::clicked, this, [switchPage]() {
            switchPage(TOURNAMENT);
        });
    }

    EngineSelector::EngineSelector(QWidget* parent) : QWidget(parent) {
        auto *layout = new QHBoxLayout(this);

        auto* addEngBtn = new QPushButton("Add UCI Engine");

        layout->addWidget(addEngBtn);

        connect(addEngBtn, &QPushButton::clicked, this, [this, addEngBtn]() {
            QString path = getEnginePath(this);
            if (path.isEmpty()) {
                return;
            }
            addEngBtn->setText(path);
        });
    }

    QString EngineSelector::getEnginePath(QWidget* parent) { 
        QString filePath = QFileDialog::getOpenFileName(
            parent,
            "Open File",
            "",  
            "All Files (*.*)"
        );

        if (!filePath.isEmpty()) {
            qDebug() << "Selected file:" << filePath;
        } else {
            qDebug() << "No file selected.";
        }

        return filePath;
    }
}