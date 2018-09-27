#!/usr/bin/env python
# -*- coding: utf-8 -*-

import math
import matplotlib.pyplot as plt
import csv

global path1_1, paht1_2, paht1_3
path1_1 = "/home/rmp/bagfiles/3_good_run/vel.txt"
paht1_2 = "/home/rmp/bagfiles/3_good_run/segodom.txt"
paht1_3 = "/home/rmp/bagfiles/with vector/1-turn back/new_odom.txt"


def vel_graph( path):
	#time,field.linear.x,field.linear.y,field.linear.z,field.angular.x,field.angular.y,field.angular.z
	time = []
	linear = []
	angular = []

	with open(path, "r") as csvfile:
		plots = csv.reader(csvfile, delimiter=',')
		for row in plots:
			time.append(float(row[0]))
			linear.append(float(row[1]))
			angular.append(float(row[6]))


	base=time[0]
	size=len(time)
	new_time = []
	new_time.append(0)
	for elem in range(1,size):
		aux=time[elem]- base
		new_time.append(aux/60)

	plt.figure(1)
	plt.plot(new_time,linear, label='Velocidade linear')
	plt.plot(new_time,angular, label='Velocidade angular')
	plt.xlabel('Tempo em minutos')
	plt.ylabel('Velocidades')
	plt.title('Good Run \n Velocidades')
	plt.legend()
	#plt.show()
	#plt.hold(True)


def myodom_graph(path,number):
	#time,field.x,field.y,field.theta
	time = []
	x = []
	y = []
	theta = []

	with open(path, "r") as csvfile:
		plots = csv.reader(csvfile, delimiter=',')
		for row in plots:
			time.append(float(row[0]))
			x.append(float(row[1]))
			y.append(float(row[2]))
			theta.append(float(row[3]))


	base=time[0]
	size=len(time)
	new_time = []
	new_time.append(0)
	for elem in range(1,size):
		aux=time[elem]- base
		new_time.append(aux/60)

	plt.figure(number)
	plt.plot(new_time,x, label="posicao em x")
	plt.plot(new_time,y, label="posicao em y")
	plt.plot(new_time,theta, label="valor de theta")
	plt.xlabel('Tempo (min)')
	plt.ylabel('Posicao')
	plt.title('\n Odometria')
	#plt.legend()
	#plt.show()

	


if __name__ == "__main__":
	'''
	plt.plot([1, 2, 3, 4])
	plt.ylabel('some numbers')
	plt.show()
	'''

	#vel_graph(path1_1)
	myodom_graph("/home/rmp/bagfiles/transform/odom.txt",2)
	myodom_graph("/home/rmp/bagfiles/transform/odom2.txt",3)
	plt.show()

	
