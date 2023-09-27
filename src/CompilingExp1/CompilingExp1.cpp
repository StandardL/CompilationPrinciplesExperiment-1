#include "CompilingExp1.h"


CompilingExp1::CompilingExp1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    this->setWindowIcon(QIcon("./analyzser.ico"));

    QObject::connect(ui.saveres, SIGNAL(triggered()), this, SLOT(SaveFileAction()));
    QObject::connect(ui.openfile, SIGNAL(triggered()), this, SLOT(ReadFileAction()));
    QObject::connect(ui.opensample, SIGNAL(triggered()), this, SLOT(ReadSampleAction()));
    QObject::connect(ui.aboutapp, SIGNAL(triggered()), this, SLOT(AboutAppAction()));
    QObject::connect(ui.btnClear, SIGNAL(clicked()), this, SLOT(ClearBtnClicked()));
    
    // 设置Action的图标
    ui.openfile->setIcon(style()->standardIcon(QStyle::SP_DirOpenIcon));
    ui.saveres->setIcon(style()->standardIcon(QStyle::SP_DialogSaveButton));
    ui.opensample->setIcon(style()->standardIcon(QStyle::SP_FileIcon));
}

CompilingExp1::~CompilingExp1()
{}

QString CompilingExp1::TokenTypeToString(TokenType type)
{
    switch (type) {
    case TokenType::Keyword: return "关键字";
    case TokenType::Var: return "标识符";
    case TokenType::String: return "字符串";
    case TokenType::Char: return "字符";
    case TokenType::Number: return "数字";
    case TokenType::Arithmetic: return "算术运算符";
    case TokenType::Logic: return "逻辑运算符";
    case TokenType::Relation: return "关系运算符";
    case TokenType::Bitwise: return "位运算符";
    case TokenType::Assignment: return "赋值运算符";
    case TokenType::Others: return "杂项运算符";
    case TokenType::Comment: return "注释";
    case TokenType::Division: return "分隔符";
    case TokenType::Special: return "特殊符号";
    // 其他枚举值的处理
    default: return "未知"; // 处理未知的枚举值
    }
}

void CompilingExp1::SaveFileAction()
{
    std::vector<Token> res(alphabet.tokens);
    saveTokensToCSV(res);
    QMessageBox::information(NULL, QString("成功"), QString("保存成功！若文件出现乱码情况，请确保是以UTF-8编码格式打开"));
}

void CompilingExp1::ReadFileAction()
{
    auto filePath = QFileDialog::getOpenFileName(this, tr("选择 .cpp 文件"), QDir::currentPath(), tr("C++ 源文件 (*.cpp);;所有文件 (*.*)"));
    

    if (filePath.isEmpty())
    {
        QMessageBox::warning(NULL, QString("提示"), QString("已取消读取！"));
    }
    else
    {
        std::string stdFilePath = std::string(filePath.toLocal8Bit());
        
        alphabet.ReadFile(stdFilePath);
        std::vector<Token> res(alphabet.tokens);
        ShowInTable(res);
    }
}

void CompilingExp1::ReadSampleAction()
{
    alphabet.ReadFile();
    std::vector<Token> res(alphabet.tokens);
    ShowInTable(res);
    // 清空Token缓冲池
    alphabet.ResetToken();
}


void CompilingExp1::AboutAppAction()
{
    QString detail = "应用版本\t1.0.0-release\nQt版本\t6.2.4构建";
    QMessageBox::information(NULL, QString("关于此应用"), detail);
}

void CompilingExp1::ClearBtnClicked()
{
    alphabet.ResetToken();
    ui.restable->clear();
}

void CompilingExp1::ShowInTable(std::vector<Token>& res)
{
    // 清空table
    ui.restable->clear();

    // 设置行数和列数
    int rowCount = res.size();
    int colCount = 2; // 假设每个 Token 包含两列数据（ID 和 value）

    ui.restable->setRowCount(rowCount);
    ui.restable->setColumnCount(colCount);

    // 禁止编辑
    ui.restable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 遍历 vector 并将数据添加到表格
    for (int row = 0; row < rowCount; ++row) {
        QTableWidgetItem* idItem = new QTableWidgetItem(CompilingExp1::TokenTypeToString(res[row].ID));
        QTableWidgetItem* valueItem = new QTableWidgetItem(QString::fromStdString(res[row].value));

        ui.restable->setItem(row, 0, idItem);     // 第一列显示 ID
        ui.restable->setItem(row, 1, valueItem);  // 第二列显示 value
        valueItem->setToolTip(QString::fromStdString(res[row].value));  // 悬停显示完整的值
    }

    // 设置标题
    ui.restable->setHorizontalHeaderLabels(QStringList() << "类型" << "文本");
    // 自动调整列宽（可选）
    ui.restable->resizeColumnsToContents();
}

void CompilingExp1::saveTokensToCSV(const std::vector<Token>& tokens)
{
    // 创建一个文件保存路径
    auto filePath = QFileDialog::getSaveFileName(nullptr, tr("保存为 CSV 文件"), QDir::currentPath(), tr("CSV 文件 (*.csv)"));

    // 检查用户是否取消了文件保存操作
    if (!filePath.isEmpty()) {
        // 打开文件以写入数据
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);

            // 循环遍历 tokens，并将其写入 CSV 文件
            for (auto& token : tokens) {
                // 使用逗号分隔符将每个 token 写入文件
                //out << QString::fromStdString(token) << ",";
                out << TokenTypeToString(token.ID) << ",";
                out << QString(QString::fromLocal8Bit(token.value.data())) << ",";
                out << "\n";
            }

            // 关闭文件
            file.close();
        }
        else {
            // 处理文件无法打开的情况
        }
    }
}
