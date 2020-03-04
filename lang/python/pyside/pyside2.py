#!/usr/bin/python

# Import PySide classes
import sys
from PySide2.QtWidgets import *

# Create a Qt application
app = QApplication(sys.argv)
# Create a Label and show it
label = QLabel("Hello World")
label.show()
# Enter Qt application main loop
app.exec_()
sys.exit()
