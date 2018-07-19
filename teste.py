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

import Tkinter

window = Tkinter.Tk()
window.title("Manager")
#window.geometry('350x400')
window.configure(background = "white")

places = {}

places ["Main Hall"] = [20,10]
places ["Mobile Robotics Lab"] = [40,20]
places ["Accounting"] = [30,50]


def show_all():
	lb_places.delete(0,"end") # to clear the window when you press the button
	for destiny in places:
		lb_places.insert("end", destiny)

def calculateCourse():
	#lbl_output.delete(0,"end")
	selected = lb_places.get("active") #the active item is the one which is corrently sellected
	result = places[selected]
	#msg = "%f : %f" % selected, result[1]
	msg = result[1]
	lbl_output["text"] = msg

def resume():
	pass

def stopSegway():
	pass


#label
lbl_output = Tkinter.Label(window,text = "Hello! Where do you want to go?")
lbl_output.pack()
#input box
txt_input = Tkinter.Entry(window)
txt_input.pack()
#listbox
lb_places = Tkinter.Listbox(window)
lb_places.pack()

#button
'''
btn_show_all = Tkinter.Button(window, text ="Show all", command = show_all)
btn_show_all.pack()
'''
btn_lets_go = Tkinter.Button(window, text ="Let's go!", command = calculateCourse)
btn_lets_go.pack()

btn_stop = Tkinter.Button(window, text ="Stop Segway", command = stopSegway)
btn_stop.pack()

btn_resume = Tkinter.Button(window, text ="Resume destination", command = resume)
btn_resume.pack()



show_all()
window.mainloop()


