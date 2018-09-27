void SendVelocity::goTo(float xf, float yf,float limiar){

  outfile.open("vectors.txt");
  outfile2.open("goal.txt");

  float vecResX = repulsive.x + xf;
  float vecResY = repulsive.y + yf;

  float pObstX = vecResX + xf;
  float pObstY = vecResY + yf;
  // calculo do módulo
  float d=sqrt(pow((vecResX-odomNew.x),2)+pow((vecResY-odomNew.y),2));
  // calculo da circunferencia de bullseye
  //float c=pow((vecResX-odomNew.x),2)+pow((vecResY-odomNew.y),2);
  float c=pow((xf-odomNew.x),2)+pow((yf-odomNew.y),2);
  // calculo do versor para comparacao da direcao da plataforma
  float dxini = (xf-odomNew.x) / d;
  float dyini = (yf-odomNew.y) / d;


  ROS_INFO("Proximo ponto: X= %f e Y= %f.",xf, yf);

  //enquanto o RMP estiver fora do raio da circunferencia c centro no ponto destino
  // e ao detectar um marcador não querer voltar para trás
  while (c>pow(limiar,2) && opposite == false){

    vecResX = repulsive.x + xf;
    vecResY = repulsive.y + yf;
    ROS_INFO("New coordinates: X: %f Y: %f", vecResX, vecResY );

    outfile << vecResX << "," << vecResY << std::endl;
    outfile2 << xf << "," << yf << std::endl;

    c=pow((xf-odomNew.x),2)+pow((yf-odomNew.y),2);
    // calculo do d necessita de pontos e nao vectores
    d=sqrt(pow((vecResX-odomNew.x),2)+pow((vecResY-odomNew.y),2));

    // vetores normalizados -> versor
    float dx=(vecResX - odomNew.x ) / d;
    float dy=(vecResY - odomNew.y) / d;

    // calculo velocidades a enviar
    float vx=cos(odomNew.theta)*dx + sin(odomNew.theta)*dy;
    float vy=cos(odomNew.theta)*dy - sin(odomNew.theta)*dx;
    
    // projecções * os ganhos
    sendVel(vx*Kl,vy*Kw);

    // se for detectado um marcador e sinalizado com um servico e com esta variavel
    // usado para comparar se o robo continua com a mesma direccao ou nao
    // problema existente de quando ele detectava um marcador voltava para tras
    if (error_received){ //sai do ciclo e faz pop la fora
      printf("send velocity function next point check \n");
      float res = dxini*((xf-odomNew.x ) / d) + dyini * ((yf-odomNew.y ) / d); // calculo do produto interno entre os dois versores
      ROS_INFO("resultado do produto interno: %f", res);
      if (res<-0.8) opposite=true; // sentido diferente, quero sair do ciclo
      error_received=false; // reset à flag do serviço recebido
    }
 


    //ROS_INFO("vx= %f vw= %f", vx*Kl, vy*Kw);
    ROS_DEBUG("vx= %f vy= %f d= %f xf= %f yf= %f",vx,vy, d, xf, yf);
    ros::spinOnce();
    if (state==STOPPING){
        outfile.close();
        outfile2.close();

       return;
     }

  }//end while



  if (opposite == true){
    fila_pontos.pop();
    ROS_INFO("Fiz pop porque o vector estava c sentido contrario");

  } 


  if(c<pow(limiar,2)){
    ROS_INFO("Chegou ao ponto: X= %f e Y= %f.",xf, yf);
    ROS_INFO("Odom: X= %f  Y= %f  Th= %f", odomNew.x, odomNew.y,odomNew.theta);
    fila_pontos.pop();
  }

    //state=GO;
    //infoOdom();
  
  }// fim da funcao
