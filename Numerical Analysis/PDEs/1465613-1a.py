################################
#     Nom: Marc Seguí Coll     #
#         NIU: 1465613         #
#                              #
#    Pràctica 1: l'equació     #
#        del transport         #
################################

# Càrrega de paquets

import sys
import numpy as np
import matplotlib
matplotlib.use('Qt5Agg')

from PyQt5 import QtCore, QtWidgets, QtGui

from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure


# Funcions que defineixen el problema

def u0(x,sel):
    if (sel == 0):
        if(np.abs(x) < 1/2):
            return np.cos(np.pi*x)**2
        else:
            return 0
    if (sel == 1):
        if(np.abs(x) < 1):
            return np.exp(-x**2)
        else:
            return 0
    if (sel == 2):
        return np.cos(2*np.pi*x)*np.exp(-x**2)
    if (sel == 3):
        if((x < 0) and (x > -2)):
            return (x+2)**2
        else:
            if((x >= 0) and (x < 2)):
                return (x-2)**2
            else:
                return 0

def f(x,t,sel):
    if (sel == 0):
        return 0
    if (sel == 1):
        return 1
    if (sel == 2):
        return x
    if (sel == 3):
        return t

def a(x,t,sel):
    if (sel == 0):
        return 1
    if (sel == 1):
        return x**2
    if (sel == 2):
        return np.sin(2*np.pi*t)
    if (sel == 3):
        return -t*x

# Definició de la malla

def init_vars(xini,xfin,numx,tini,tfin,numt):
    variables = {'x0' : xini,
    'xf' : xfin,
    'nx' : numx, # Nombre d'intervals en x
    'dx' : (xfin-xini)/numx,
    'x' : np.linspace(xini,xfin,numx+1), # nx intervals => nx+1 nodes
    't0' : tini,
    'tf' : tfin,
    'nt' : numt, # Nombre d'intervals en t
    'dt' : (tfin-tini)/numt,
    't' : np.linspace(tini,tfin,numt+1),
    'l' : ((tfin-tini)/numt)/((xfin-xini)/numx)}
    return variables

# Esquema de Lax-Friedrichs

def sol(variables,fsel,asel,u0sel):
    u = np.zeros((variables['nx']+1,variables['nt']+1))

    for i in range(0,variables['nx']+1):
        u[i][0] = u0(variables['x'][i],u0sel)

    for j in range(0,variables['nt']):
        for i in range(1,variables['nx']+1):
            if(i == 1):
                u[i][j+1] = variables['dt']*f(variables['x'][i],variables['t'][j],fsel) + \
                            (1-variables['l']*a(variables['x'][i],variables['t'][j],asel))*u[i+1][j]/2
            else:
                if(i == variables['nx']):
                    u[i][j+1] = u[i][j] # Condició de contorn numèrica emprada a teoria
                else:
                    u[i][j+1] = variables['dt']*f(variables['x'][i],variables['t'][j],fsel) + \
                                (1+variables['l']*a(variables['x'][i],variables['t'][j],asel))*u[i-1][j]/2 + \
                                (1-variables['l']*a(variables['x'][i],variables['t'][j],asel))*u[i+1][j]/2

    return u

# Interfície gràfica

