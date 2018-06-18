#!/usr/bin/env python
import numpy as np
from sympy import *


def matrixTest():
	'''
	example using numpy as array
	'''

	#criacao 'matrix'
	a = np.array([[1, 0, 2],[0, -1, 4],[0, 0, 1]])
	#criacao 'vector'
	b = np.array([[1],[2], [3]])
	#multiplicacao com array sem ser elemento a elemento
	c = a.dot(b);
	#calculo da inversa
	inverse = np.linalg.inv(a)
	#multipliccacao pela inversa
	cc = inverse.dot(b)

	print c, c[1]

	#-----------------------------------------------------#
	'''
	example using nampy as matrix
	'''
	displayx=800
	displayy=480

	#cricao matrix
	wTm= np.matrix([[1,0,displayx],
			[0,-1,displayy],
			[0,0,1]])
	#criacao vector
	vector = np.matrix([[20],[20],[0]])
	#calculo da inversa
	inv= wTm.I


	print "x", inv[1,0:1], "y", inv[2,0:1]
	#final= inv(1:2)*vector[1]

	#print "\ninv2", inv, "\nnew point", final


def symbolicTest():
	x = Symbol('x')
	y = Symbol('y')
	newX = Symbol('newX')
	newY = Symbol('newY')
	dX = Symbol('dX')
	dY = Symbol('dY')

	#cricao matrix
	wTm= np.matrix([[1,0,dX],
			[0,-1,dY],
			[0,0,1]])

	#criacao vector
	vector = np.matrix([[x],[y],[0]])
	
	#calculo da inversa
	inv= wTm.I
	new=inv*vector

	print "\n" , new



if __name__ == "__main__":

	symbolicTest()