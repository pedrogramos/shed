#!/usr/bin/env python

'''
from Tkinter import *


from random import *        #This library allows us to generate random numbers
							#import library section   2

#
#What not to use??? 
#---------------------------------------------------------------

def one_to_ten():
	ran = uniform(1,10)
	print ran
	
def GoWork():           # def starts a function, or define a function
	sum = 3*5 
	print sum               #Function section   3 
		
#----------------------------------------------------------------


		
							#Code section    4
	
window = Tk()      #i am the parent, button = child

stacy = Button(window, text = 'yoyo', command = one_to_ten)  
#A rose with any other name would be just as sweet


stacy.pack()        #you can name it after your fish (ignored)
window.mainloop()         #you can use your fish's name 

'''

#TO IMPORT A IMAGE OF THE BUILDING PLACES
'''
#This creates the main window of an application
window = tk.Tk()
window.title("Join")
window.geometry("300x300")
window.configure(background='grey')

path = "Aaron.jpg"

#Creates a Tkinter-compatible photo image, which can be used everywhere Tkinter expects an image object.
img = ImageTk.PhotoImage(Image.open(path))

#The Label widget is a standard Tkinter widget used to display a text or image on the screen.
panel = tk.Label(window, image = img)

#The Pack geometry manager packs widgets in rows or columns.
panel.pack(side = "bottom", fill = "both", expand = "yes")

#Start the GUI
window.mainloop()
'''


'''
from tkinter import *

root = Tk()

def task():
    print("hello")
    root.after(2000, task)  # reschedule event in 2 seconds

root.after(2000, task)
root.mainloop()
'''


import serial
import copy
import rospy
from RMPISR.msg import sensors


values = []
array = sensors()

pub = rospy.Publisher('sensorArray', sensors, queue_size=10)

ser = serial.Serial('/dev/ttyACM1', 115200)
print "Trying to connect to arduino..."

if (ser.is_open):
	print "Connection established!"

while ser.is_open:

	s = ser.readline()
	sf = s.decode('utf-8')

	if sf == "hshake\r\n":
		if len(values) == 7:
			array.ir1 = values[0]
			array.s1 = values[1]
			array.ir2 = values[2]
			array.s2 = values[3]
			array.ir3 = values[4]
			array.ir4 = values[5]
			array.s5 = values[6]

			pub.publish(array)

			print values
			print "ir2: ", array.ir2
			print "s2: ", array.s2
			print "ir3: ", array.ir3
			del values[:]
	else:
		print "Receiving values."
		values.append(copy.deepcopy(sf.strip("/r/n")))




