 -- mais recente com versores --

        size=len(self.traj_points)


        for i in range(1,size):

            d = math.sqrt(math.pow((self.traj_points[i].x-self.traj_points[i-1].x),2) + math.pow((self.traj_points[i].y-self.traj_points[i-1].y),2))
            versorX = (self.traj_points[i].x - self.traj_points[i-1].x) / d
            versorY = (self.traj_points[i].y - self.traj_points[i-1].y) / d

            #quantas vezes cabe a minha scale na distancia entre os pontos
            #vezes que tenho de incrementar o ciclo
            k = int(math.ceil(d/scale))

            #valor do incremento por iteracao
            inc= d/k

            print "d: %f versorX: %f versorY: %f k: %f inc: %f" % (d,versorX,versorY,k,inc)


            for j in xrange(k):
                self.aux_traj.x = self.aux_traj.x + (inc*versorX)
                self.aux_traj.y = self.aux_traj.y + (inc/versorY)
                self.new_traj.append(copy.deepcopy(self.aux_traj))
            

        print "lista final: \n" , self.new_traj


---------------------------------------------
size=len(self.traj_points)


        for i in range(1,size):

            d = math.sqrt(math.pow((self.traj_points[i].x-self.traj_points[i-1].x),2) + math.pow((self.traj_points[i].y-self.traj_points[i-1].y),2))
            versorX = (self.traj_points[i].x - self.traj_points[i-1].x) / d
            versorY = (self.traj_points[i].y - self.traj_points[i-1].y) / d

            #print versorX, versorY, d

            # inicializacao da nova trajectoria
            self.aux_traj.x = self.traj_points[i-1].x
            self.aux_traj.y = self.traj_points[i-1].y

            if (versorX>0):
                #calculo de quantas vezes cabe a meu espacamento entre pontos na distancia total por excesso
                bitolaX=int(math.ceil((versorX*d)/scale))
                #fazer os segmentos com a distancia entre eles toda igual
                new_scaleX = (versorX*d)/bitolaX

                #incremento da distancia ate chegar ao ponto
                for j in xrange(bitolaX):
                    self.aux_traj.x = self.aux_traj.x + new_scaleX
                    self.new_traj.append(copy.deepcopy(self.aux_traj))

            if (versorY>0):
                bitolaY=int(math.ceil((versorY*d)/scale))
                new_scaleY = (versorY*d)/bitolaY

                for k in xrange(bitolaY):
                        self.aux_traj.y = self.aux_traj.y + new_scaleY
                        self.new_traj.append(copy.deepcopy(self.aux_traj))
            

        print "lista final: \n" , self.new_traj










--------------------------------------

                if (versorX>0):
                    #calculo de quantas vezes cabe a meu espacamento entre pontos na distancia total por excesso
                    bitolaX=int(math.ceil((versorX*d)/scale))
                    #fazer os segmentos com a distancia entre eles toda igual
                    new_scaleX = (versorX*d)/bitolaX

                    #incremento da distancia ate chegar ao ponto
                    for j in xrange(bitolaX):
                        self.aux_traj.x = self.aux_traj.x + new_scaleX
                        self.new_traj.append(copy.deepcopy(self.aux_traj))

                if (versorY>0):
                    bitolaY=int(math.ceil((versorY*d)/scale))
                    new_scaleY = (versorY*d)/bitolaY

                    for k in xrange(bitolaY):
                            self.aux_traj.y = self.aux_traj.y + new_scaleY
                            self.new_traj.append(copy.deepcopy(self.aux_traj))
                

            print "lista final: \n" , self.new_traj



#------------------------------------------------------------------


def trajDivider(self,scale=1):
            size=len(self.traj_points)
            i=1

            # inicializacao da nova trajectoria
            self.aux_traj.x = self.traj_points[0].x
            self.aux_traj.y = self.traj_points[0].y


            for i in range(1,size):

                d = math.sqrt(math.pow((self.traj_points[i].x-self.traj_points[i-1].x),2) + math.pow((self.traj_points[i].y-self.traj_points[i-1].y),2))
                versorX = (self.traj_points[i].x - self.traj_points[i-1].x) / d
                versorY = (self.traj_points[i].y - self.traj_points[i-1].y) / d

                print versorX, versorY, d

                #verificar se a coordenada aumenta de facto nesta direcao ou nao
                if (versorX != 0):
                    #calculo de quantas vezes cabe a meu espacamento entre pontos na distancia total por excesso
                    bitolaX=int(math.ceil((versorX*d)/scale))
                    #fazer os segmentos com a distancia entre eles toda igual
                    new_scaleX = (versorX*d)/bitolaX
                    print bitolaX, new_scaleX

                if (versorY != 0):
                    bitolaY=int(math.ceil((versorY*d)/scale))
                    new_scaleY = (versorY*d)/bitolaY
                    print bitolaY, new_scaleY

                if (abs(bitolaY)>=abs(bitolaX)):
                    bigger = abs(bitolaY)
                else: 
                    bigger = abs(bitolaX)

                print bitolaX, bitolaY, bigger

                for j in xrange(bigger):

                    if(j <= abs(bitolaX)) and (versorX != 0):
                        self.aux_traj.x = self.aux_traj.x + new_scaleX
                        self.new_traj.append(copy.deepcopy(self.aux_traj))

                    if(j <= abs(bitolaY)) and (versorY != 0):
                        self.aux_traj.y = self.aux_traj.y + new_scaleY
                        self.new_traj.append(copy.deepcopy(self.aux_traj))

            print "lista final: \n" , self.new_traj