class Ui_MainWindow(object):

    # Setup dels widgets (botons, text, opcions,...)

    def setupUi(self, MainWindow):
        self.loopx = 0
        self.loopt = 0
        self.animation = False
        self.variables = init_vars(-1,3,20,0,12/5,24)
        self.u = sol(self.variables,0,0,0)
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(780, 840)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.label_u0 = QtWidgets.QLabel(self.centralwidget)
        self.label_u0.setGeometry(QtCore.QRect(550, 10, 200, 50))
        self.label_u0.setAlignment(QtCore.Qt.AlignCenter)
        self.label_u0.setObjectName("label_u0")
        self.comboBox_u0 = QtWidgets.QComboBox(self.centralwidget)
        self.comboBox_u0.setGeometry(QtCore.QRect(550, 70, 200, 25))
        self.comboBox_u0.setObjectName("comboBox_u0")
        self.comboBox_u0.addItem("")
        self.comboBox_u0.addItem("")
        self.comboBox_u0.addItem("")
        self.comboBox_u0.addItem("")
        self.label_x = QtWidgets.QLabel(self.centralwidget)
        self.label_x.setGeometry(QtCore.QRect(550, 110, 200, 60))
        self.label_x.setAlignment(QtCore.Qt.AlignCenter)
        self.label_x.setObjectName("label_x")
        self.label_x0 = QtWidgets.QLabel(self.centralwidget)
        self.label_x0.setGeometry(QtCore.QRect(550, 190, 30, 20))
        self.label_x0.setObjectName("label_x0")
        self.plainTextEdit_x0 = QtWidgets.QPlainTextEdit(self.centralwidget)
        self.plainTextEdit_x0.setGeometry(QtCore.QRect(580, 185, 50, 30))
        self.plainTextEdit_x0.setObjectName("plainTextEdit_x0")
        self.label_xf = QtWidgets.QLabel(self.centralwidget)
        self.label_xf.setGeometry(QtCore.QRect(650, 190, 30, 20))
        self.label_xf.setObjectName("label_xf")
        self.plainTextEdit_xf = QtWidgets.QPlainTextEdit(self.centralwidget)
        self.plainTextEdit_xf.setGeometry(QtCore.QRect(680, 185, 50, 30))
        self.plainTextEdit_xf.setObjectName("plainTextEdit_xf")
        self.label_nx = QtWidgets.QLabel(self.centralwidget)
        self.label_nx.setGeometry(QtCore.QRect(550, 220, 200, 60))
        self.label_nx.setAlignment(QtCore.Qt.AlignCenter)
        self.label_nx.setObjectName("label_nx")
        self.spinBox_nx = QtWidgets.QSpinBox(self.centralwidget)
        self.spinBox_nx.setGeometry(QtCore.QRect(630, 280, 50, 25))
        self.spinBox_nx.setMaximum(1000)
        self.spinBox_nx.setProperty("value", self.variables['nx'])
        self.spinBox_nx.setObjectName("spinBox_nx")
        self.label_t = QtWidgets.QLabel(self.centralwidget)
        self.label_t.setGeometry(QtCore.QRect(550, 340, 200, 60))
        self.label_t.setAlignment(QtCore.Qt.AlignCenter)
        self.label_t.setObjectName("label_t")
        self.label_t0 = QtWidgets.QLabel(self.centralwidget)
        self.label_t0.setGeometry(QtCore.QRect(550, 420, 30, 20))
        self.label_t0.setObjectName("label_t0")
        self.plainTextEdit_t0 = QtWidgets.QPlainTextEdit(self.centralwidget)
        self.plainTextEdit_t0.setGeometry(QtCore.QRect(580, 415, 50, 30))
        self.plainTextEdit_t0.setObjectName("plainTextEdit_t0")
        self.label_tf = QtWidgets.QLabel(self.centralwidget)
        self.label_tf.setGeometry(QtCore.QRect(650, 420, 30, 20))
        self.label_tf.setObjectName("label_tf")
        self.plainTextEdit_tf = QtWidgets.QPlainTextEdit(self.centralwidget)
        self.plainTextEdit_tf.setGeometry(QtCore.QRect(680, 415, 50, 30))
        self.plainTextEdit_tf.setObjectName("plainTextEdit_tf")
        self.label_nt = QtWidgets.QLabel(self.centralwidget)
        self.label_nt.setGeometry(QtCore.QRect(550, 470, 200, 60))
        self.label_nt.setAlignment(QtCore.Qt.AlignCenter)
        self.label_nt.setObjectName("label_nt")
        self.spinBox_nt = QtWidgets.QSpinBox(self.centralwidget)
        self.spinBox_nt.setGeometry(QtCore.QRect(630, 530, 50, 25))
        self.spinBox_nt.setMaximum(1000)
        self.spinBox_nt.setProperty("value", self.variables['nt'])
        self.spinBox_nt.setObjectName("spinBox_nt")
        self.label_f = QtWidgets.QLabel(self.centralwidget)
        self.label_f.setGeometry(QtCore.QRect(550, 580, 200, 60))
        self.label_f.setAlignment(QtCore.Qt.AlignCenter)
        self.label_f.setObjectName("label_f")
        self.comboBox_f = QtWidgets.QComboBox(self.centralwidget)
        self.comboBox_f.setGeometry(QtCore.QRect(550, 640, 200, 25))
        self.comboBox_f.setObjectName("comboBox_f")
        self.comboBox_f.addItem("")
        self.comboBox_f.addItem("")
        self.comboBox_f.addItem("")
        self.comboBox_f.addItem("")
        self.label_a = QtWidgets.QLabel(self.centralwidget)
        self.label_a.setGeometry(QtCore.QRect(550, 680, 200, 60))
        self.label_a.setAlignment(QtCore.Qt.AlignCenter)
        self.label_a.setObjectName("label_a")
        self.comboBox_a = QtWidgets.QComboBox(self.centralwidget)
        self.comboBox_a.setGeometry(QtCore.QRect(550, 740, 200, 25))
        self.comboBox_a.setObjectName("comboBox_a")
        self.comboBox_a.addItem("")
        self.comboBox_a.addItem("")
        self.comboBox_a.addItem("")
        self.comboBox_a.addItem("")
        self.label_LF = QtWidgets.QLabel(self.centralwidget)
        self.label_LF.setGeometry(QtCore.QRect(100, 100, 340, 20))
        self.label_LF.setObjectName("label_LF")
        self.label_EDP = QtWidgets.QLabel(self.centralwidget)
        self.label_EDP.setGeometry(QtCore.QRect(170, 20, 240, 20))
        self.label_EDP.setObjectName("label_EDP")
        self.label_CI = QtWidgets.QLabel(self.centralwidget)
        self.label_CI.setGeometry(QtCore.QRect(220, 45, 131, 20))
        self.label_CI.setObjectName("label_CI")
        self.label_CC = QtWidgets.QLabel(self.centralwidget)
        self.label_CC.setGeometry(QtCore.QRect(235, 70, 70, 20))
        self.label_CC.setObjectName("label_CC")
        self.widget = QtWidgets.QWidget(self.centralwidget)
        self.widget.setGeometry(QtCore.QRect(20, 130, 500, 580))
        self.widget.setObjectName("widget")
        self.fig = Figure(figsize = (5, 11), dpi = 100)
        self.axex = self.fig.add_subplot(211)
        self.axet = self.fig.add_subplot(212)
        self.axex.yaxis.grid(color='gray')
        self.axex.xaxis.grid(color='gray')
        self.axex.set_axisbelow(True)
        self.axet.yaxis.grid(color='gray')
        self.axet.xaxis.grid(color='gray')
        self.axet.set_axisbelow(True)
        self.fig.subplots_adjust(left = 0.125, right = 0.9, bottom = 0.1, top = 0.9, wspace = 0.2, hspace = 0.6)
        self.canvas = FigureCanvas(self.fig)
        self.xdatax = self.variables['x']
        self.ydatax = [self.u[i][0] for i in range(0,self.variables['nx']+1)]
        self.xdatat = self.variables['t']
        self.ydatat = [self.u[0][j] for j in range(0,self.variables['nt']+1)]
        self.stop_button = QtWidgets.QPushButton(self.centralwidget)
        self.stop_button.setGeometry(QtCore.QRect(40,720,140,20))
        self.stop_button.setText("Aturar animació")
        self.stop_button.clicked.connect(self.stop)
        self.play_button = QtWidgets.QPushButton(self.centralwidget)
        self.play_button.setGeometry(QtCore.QRect(200,720,140,20))
        self.play_button.setText("Reproduir animació")
        self.play_button.clicked.connect(self.play)
        self.reset_button = QtWidgets.QPushButton(self.centralwidget)
        self.reset_button.setGeometry(QtCore.QRect(360,720,140,20))
        self.reset_button.setText("Reset de l'animació")
        self.reset_button.clicked.connect(self.reset)
        self.label_l = QtWidgets.QLabel(self.centralwidget)
        self.label_l.setGeometry(QtCore.QRect(70, 760, 70, 20))
        self.label_l.setObjectName("label_l")
        self.label_dt = QtWidgets.QLabel(self.centralwidget)
        self.label_dt.setGeometry(QtCore.QRect(240, 760, 30, 20))
        self.label_dt.setObjectName("label_dt")
        self.label_dx = QtWidgets.QLabel(self.centralwidget)
        self.label_dx.setGeometry(QtCore.QRect(410, 760, 30, 20))
        self.label_dx.setObjectName("label_dx")
        self.label_l_value = QtWidgets.QLabel(self.centralwidget)
        self.label_l_value.setGeometry(QtCore.QRect(135, 760, 30, 20))
        self.label_l_value.setObjectName("label_l_value")
        self.label_dt_value = QtWidgets.QLabel(self.centralwidget)
        self.label_dt_value.setGeometry(QtCore.QRect(270, 760, 30, 20))
        self.label_dt_value.setObjectName("label_dt_value")
        self.label_dx_value = QtWidgets.QLabel(self.centralwidget)
        self.label_dx_value.setGeometry(QtCore.QRect(440, 760, 30, 20))
        self.label_dx_value.setObjectName("label_dx_value")

        MainWindow.setCentralWidget(self.centralwidget)
        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)
        layout = QtWidgets.QVBoxLayout()
        layout.addWidget(self.canvas)
        self.widget.setLayout(layout)
        self.update_var_sol()
        self.update_plot()
        self.show()
        # Setup a timer to trigger the redraw by calling update_plot.
        self.timer = QtCore.QTimer()
        self.timer.setInterval(500)
        self.timer.timeout.connect(self.update_plot)
        self.timer.timeout.connect(self.update_var_sol)
        self.timer.start()

    def play(self):
        self.animation = True

    def stop(self):
        self.animation = False

    def reset(self):
        self.loopx = 0
        self.loopt = 0

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "Integració numèrica de l\'equació del transport"))
        self.comboBox_u0.setItemText(0, _translate("MainWindow", "cos(pi*x**2) si abs(x) < 0.5 "))
        self.comboBox_u0.setItemText(1, _translate("MainWindow", "exp(-x**2)"))
        self.comboBox_u0.setItemText(2, _translate("MainWindow", "cos(2*pi*x)*exp(-x**2)"))
        self.comboBox_u0.setItemText(3, _translate("MainWindow", "(x+2)**2 si x<0, (x-2)**2 si x >= 0"))
        self.label_u0.setText(_translate("MainWindow", "Selecció de la condició inicial\n"
" (u0(x)):"))
        self.label_x.setText(_translate("MainWindow", "Domini\n"
" en la coordenada x\n"
" (interval [x0,xf])"))
        self.label_x0.setText(_translate("MainWindow", "x0:"))
        self.label_xf.setText(_translate("MainWindow", "xf:"))
        self.plainTextEdit_x0.setPlainText(_translate("MainWindow", str(self.variables['x0'])))
        self.plainTextEdit_xf.setPlainText(_translate("MainWindow", str(self.variables['xf'])))
        self.label_f.setText(_translate("MainWindow", "Selecció de la funció\n"
"  f(x,t):"))
        self.label_a.setText(_translate("MainWindow", "Selecció de la funció\n"
"  a(x,t):"))
        self.comboBox_f.setItemText(0, _translate("MainWindow", "0"))
        self.comboBox_f.setItemText(1, _translate("MainWindow", "1"))
        self.comboBox_f.setItemText(2, _translate("MainWindow", "x"))
        self.comboBox_f.setItemText(3, _translate("MainWindow", "t"))
        self.comboBox_a.setItemText(0, _translate("MainWindow", "1"))
        self.comboBox_a.setItemText(1, _translate("MainWindow", "x**2"))
        self.comboBox_a.setItemText(2, _translate("MainWindow", "sin(2*pi*t)"))
        self.comboBox_a.setItemText(3, _translate("MainWindow", "-t*x"))
        self.label_t.setText(_translate("MainWindow", "Domini\n"
" en la coordenada t\n"
" (interval [t0,tf])"))
        self.label_t0.setText(_translate("MainWindow", "t0:"))
        self.label_tf.setText(_translate("MainWindow", "tf:"))
        self.plainTextEdit_tf.setPlainText(_translate("MainWindow", str(self.variables['tf'])))
        self.plainTextEdit_t0.setPlainText(_translate("MainWindow", str(self.variables['t0'])))
        self.label_nt.setText(_translate("MainWindow", "Nombre de subdivisions\n"
" de [t0,tf] (nt):"))
        self.label_nx.setText(_translate("MainWindow", "Nombre de subdivisions\n"
" de [x0,xf] (nx):"))
        self.label_LF.setText(_translate("MainWindow", "Solució numèrica amb l\'esquema de Lax-Friedrichs"))
        self.label_EDP.setText(_translate("MainWindow", "u_t(x,t) + a(x,t)u_x(x,t) = f(x,t) "))
        self.label_CI.setText(_translate("MainWindow", "u(x,0) = u0(x)"))
        self.label_CC.setText(_translate("MainWindow", "u(0,t) = 0"))
        self.label_l.setText(_translate("MainWindow", "lambda = "))
        self.label_dt.setText(_translate("MainWindow", "dt = "))
        self.label_dx.setText(_translate("MainWindow", "dx = "))
        self.label_l_value.setText(_translate("MainWindow", str(np.around(self.variables['l'],2))))
        self.label_dt_value.setText(_translate("MainWindow", str(np.around(self.variables['dt'],2))))
        self.label_dx_value.setText(_translate("MainWindow", str(np.around(self.variables['dx'],2))))


    def update_plot(self):
        if(self.loopx > self.variables['nt']):
            self.loopx = 0
        if(self.loopt > self.variables['nx']):
            self.loopt = 0
        # Drop off the first y element, append a new one
        self.xdatax = self.variables['x']
        self.xdatat = self.variables['t']
        self.ydatax = [self.u[i][self.loopx] for i in range(0,self.variables['nx']+1)]
        self.ydatat = [self.u[self.loopt][j] for j in range(0,self.variables['nt']+1)]
        self.axex.cla()  # Clear the canvas.
        self.axet.cla()  # Clear the canvas.
        self.axex.set_ylim(np.amin(self.u),np.amax(self.u))
        self.axet.set_ylim(np.amin(self.u),np.amax(self.u))
        self.axex.set_xlabel("Eix 'x'")
        self.axet.set_xlabel("Eix 't'")
        self.axex.set_ylabel("u(x,t)")
        self.axet.set_ylabel("u(x,t)")
        self.axex.yaxis.grid(color='gray')
        self.axex.xaxis.grid(color='gray')
        self.axex.set_axisbelow(True)
        self.axet.yaxis.grid(color='gray')
        self.axet.xaxis.grid(color='gray')
        self.axet.set_axisbelow(True)
        self.axex.set_title("Solució a 't' fixat")
        self.axex.plot(self.xdatax, self.ydatax, color = 'crimson',label = 't = ' + str(np.around(self.variables['t'][self.loopx],3)))
        self.axet.set_title("Solució a 'x' fixada")
        self.axet.plot(self.xdatat, self.ydatat, color = 'darkcyan',label = 'x = ' + str(np.around(self.variables['x'][self.loopt],3)))
        self.axex.legend(loc="upper right")
        self.axet.legend(loc="upper right")
        # Trigger the canvas to update and redraw.
        self.canvas.draw()
        if(self.animation):
            self.loopx += 1
            self.loopt += 1

    def update_var_sol(self):
        _translate = QtCore.QCoreApplication.translate
        self.variables = None
        self.variables = init_vars(float(self.plainTextEdit_x0.toPlainText()),\
                                   float(self.plainTextEdit_xf.toPlainText()),\
                                   int(self.spinBox_nx.value()),\
                                   float(self.plainTextEdit_t0.toPlainText()),\
                                   float(self.plainTextEdit_tf.toPlainText()),\
                                   int(self.spinBox_nt.value()))
        self.u = np.copy(sol(self.variables,\
                         self.comboBox_f.currentIndex(),\
                         self.comboBox_a.currentIndex(),\
                         self.comboBox_u0.currentIndex()))
        self.label_l_value.setText(_translate("MainWindow", str(np.around(self.variables['l'],2))))
        self.label_dt_value.setText(_translate("MainWindow", str(np.around(self.variables['dt'],2))))
        self.label_dx_value.setText(_translate("MainWindow", str(np.around(self.variables['dx'],2))))

class ExampleApp(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self, parent=None):
        super(ExampleApp, self).__init__(parent)
        self.setupUi(self)

app = QtWidgets.QApplication(sys.argv)
w = ExampleApp()
w.show()
app.exec_()
