FILE *pf;


int cargarReg(t_reg *preg);


{
    t_reg reg;

    while(cargarReg(&reg))
        fwrite(&reg,sizeof(t_reg),1,pf);





}



fwrite(&reg,);