#---------------------------------------------------------------------------------

d = math.sqrt(math.pow((self.traj_points[i].x-self.traj_points[i-1].x),2) + math.pow((self.traj_points[i].y-self.traj_points[i-1].y),2))
                #quantidade que tenho de avançar em X
                versorX = (self.traj_points[i].x - self.traj_points[i-1].x) / d
                #quantidade que tenho de avançar em Y
                versorY = (self.traj_points[i].y - self.traj_points[i-1].y) / d

                print "versorX: %f  versorY: %f  d: %f" % (versorX, versorY, d)

                #verificar se a coordenada aumenta de facto nesta direcao ou nao
                if (versorX != 0):
                    #calculo de quantas vezes cabe a meu espacamento entre pontos na distancia total por excesso
                    bitolaX=int(math.ceil((versorX*d)/scale))
                    #fazer os segmentos com a distancia entre eles toda igual
                    new_scaleX = abs(versorX*d)/bitolaX
                    print "bitolaX: %f  incrementX= %f" % (bitolaX, new_scaleX)

                if (versorY != 0):
                    bitolaY=int(math.ceil((versorY*d)/scale))
                    new_scaleY = abs(versorY*d)/bitolaY
                    print "bitolaY: %f  incrementY= %f" % (bitolaY, new_scaleY)

                if (abs(bitolaY)>=abs(bitolaX)):
                    bigger = abs(bitolaY)
                else: 
                    bigger = abs(bitolaX)

                print "bitolaX: %f  bitolaY= %f  bigger: %f" % (bitolaX, bitolaY, bigger)

                for j in xrange(bigger):

                    if(j <= abs(bitolaX)) and (versorX != 0):
                        self.aux_traj.x = self.aux_traj.x + new_scaleX
                        #self.new_traj.append(copy.deepcopy(self.aux_traj))

                    if(j <= abs(bitolaY)) and (versorY != 0):
                        self.aux_traj.y = self.aux_traj.y + new_scaleY
                        #self.new_traj.append(copy.deepcopy(self.aux_traj))

                    self.new_traj.append(copy.deepcopy(self.aux_traj))

            print "lista final: \n" , self.new_traj



-------------------------------------------------------------------------

usando a equação da recta


        def trajDivider(self,scale=1):
            size=len(self.traj_points)
            i=1

            # inicializacao da nova trajectoria
            self.aux_traj.x = self.traj_points[0].x
            self.aux_traj.y = self.traj_points[0].y


            for i in range(1,size):

                sizex=self.traj_points[i].x-self.traj_points[i-1].x
                sizey=self.traj_points[i].y-self.traj_points[i-1].y
                d = math.sqrt(math.pow(sizex,2) + math.pow(sizey,2))
                m = sizey/sizex
                b = self.traj_points[i].y - m*self.traj_points[i].x

                print "sizex: %f sizey: %f m: %f  b: %f" % (sizex, sizey, m,b)

                if (abs(sizey) >= abs(sizex)):
                    bitola = int(math.ceil(sizey/scale))
                    inc = sizey/bitola
                    print "estou em y bitola: %f  inc %f" % (bitola, inc)

                    for j in xrange(bitola):
                        self.aux_traj.y = self.aux_traj.y + bitola  
                        self.aux_traj.x = ((self.aux_traj.y)-b)/m
                        self.new_traj.append(copy.deepcopy(self.aux_traj))

                else: 

                    bitola = int(math.ceil(sizex))
                    inc = bitola/scale
                    print "estou em X bitola: %f  inc %f" % (bitola, inc)

                    for j in xrange(bitola):
                        self.aux_traj.x = self.aux_traj.x + bitola  
                        self.aux_traj.y = (m*self.aux_traj.x)+b
                        self.new_traj.append(copy.deepcopy(self.aux_traj))

                print "lista final: \n" , self.new_traj

