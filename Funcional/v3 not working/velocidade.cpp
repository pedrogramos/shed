
void SendVelocity::vecCallback(const geometry_msgs::Point::ConstPtr& data){

  repulsive.x = data->x;
  repulsive.y = data->y;

}

void SendVelocity::goTo(float xf, float yf,float limiar){

  //soma do vector total repulsivo com o vector atractivo
  vecResX=point.x+xf;
  vecResY=point.y+yf;


  // calculo do módulo
  float d=sqrt(pow((vecResX-odomNew.x),2)+pow((vecResY-odomNew.y),2));
  // calculo da circunferencia de bullseye
  float c=pow((vecResX-odomNew.x),2)+pow((vecResY-odomNew.y),2);
  // calculo do versor para comparacao da direcao da plataforma
  float dxini = (xf-odomNew.x) / d;
  float dyini = (yf-odomNew.y) / d;


  ROS_INFO("Proximo ponto: X= %f e Y= %f.",xf, yf);

  //enquanto o RMP estiver fora do raio da circunferencia c centro no ponto destino
  while (c>pow(limiar,2) && opposite == false){

    c=pow((xf-odomNew.x),2)+pow((yf-odomNew.y),2);
    d=sqrt(pow((vecResX-odomNew.x),2)+pow((vecResY-odomNew.y),2));

    // vetores normalizados -> versor
    float dx=(vecResX-odomNew.x ) / d;
    float dy=(vecResY-odomNew.y) / d;

    // calculo velocidades a enviar
    float vx=cos(odomNew.theta)*dx+sin(odomNew.theta)*dy;
    float vy=cos(odomNew.theta)*dy-sin(odomNew.theta)*dx;
    // projecções * os ganhos
    sendVel(vx*Kl,vy*Kw);

    if (error_received){
      printf("send velocity function next point check \n");
      float res = dxini*dx + dyini*dy; // calculo do produto interno entre os dois versores
      ROS_INFO("resultado do produto interno: %f", res);
      if (res<-0.8) opposite=true; // sentido diferente, quero sair do ciclo
      error_received=false; // reset à flag do serviço recebido
    }
 


    //ROS_INFO("vx= %f vw= %f", vx*Kl, vy*Kw);
    ROS_DEBUG("vx= %f vy= %f d= %f xf= %f yf= %f",vx,vy, d, xf, yf);
    ros::spinOnce();
    if (state==STOPPING) return;
  }//end while

  if (opposite == true){
    fila_pontos.pop();
    ROS_INFO("Fiz pop porque o vector estava c sentido contrario");

  } 


  if(c<pow(limiar,2))
    ROS_INFO("Chegou ao ponto: X= %f e Y= %f.",xf, yf);
    ROS_INFO("Odom: X= %f  Y= %f  Th= %f", odomNew.x, odomNew.y,odomNew.theta);
    fila_pontos.pop();

    //state=GO;
    //infoOdom();
  } 