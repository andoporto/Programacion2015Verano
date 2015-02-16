






fread(&reg,sizeof(t_reg),1,pf);

while (!feof(pf))
{
    //procesar
    mostrarReg(&reg);
    fread(&reg,sizeof(t_reg),1,pf);  //&reg le pasa la direccion de la estructura
}

fclose(pf);
