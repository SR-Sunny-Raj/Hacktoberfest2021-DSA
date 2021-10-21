import sys
from PyQt5 import QtWidgets as qtw
from PyQt5 import QtCore as qtc
from PyQt5 import QtGui as qtg



class binary(qtg.QValidator):

    def validate(self,string,index):
        print(string,index)
        
        if all([i=="1" or i == "0" for i in str(string)]):
            state = qtg.QValidator.Acceptable
        elif string == "":
            state = qtg.QValidator.Intermediate
        else: 
            state = qtg.QValidator.Invalid
        return (state,string,index)

class MainWindow(qtw.QWidget):

    def __init__(self,*args,**kwargs):
        super().__init__()
        self.setLayout(qtw.QGridLayout())
        

        label1 = qtw.QLabel("Enter a Binary Number")
        self.convert = qtw.QPushButton("Convert")
        self.answer = qtw.QLabel()
        self.line = qtw.QLineEdit()
        self.line.setValidator(binary()) 
        self.answer.setAlignment(qtc.Qt.AlignHCenter) 
        self.layout().addWidget(label1,0,1)
        self.layout().addWidget(self.line,0,2)
        self.layout().addWidget(self.answer,1,0,1,4)
        self.layout().addWidget(self.convert,0,4) 

        self.convert.clicked.connect(self.converter)
        
        self.show()

    def converter(self):
        decimal = self.line.text()
        binary = int(str(decimal),2)
        self.answer.setText(str(binary))


if __name__ == "__main__":
    app = qtw.QApplication(sys.argv)
    win = MainWindow()
    sys.exit(app.exec_())
