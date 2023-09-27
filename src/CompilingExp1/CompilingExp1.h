#pragma once

#include <QtWidgets/QMainWindow>
#include <qmessagebox.h>
#include <qprogressbar.h>
#include <qfiledialog.h>
#include "ui_CompilingExp1.h"
#include "Alphabet.h"

class CompilingExp1 : public QMainWindow
{
    Q_OBJECT

public:
    CompilingExp1(QWidget *parent = nullptr);
    ~CompilingExp1();

private slots:
    void SaveFileAction();
    void ReadFileAction();
    void ReadSampleAction();
    void AboutAppAction();
    void ClearBtnClicked();

private:
    Ui::CompilingExp1Class ui;
    Alphabet alphabet;

    QString TokenTypeToString(TokenType type);
    void ShowInTable(std::vector<Token>&);
    void saveTokensToCSV(const std::vector<Token>& tokens);
};
